import socket

# Client script to receive a PDF file from the server via UDP using rdt2.1 protocol

def receive_file(output_filename, host, port):
    """
    Receives a PDF file from the server via UDP using rdt2.1 protocol.
    Implements acknowledgments and sequence numbers to ensure reliability.
    :param output_filename: Name of the output file where data will be stored.
    :param host: The IP address of the client.
    :param port: The port number to listen on.
    """
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    client_socket.bind((host, port))
    print(f"Client listening on {host}:{port}")

    with open(output_filename, "wb") as file:
        expected_seq_num = 0  # Expected sequence number
        while True:
            packet, server_address = client_socket.recvfrom(1025)  # Receive packet
            seq_num = packet[0]  # Extract sequence number
            data = packet[1:]  # Extract data
            
            if seq_num == expected_seq_num:
                file.write(data)  # Write data to file
                client_socket.sendto(bytes([expected_seq_num]), server_address)  # Send ACK
                expected_seq_num = 1 - expected_seq_num  # Toggle expected sequence number
            else:
                client_socket.sendto(bytes([1 - expected_seq_num]), server_address)  # Resend last ACK

    print("File received successfully!")
    client_socket.close()

if __name__ == "__main__":
    output_filename = "daa3.pdf"  # File to save received data
    host = "0.0.0.0"  # Bind to all available interfaces
    port = 5001  # Port number to receive data
    
    receive_file(output_filename, host, port)