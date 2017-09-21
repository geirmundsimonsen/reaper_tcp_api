#pragma once

#include "stdafx.h"

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "Ws2_32.lib")

int connect() {

	WSADATA wsaData;

	int iResult;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
		return 1;
	}



	///// CREATING THE SOCKET ////////////

	/*
	Declare an addrinfo object that contains a sockaddr structure and
	initialize these values. For this application, the Internet address
	family is unspecified so that either an IPv6 or IPv4 address can be
	returned. The application requests the socket type to be a stream
	socket for the TCP protocol.
	*/
	struct addrinfo *result = NULL,
		*ptr = NULL,
		hints;

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	/*
	Call the getaddrinfo function requesting the IP address for the
	server name passed on the command line. The TCP port on the server
	that the client will connect to is defined by DEFAULT_PORT as 27015
	in this sample. The getaddrinfo function returns its value as an integer
	that is checked for errors.
	*/
#define DEFAULT_PORT "9501"

	// Resolve the server address and port
	iResult = getaddrinfo("127.0.0.1", DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed: %d\n", iResult);
		WSACleanup();
		return 1;
	}


	/*
	Create a SOCKET object called ConnectSocket.
	*/

	SOCKET ConnectSocket = INVALID_SOCKET;


	/*
	Call the socket function and return its value to the ConnectSocket
	variable. For this application, use the first IP address returned by
	the call to getaddrinfo that matched the address family, socket type,
	and protocol specified in the hints parameter. In this example, a TCP
	stream socket was specified with a socket type of SOCK_STREAM and a
	protocol of IPPROTO_TCP. The address family was left unspecified
	(AF_UNSPEC), so the returned IP address could be either an IPv6 or
	IPv4 address for the server.

	If the client application wants to connect using only IPv6 or IPv4,
	then the address family needs to be set to AF_INET6 for IPv6 or
	AF_INET for IPv4 in the hints parameter.
	*/
	// Attempt to connect to the first address returned by
	// the call to getaddrinfo
	ptr = result;

	// Create a SOCKET for connecting to server
	ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
		ptr->ai_protocol);

	/*
	Check for errors to ensure that the socket is a valid socket.
	*/
	if (ConnectSocket == INVALID_SOCKET) {
		printf("Error at socket(): %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}



	//////////// CONNECTING TO A A SOCKET //////////

	/*
	Call the connect function, passing the created socket and the sockaddr
	structure as parameters. Check for general errors.
	*/

	// Connect to server.
	iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		closesocket(ConnectSocket);
		ConnectSocket = INVALID_SOCKET;
	}

	// Should really try the next address returned by getaddrinfo
	// if the connect call failed
	// But for this simple example we just free the resources
	// returned by getaddrinfo and print an error message

	freeaddrinfo(result);

	if (ConnectSocket == INVALID_SOCKET) {
		printf("Unable to connect to server!\n");
		WSACleanup();
		return 1;
	}

	/*
	The getaddrinfo function is used to determine the values in the
	sockaddr structure. In this example, the first IP address returned
	by the getaddrinfo function is used to specify the sockaddr structure
	passed to the connect. If the connect call fails to the first IP
	address, then try the next addrinfo structure in the linked list
	returned from the getaddrinfo function.

	The information specified in the sockaddr structure includes:

	the IP address of the server that the client will try to connect to.
	the port number on the server that the client will connect to. This
	port was specified as port 27015 when the client called the
	getaddrinfo function.
	*/



	////////// SENDING / RECEVING DATA //////////

	/*
	The following code demonstrates the send and recv functions used by
	the client once a connection is established.
	*/

	//char *sendbuf = "this is a test";
	//double d = 72813.713481358;
	// Send an initial buffer
	//iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	//iResult = send(ConnectSocket, (char*) &d, 8, 0);
	/*if (iResult == SOCKET_ERROR) {
	printf("send failed: %d\n", WSAGetLastError());
	closesocket(ConnectSocket);
	WSACleanup();
	return 1;
	}

	printf("Bytes Sent: %ld\n", iResult);*/

	// shutdown the connection for sending since no more data will be sent
	// the client can still use the ConnectSocket for receiving data
	/*iResult = shutdown(ConnectSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
	printf("shutdown failed: %d\n", WSAGetLastError());
	closesocket(ConnectSocket);
	WSACleanup();
	return 1;
	}*/

	
	// Receive data until the server closes the connection
	while (true) {
		iResult = recv(ConnectSocket, sendrecvbuf, tcpbuflength, 0); // you can loop this call, iresult > 0
		if (iResult > 0) {

		} else if (iResult == 0) {

			break;
		} else {

			break;
		}

		int func_to_call = *(int*)&sendrecvbuf[0];

		int bytes_to_send = functions[func_to_call]();


		if (bytes_to_send != 0) {
			char bytes_to_read[4];
			memcpy(bytes_to_read, &bytes_to_send, 4);
			iResult = send(ConnectSocket, bytes_to_read, 4, 0);

			if (iResult == SOCKET_ERROR) {

				closesocket(ConnectSocket);
				WSACleanup();
				return 1;
			}

			iResult = send(ConnectSocket, sendrecvbuf, bytes_to_send, 0);

			if (iResult == SOCKET_ERROR) {

				closesocket(ConnectSocket);
				WSACleanup();
				return 1;
			}
		}
	}

	/*
	The send and recv functions both return an integer value of the
	number of bytes sent or received, respectively, or an error. Each
	function also takes the same parameters: the active socket, a char
	buffer, the number of bytes to send or receive, and any flags to use.
	*/

	//////// DISCONNECTING THE CLIENT ////////////

	/*
	Once the client is completed sending and receiving data, the client
	disconnects from the server and shutdowns the socket.

	When the client is done sending data to the server, the shutdown
	function can be called specifying SD_SEND to shutdown the sending
	side of the socket. This allows the server to release some of the
	resources for this socket. The client application can still receive
	data on the socket.
	*/
	// shutdown the send half of the connection since no more data will be sent
	iResult = shutdown(ConnectSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}


	/*
	When the client application is done receiving data, the closesocket
	function is called to close the socket.

	When the client application is completed using the Windows Sockets
	DLL, the WSACleanup function is called to release resources.
	*/
	// cleanup
	closesocket(ConnectSocket);
	WSACleanup();


	return 0;
}