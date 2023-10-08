# Minitalk

Minitalk is a simple client-server communication program that uses signals for message transmission. This readme provides an overview of the Minitalk project, its components, and how to use it.

## Introduction

Minitalk is a client-server application where the server listens for signals from the client, interprets them as binary data, and reconstructs the transmitted message. The client sends messages to the server by sending signals.

## Server

### Signal Handling

The server program (server.c) initializes signal handling using the sigaction function. It listens for two custom signals, SIG_USR1 and SIG_USR2, which represent binary bits. When a signal is received, the handle_sigusr function updates a global variable g_rec_bit with the received bit value (0 or 1) and stores the PID of the client program. The server then waits for the next signal using pause().

### Main Function

The main function initializes signal handling, displaying its own PID, and enters an infinite loop to listen for signals. When a signal is received, it calls the get_msg function to process the received message.

## Client

### Signal Handling

The client program (client.c) also initializes signal handling using the sigaction function. It listens for two custom signals, SIG_USR1 and SIG_USR2, which represent acknowledgments for individual bits and entire messages, respectively. When a signal is received, the handle_sigusr function updates a global variable g_ack with the acknowledgment status.

### Main Function

The main function retrieves the server's PID from the command line arguments, initializes signal handling, and sends the message specified in the command line arguments to the server using the send_msg function.

## Usage

To use Minitalk, follow these steps:

1. Compile the server and client programs:

```shell
$> make
```

2. Start the server in one terminal:

```shell
$> ./server
```

3. In another terminal, send a message from the client to the server:


```shell
$> ./client [SERVER_PID] "Your message here"
```

Replace [SERVER_PID] with the PID of the server process.

The server will receive and display the message.

Feel free to modify and extend the Minitalk project as needed for your use case.