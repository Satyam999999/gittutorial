import socket

# Server details
SERVER_IP = "192.168.137.52"  # Change this to the server's IP address
SERVER_PORT = 5001
BUFFER_SIZE = 1024
OUTPUT_FILE = "received_file.pdf"  # The file to save received data

def receive_file():
    """Function to receive a file from the server over UDP"""
    
    # Create a UDP socket
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    
    try:
        # Send a request to the server
        client_socket.sendto(b"REQUEST_FILE", (SERVER_IP, SERVER_PORT))
        print("Request sent to the server.")

        # Open a file to write the received data
        with open(OUTPUT_FILE, "wb") as file:
            while True:
                # Receive data from the server
                data, _ = client_socket.recvfrom(BUFFER_SIZE)
                
                if data == b"EOF":  # End-of-file signal
                    print("End of file reached.")
                    break
                
                # Write the received data to the file
                file.write(data)
                print(f"Received {len(data)} bytes.")
        
        print(f"File successfully received and saved as {OUTPUT_FILE}.")
    
    except Exception as e:
        print(f"Error: {e}")
    
    finally:
        client_socket.close()
        print("Socket closed.")

if __name__ == "__main__":
    receive_file()
