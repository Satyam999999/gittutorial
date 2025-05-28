import socket

# Client Configuration
SERVER_IP = '172.27.75.208'  # Change to server's actual IP
PORT = 5001
OUTPUT_FILE = 'received1.pdf'  # File to save the received data

def receive_file():
    """Connect to the server and receive the PDF file."""
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
        client_socket.connect((SERVER_IP, PORT))  # Connect to server
        print(f"Connected to server at {SERVER_IP}:{PORT}")

        with open(OUTPUT_FILE, 'wb') as file:
            while chunk := client_socket.recv(1024):  # Receive 1024-byte chunks
                file.write(chunk)  # Write data to file
        print("File received successfully.")

if __name__ == "__main__":
    receive_file()