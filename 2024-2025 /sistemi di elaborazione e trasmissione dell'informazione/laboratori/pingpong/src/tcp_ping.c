/*
 * tcp_ping.c: esempio di implementazione del processo "ping" con
 *             socket di tipo STREAM.
 *
 * versione 24.1
 *
 * Programma sviluppato a supporto del laboratorio di
 * Sistemi di Elaborazione e Trasmissione del corso di laurea
 * in Informatica classe L-31 presso l'Universita` degli Studi di
 * Genova, anno accademico 2024/2025.
 *
 * Copyright (C) 2013-2014 by Giovanni Chiola <chiolag@acm.org>
 * Copyright (C) 2015-2016 by Giovanni Lagorio <giovanni.lagorio@unige.it>
 * Copyright (C) 2017-2024 by Giovanni Chiola <chiolag@acm.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include "pingpong.h"

/*
 * This function sends and wait for a reply on a socket.
 * int msg_size: message length
 * int msg_no: message sequence number (written into the message)
 * char message[msg_size]: buffer to send
 * int tcp_socket: socket file descriptor
 */
double do_ping(size_t msg_size, int msg_no, char message[msg_size], int tcp_socket)
{
	char rec_buffer[msg_size];
	ssize_t recv_bytes, sent_bytes;
	size_t offset;
	struct timespec send_time, recv_time;

/*** write msg_no at the beginning of the message buffer ***/
	/*** TO BE DONE START ***/
  	sprintf(message, "%d", msg_no);
	/*** TO BE DONE END ***/

/*** Store the current time in send_time ***/
	/*** TO BE DONE START ***/
	clock_gettime(CLOCK_TYPE, &send_time);		// usiamo clock type dichiarato sul file h, se cambiamo il tipo di orologio almeno non dobbiamo cambiare questa riga
	/*** TO BE DONE END ***/

/*** Send the message through the socket ***/
	/*** TO BE DONE START ***/
	sent_bytes = send(tcp_socket, message, msg_size, 0);	// 
	if (sent_bytes == -1) 
		fail_errno("Sending message through the socket FAILED");
	/*** TO BE DONE END ***/

    /*** Receive answer through the socket (blocking) ***/
	for (offset = 0; (offset + (recv_bytes = recv(tcp_socket, rec_buffer + offset, sent_bytes - offset, MSG_WAITALL))) < msg_size; offset += recv_bytes) {
		debug(" ... received %zd bytes back\n", recv_bytes);
		if (recv_bytes < 0)
			fail_errno("Error receiving data");
	}

/*** Store the current time in recv_time ***/
	/*** TO BE DONE START ***/
	clock_gettime(CLOCK_TYPE, &recv_time);
	/*** TO BE DONE END ***/

	printf("tcp_ping received %zd bytes back\n", recv_bytes);
	return timespec_delta2milliseconds(&recv_time, &send_time);
}

int main(int argc, char **argv)
{
	struct addrinfo gai_hints, *server_addrinfo;
	int msgsz, norep;
	int gai_rv;
	char ipstr[INET_ADDRSTRLEN];
	struct sockaddr_in *ipv4;
	int tcp_socket;
	char request[MAX_REQ], answer[MAX_ANSW];
	ssize_t nr;

	if (argc < 4)
		fail("Incorrect parameters provided. Use: tcp_ping PONG_ADDR PONG_PORT SIZE [NO_REP]\n");
	for (nr = 4, norep = REPEATS; nr < argc; nr++)
		if (*argv[nr] >= '1' && *argv[nr] <= '9')
			sscanf(argv[nr], "%d", &norep);
	if (norep < MINREPEATS)
		norep = MINREPEATS;
	else if (norep > MAXREPEATS)
		norep = MAXREPEATS;

    /*** Initialize hints in order to specify socket options ***/
	memset(&gai_hints, 0, sizeof gai_hints);

	/*** TO BE DONE START ***/
	gai_hints.ai_flags = 0;
	gai_hints.ai_family = AF_INET; // iPv4
	gai_hints.ai_socktype = SOCK_STREAM; // tcp
	gai_hints.ai_protocol = IPPROTO_TCP;
	/*** TO BE DONE END ***/

/*** call getaddrinfo() in order to get Pong Server address in binary form ***/
	/*** TO BE DONE START ***/
	gai_rv = getaddrinfo(argv[1], argv[2], &gai_hints, &server_addrinfo);
	if (gai_rv != 0) {
		fail_errno("\nerrore getaddrinfo()\n");	
	}
	/*** TO BE DONE END ***/

    /*** Print address of the Pong server before trying to connect ***/
	ipv4 = (struct sockaddr_in *)server_addrinfo -> ai_addr;
	printf("TCP Ping trying to connect to server %s (%s) on port %s\n", argv[1], inet_ntop(AF_INET, &ipv4->sin_addr, ipstr, INET_ADDRSTRLEN), argv[2]);

/*** create a new TCP socket and connect it with the server ***/
	/*** TO BE DONE START ***/
	tcp_socket = socket(server_addrinfo -> ai_family, server_addrinfo -> ai_socktype, server_addrinfo -> ai_protocol);

	if (tcp_socket == -1) 
		fail_errno("Could not create TCP socket");

	if (connect(tcp_socket, server_addrinfo -> ai_addr, server_addrinfo -> ai_addrlen) == -1) 
		fail_errno("Could not connect to the server");
	/*** TO BE DONE END ***/

	freeaddrinfo(server_addrinfo);
	if (sscanf(argv[3], "%d", &msgsz) != 1)
		fail("Incorrect format of size parameter");
	if (msgsz < MINSIZE)
		msgsz = MINSIZE;
	else if (msgsz > MAXTCPSIZE)
		msgsz = MAXTCPSIZE;
	printf(" ... connected to Pong server: asking for %d repetitions of %d bytes TCP messages\n", norep, msgsz);
	sprintf(request, "TCP %d %d\n", msgsz, norep);

/*** Write the request on socket ***/
	/*** TO BE DONE START ***/
	if (write(tcp_socket, request, strlen(request)) == -1) 
    	fail_errno("Could not send request to server");
	/*** TO BE DONE END ***/

	nr = read(tcp_socket, answer, sizeof(answer));
	if (nr < 0)
		fail_errno("TCP Ping could not receive answer from Pong server");
		

/*** Check if the answer is OK, and fail if it is not ***/
	/*** TO BE DONE START ***/
	if(answer[0]=='E'){
		fail_errno("Unexpected response from Pong server");
	}
	/*** TO BE DONE END ***/

    /*** else ***/
	printf(" ... Pong server agreed :-)\n");

	{
		double ping_times[norep];
		struct timespec zero, resolution;
		char message[msgsz];
		int rep;
		memset(message, 0, (size_t)msgsz);
		for(rep = 1; rep <= norep; ++rep) {
			double current_time = do_ping((size_t)msgsz, rep, message, tcp_socket);
			ping_times[rep - 1] = current_time;
			printf("Round trip time was %lg milliseconds in repetition %d\n", current_time, rep);
		}
		memset((void *)(&zero), 0, sizeof(struct timespec));
		if (clock_getres(CLOCK_TYPE, &resolution))
			fail_errno("TCP Ping could not get timer resolution");
		print_statistics(stdout, "TCP Ping: ", norep, ping_times, msgsz, timespec_delta2milliseconds(&resolution, &zero));
	}

	shutdown(tcp_socket, SHUT_RDWR);
	close(tcp_socket);
	exit(EXIT_SUCCESS);
}

