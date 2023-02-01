/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_srv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:09:38 by jcaron            #+#    #+#             */
/*   Updated: 2023/02/01 13:51:13 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file msg_srv.c
 * 
 * @brief Contains functions for the server program for minitalk service.
 * 
 * @author jcaron
 * 
 * @date December 2022
 * 
 * This file contains functions for the server program for minitalk.
 * The main function of the server program is located in the server.c file.
 * The get_byte function receives one byte of data from the client program by
 * waiting for the corresponding signals to be received. It stores the received
 * byte in a variable-length array (VLA) and sends an acknowledgement signal to
 * the client program after each bit is received. If no signal is received
 * within a certain timeout, the function calls the error function with the
 * appropriate error code and destroys the VLA before exiting.
 * The get_msg function receives a message from the client program by calling
 * the get_byte function until a null byte is received. It then sends an
 * acknowledgement signal to the client program to confirm the successful
 * reception of the message. The function then adds a newline character to the
 * end of the message and displays it to the standard output. It then destroys
 * the VLA.
*/

#include <signal.h>
#include <unistd.h>
#include "server.h"
#include "msg_srv.h"
#include "minitalk.h"
#include "libft.h"
#include "error.h"

/**
 * @brief External global variable to store the received bit.
 * 
 * This external global variable is used to store the received bit during a
 * transmission from the client program. It can have the values
 * -1 (waiting for a signal), 0 (received a 0 bit) or 1 (received a 1 bit).
*/

extern int	g_rec_bit;

/**
 * @brief Receives one byte of data from the client program.
 * 
 * This function receives one byte of data from the client program by waiting
 * for the corresponding signals to be received. It stores the received byte in
 * a variable-length array (VLA) and sends an acknowledgement signal to the
 * client program after each bit is received. If no signal is received within a
 * certain timeout, the function calls the error function with the appropriate
 * error code and destroys the VLA before exiting.
 * 
 * @return The received byte.
*/

char	get_byte(void)
{
	char	byte;
	char	i;

	i = 0;
	byte = 0;
	while (i < 8)
	{
		if (g_rec_bit == WAIT_NEXT)
		{
			if (!usleep(TIMEOUT))
			{
				error(TIMEOUT_CLI, false);
				return (ESC);
			}
		}
		if (g_rec_bit == 1)
			byte |= 1 << i;
		else
			byte &= ~(1 << i);
		g_rec_bit = WAIT_NEXT;
		if (++i < 8 || byte != '\0')
			kill(pid_cli(0), SIG_ACK_BIT);
	}
	return (byte);
}

/**@brief Receives a message from the client program.
 * 
 * This function receives a message from the client program by calling the
 * get_byte function until the received byte is the null terminator character
 * '\0'. It stores the received message in a variable-length array (VLA) and
 * sends an acknowledgement signal to the client program after the message is
 * received. It then adds a newline character to the VLA and writes the received
 * message to the standard output before destroying the VLA.
*/

void	get_msg(void)
{
	t_dyn_str	*ds_msg;
	char		byte;

	ds_msg = ds_create(1);
	if (!ds_msg)
	{
		error(MEM_ALLOC, false);
		return ;
	}	
	byte = 1;
	while (byte)
	{
		byte = get_byte();
		if (byte == ESC)
			break ;
		ds_append_char(ds_msg, byte);
	}
	if (byte == 0)
	{
		kill(pid_cli(0), SIG_ACK_MSG);
		ds_append_char(ds_msg, '\n');
		write(1, ds_msg->str, ds_msg->len);
	}
	ds_destroy(ds_msg);
}
