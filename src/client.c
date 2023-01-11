/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:22:31 by jcaron            #+#    #+#             */
/*   Updated: 2023/01/11 14:26:29 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file client.c
 * 
 * @brief Contains the main function for the client program for minitalk
 * service.
 * 
 * @author jcaron
 * 
 * @date December 2022
 * 
 * This file contains the main function of the client program for minitalk.
 * It first retrieves the pid of the server from the command
 * line arguments, then initializes the signalhandling for the program and
 * finally sends the message specified in the command line arguments to the
 * server.
*/

#include "minitalk.h"
#include "client.h"
#include "msg_cli.h"
#include "libft.h"
#include "error.h"

/**
 * @brief Global variable to store the the acknowledgement status.
 * 
 * This global variable is used to store the state of the acknowledgement
 * status.
 * It can have the values 0 (no acknowledgement), 1 (acknowledgement of a bit)
 * or 2 (acknowledgement of a message).
*/

int		g_ack;

/**
 * @brief Signal handler function for the client program
 * 
 * This function is called every time the client program receives a signal. It
 * checks thereceived signal and updates the value of the global variable g_ack
 * accordingly.
 * 
 * @param sig The signal number that has been received.
*/

void	handle_sigusr(int sig)
{
	if (sig == SIG_ACK_BIT)
		g_ack = 1;
	else if (sig == SIG_ACK_MSG)
		g_ack = 2;
}

/**
 * @brief Retrieves the pid of the server from the command line arguments.
 * 
 * This function retrieves the pid of the server from the command line arguments
 * and checksthat it is a valid integer and a positive number greater than 1.
 * If the pid is invalid, the function calls the error function with the
 * appropriate error code.
 * 
 * @param argc The number of command line arguments.
 * @param argv The array of command line arguments.
 * 
 * @return The pid of the server.
*/

int	get_pid(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		error(NUM_ARG, true);
	if (!ft_str_is_int(argv[1]))
		error(BAD_ARG, true);
	pid = ft_atoi(argv[1]);
	if (pid <= 1)
		error(BAD_PID, true);
	return (pid);
}

/**
 * @brief Initializes the signal handling for the client program.
 * 
 * This function initializes the signal handling for the client program by
 * setting up a sigaction structure and specifying the handle_sigusr function
 * as the signal handler. It also sets the value of the global variable g_ack
 * to 1.
*/

void	init_sig(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handle_sigusr;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIG_ACK_BIT, &sa, NULL);
	sigaction(SIG_ACK_MSG, &sa, NULL);
	g_ack = 1;
}

/**
 * @brief The main function for the client program of the minitalk program.
 * 
 * This function is the entry point for the client program of the minitalk
 * program. It first retrieves the pid of the server from the command line
 * arguments, then initializes the signal handling for the program and finally
 * sends the message specified in the command line arguments to the server.
 * 
 * @param argc The number of command line arguments.
 * @param argv The array of command line arguments.
 * 
 * @return 0 upon successful execution.
*/

int	main(int argc, char **argv)
{
	int	pid;

	pid = get_pid(argc, argv);
	init_sig();
	send_msg(pid, argv[2]);
	return (0);
}
