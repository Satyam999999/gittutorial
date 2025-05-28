import socket

# Client script to receive a PDF file from the server via UDP

def receive_file(output_filename, host, port):
    """
    Receives a PDF file from the server via UDP.
    :param output_filename: Name of the output file where data will be stored.
    :param host: The IP address of the client.
    :param port: The port number to listen on.
    """
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    client_socket.bind((host, port))
    print(f"Client listening on {host}:{port}")

    with open(output_filename, "wb") as file:
        while True:
            data, _ = client_socket.recvfrom(1024)  # Receive chunks of 1024 bytes
            if not data:
                break
            file.write(data)

    print("File received successfully!")
    client_socket.close()

if __name__ == "__main__":
    output_filename = "received.pdf"  # File to save received data
    host = "0.0.0.0"  # Bind to all available interfaces
    port = 5001  # Port number to receive data
    
    receive_file(output_filename, host, port)