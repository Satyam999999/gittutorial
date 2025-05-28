import socket
import hashlib

# Server details
SERVER_IP = "192.168.59.24"  # Replace with actual server IP
SERVER_PORT = 12345
BUFFER_SIZE = 1024
OUTPUT_FILE = "received.pdf"

# Create UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

def calculate_checksum(data):
    """Compute MD5 checksum for data integrity verification."""
    return hashlib.md5(data).hexdigest().encode()

# Request the file from the server
client_socket.sendto(b"REQUEST_FILE", (SERVER_IP, SERVER_PORT))

with open(OUTPUT_FILE, "wb") as file:
    expected_seq_num = 0  # Sequence number expected

    while True:
        packet, server_address = client_socket.recvfrom(BUFFER_SIZE + 64)
        
        if packet == b"EOF":
            print("File transfer completed.")
            break

        # Extract checksum, sequence number, and data
        received_checksum, seq_num, chunk = packet.split(b"|", 2)
        seq_num = int(seq_num.decode())

        # Validate checksum and sequence number
        if received_checksum == calculate_checksum(chunk) and seq_num == expected_seq_num:
            file.write(chunk)
            client_socket.sendto(f"ACK{seq_num}".encode(), server_address)
            print(f"Received valid packet {seq_num}, sending ACK{seq_num}.")
            expected_seq_num = 1 - expected_seq_num  # Toggle sequence
        else:
            client_socket.sendto(b"NACK", server_address)
            print("Corrupted packet detected! Sending NACK.")

client_socket.close()