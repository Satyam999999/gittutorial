import socket
import time

# Constants
SERVER_IP = "0.0.0.0"
SERVER_PORT = 5001
FILE_PATH = "np.pdf"
CHUNK_SIZE = 1024
TIMEOUT = 2
SEQ_NUM = 0  # Start with sequence number 0

def send_file(conn):
    global SEQ_NUM

    with open(FILE_PATH, "rb") as file:
        while True:
            chunk = file.read(CHUNK_SIZE)
            if not chunk:
                break  # End of file

            # Append sequence number as the last byte
            data_packet = chunk + bytes([SEQ_NUM])

            conn.sendall(data_packet)  # Send data
            print(f"Sent chunk {SEQ_NUM}, waiting for ACK...")

            try:
                conn.settimeout(TIMEOUT)
                ack = conn.recv(1024).decode()  # Receive ACK

                if ack == f"ACK{SEQ_NUM}":
                    print(f"Received {ack}, sending next packet...")
                    SEQ_NUM = 1 - SEQ_NUM  # Toggle sequence number
                else:
                    print(f"Received incorrect ACK {ack}, resending chunk...")
                    time.sleep(1)  # Simulate retransmission delay

            except socket.timeout:
                print("Timeout! Resending chunk...")
                time.sleep(1)  # Simulate retransmission delay

def start_server():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_sock:
        server_sock.bind((SERVER_IP, SERVER_PORT))
        server_sock.listen(1)
        print(f"Server started at {SERVER_IP}:{SERVER_PORT}, waiting for connection...")

        conn, addr = server_sock.accept()
        print(f"Connected by {addr}")

        send_file(conn)  # Start file transmission
        conn.close()

if __name__ == "__main__":
    start_server()
