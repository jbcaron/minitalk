/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_cli.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:18:07 by jcaron            #+#    #+#             */
/*   Updated: 2023/01/11 13:27:10 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file msg_cli.c
 * 
 * @brief Contains functions for the client program for minitalk service.
 * 
 * @author jcaron
 * 
 * @date December 2022
 * 
 * This file contains functions for the client program for minitalk.
 * The main function of the client program is located in the client.c file.
 * The send_byte function sends one byte of data to the server program by
 * sending a series of signals corresponding to the bits of the byte. It waits
 * for an acknowledgement signal from the server program before sending the next
 * bit. If no acknowledgement signal is received within a certain timeout, the
 * function calls the error function with the appropriate error code.
 * The send_msg function sends a message to the server program by calling the
 * send_byte function for each byte of the message. It also sends a null byte at
 * the end of the message to indicate the end of the transmission. Then waits
 * for an acknowledgement signal from the server program to confirm the
 * successful transmission of the message. If no acknowledgement signal is
 * received within a certain timeout, the function calls the error function with
 * the appropriate error code.
*/

#include <signal.h>
#include <unistd.h>
#include "msg_cli.h"
#include "minitalk.h"
#include "error.h"

/**
 * @brief External global variable to store the acknowledgement status.
 * 
 * This external global variable is used to store the acknowledgement status of
 * the client program.
 * It can have the values 0 (no acknowledgement), 1 (acknowledgement of a bit)
 * or 2 (acknowledgementof a message).
*/

extern int	g_ack;

/**
 * @brief Sends one byte of data to the server program.
 * 
 * This function sends one byte of data to the server program by sending a
 * series of signals corresponding to the bits of the byte. It waits for an
 * acknowledgement signal from the server program before sending the next bit.
 * If no acknowledgement signal is received within a certaintimeout, the
 * function calls the error function with the appropriate error code.
 * 
 * @param pid The pid of the server program.
 * @param byte The byte to be sent.
*/

void	send_byte(int pid, char byte)
{
	char	i;

	i = 0;
	while (i < 8)
	{
		if (!g_ack)
			if (!usleep(TIMEOUT))
				error(TIMEOUT_SRV, true);
		g_ack = 0;
		if ((byte & 1 << i))
			kill(pid, SIG_BIT_1);
		else
			kill(pid, SIG_BIT_0);
		i++;
	}
	return ;
}

/**
 * @brief Sends a message to the server program.
 * 
 * This function sends a message to the server program by calling the send_byte
 * function for each byte of the message. It also sends a null byte at the end
 * of the message to indicate the end of the transmission. The function then
 * waits for an acknowledgement signal from the server program to confirm the
 * successful transmission of the message. If no acknowledgement signal is
 * received within a certain timeout, the function calls the error function with
 * the appropriate error code.
 * 
 * @param pid The pid of the server program.
 * @param msg The message to be sent.
*/

void	send_msg(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_byte(pid, msg[i]);
		i++;
	}
	send_byte(pid, '\0');
	usleep(TIMEOUT);
	if (g_ack == 2)
		write(1, "Message sended succesfully\n", 27);
	else
		error(TIMEOUT_SRV, true);
	return ;
}
