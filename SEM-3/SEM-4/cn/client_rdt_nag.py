import socket
import hashlib
import struct
import time

# Client Configuration
SERVER_IP = '172.27.75.208'  # Change to the actual server IP
PORT = 5001  
OUTPUT_FILE = 'nosql.pdf'  

PACKET_SIZE = 1041  # 1 (seq) + 16 (checksum) + 1024 (data)

def compute_checksum(data):
    """Calculate MD5 checksum of the data."""
    return hashlib.md5(data).digest()

def receive_file():
    """TCP Client using rdt3.0 for reliable file reception."""
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
        client_socket.connect((SERVER_IP, PORT))
        print(f"Connected to server at {SERVER_IP}:{PORT}")

        with open(OUTPUT_FILE, 'wb') as file:
            expected_seq = 0  

            while True:
                packet = client_socket.recv(PACKET_SIZE)
                if not packet:
                    break  

                if len(packet) != PACKET_SIZE:
                    print(f"Received incomplete packet: {len(packet)} bytes (expected {PACKET_SIZE})")
                    continue  

                seq_num, received_checksum, data = struct.unpack('!B16s1024s', packet)

                # Compute checksum *before* stripping null bytes
                computed_checksum = compute_checksum(data)

                print(f"Received SEQ={seq_num}, Expected SEQ={expected_seq}, "
                      f"Computed Checksum={computed_checksum.hex()}, Received Checksum={received_checksum.hex()}")

                if computed_checksum == received_checksum and seq_num == expected_seq:
                    file.write(data.rstrip(b'\x00'))  # Strip padding only when writing
                    print(f"Packet SEQ={seq_num} accepted. Sending ACK.")

                    # Send ACK for received sequence number
                    ack_packet = struct.pack('!B', expected_seq)
                    client_socket.sendall(ack_packet)

                    # Flip expected sequence number
                    expected_seq = 1 - expected_seq
                else:
                    print(f"Corrupt or out-of-order packet (SEQ={seq_num}), sending duplicate ACK.")
                    
                    # Send ACK for last correctly received sequence number
                    ack_packet = struct.pack('!B', 1 - expected_seq)
                    client_socket.sendall(ack_packet)

                # Small delay to prevent flooding duplicate ACKs
                time.sleep(0.01)

        print("File received successfully.")

if __name__ == "__main__":
    receive_file()
