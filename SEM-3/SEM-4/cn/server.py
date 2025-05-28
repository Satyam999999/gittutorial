import socket

# Define server address and port
HOST = '0.0.0.0'  # Listen on all network interfaces
PORT = 5001  # Port to listen on

# Name of the PDF file to send
FILENAME = "DAA.pdf"

def send_file(conn):
    """Send the PDF file to the connected client"""
    try:
        with open(FILENAME, "rb") as file:
            while chunk := file.read(4096):  # Read file in chunks of 4KB
                conn.sendall(chunk)  # Send chunk
        print("File sent successfully.")
    except FileNotFoundError:
        print("Error: File not found.")
    finally:
        conn.close()

def start_server():
    """Start the server and wait for client connection"""
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server:
        server.bind((HOST, PORT))
        server.listen(1)  # Listen for one client at a time
        print(f"Server started at {HOST}:{PORT}. Waiting for connection...")

        conn, addr = server.accept()  # Accept incoming connection
        print(f"Connected by {addr}")

        send_file(conn)  # Send the file

if __name__ == "__main__":
    start_server()
 