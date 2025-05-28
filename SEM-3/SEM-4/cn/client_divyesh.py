import socket

def receive_file(filename, s):
    """Receive a file from the server and save it locally."""
    # Receive the file details
    received = s.recv(BUFFER_SIZE).decode()
    filename, filesize = received.split(SEPARATOR)
    filesize = int(filesize)

    # Send acknowledgment
    s.send(b"ACK")

    # Receive the file in chunks
    with open(filename, "wb") as f:
        while True:
            bytes_read = s.recv(BUFFER_SIZE)
            if not bytes_read:
                break
            f.write(bytes_read)

    print(f"File {filename} received successfully.")

def main():
    SERVER_HOST = "192.168.137.25"  # Replace with the server's IP address
    SERVER_PORT = 5001
    BUFFER_SIZE = 4096
    SEPARATOR = "<SEPARATOR>"

    # Create a TCP socket
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((SERVER_HOST, SERVER_PORT))
    print(f"[*] Connected to {SERVER_HOST}:{SERVER_PORT}")

    # Request the file
    requested_file = "example.pdf"  # Replace with the desired file name
    s.send(requested_file.encode())

    # Receive the file
    receive_file(requested_file, s)

    s.close()

if __name__ == "__main__":
    main()