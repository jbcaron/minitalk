/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:21:26 by jcaron            #+#    #+#             */
/*   Updated: 2023/10/08 18:11:08 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file server.c
 * 
 * @brief Contains the main function for the server program for minitalk
 * service.
 * 
 * @author jcaron
 * 
 * @date December 2022
 * 
 * This file contains the main function of the server program for minitalk.
 * It initializes the signal handling for the program and listens for
 * signals from the client program. When a signal is received, the function
 * handles it and stores the received bits in a global variable. It also stores
 * the pid of the client program in a static variable. Then waits for the next
 * signal to be received.
*/

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "minitalk.h"
#include "server.h"
#include "msg_srv.h"
#include "color.h"

/**
 * @brief global variable to store the received bit.
 * 
 * This external global variable is used to store the received bit during a
 * transmission from the client program. It can have the values
 * -1 (waiting for a signal), 0 (received a 0 bit) or 1 (received a 1 bit).
*/

int	g_rec_bit;

/**
 * @brief Static variable to store the pid of the client program.
 * 
 * This static variable is used to store the pid of the client program. If the
 * function is called with a new pid as an argument, the static variable is
 * updated with the new pid. If the function is called without an argument, the
 * static variable is returned.
*/

int	pid_cli(int new_pid)
{
	static int	pid;

	if (new_pid)
		pid = new_pid;
	return (pid);
}

/**
 * @brief interrupt function when received SIGUSR1 or SIGUSR2
 * 
 * put g_in_exchange at 1 during a transmition and put to 0 at the end when
 * received '\0'
**/

/**
 * @brief Signal handler function for the server program.
 * 
 * This function is called every time the server program receives a signal.
 * It checks the received signal and updates the value of the global variable
 * g_rec_bit accordingly. It also updates the static variable pid with the pid
 * of the client program.
 * 
 * @param sig The signal number that has been received.
 * @param info A siginfo_t structure containing information about the signal.
 * @param ucontext An unused parameter.
*/

void	handle_sigusr(int sig, siginfo_t *info,
		__attribute__((unused))void *ucontext)
{
	if (sig == SIG_BIT_0)
		g_rec_bit = 0;
	if (sig == SIG_BIT_1)
		g_rec_bit = 1;
	pid_cli(info->si_pid);
}

/**
 * @brief Initializes the signal handling for the server program.
 * 
 * This function initializes the signal handling for the server program by
 * setting up a sigaction structure and specifying the handle_sigusr function
 * as the signal handler.
*/

void	init_sig(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_sigusr;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIG_BIT_0, &sa, NULL);
	sigaction(SIG_BIT_1, &sa, NULL);
	return ;
}

/**
 * @brief The main function for the server program of the minitalk program.
 * 
 * This function is the entry point for the server program of the minitalk.
 * It first initializes the signal handling for the program and then
 * enters an infinite loop where it listens for signals from the client program.
 * When a signal is received, the function handles it and stores the received
 * bits in a global variable. It also calls the get_msg function to process the
 * received message. The function then waits for the next signal to be received
 * using the pause function.
 * 
 * @return 0 upon successful execution.
*/

int	main(void)
{
	printf(CLR"PID : %d\n", getpid());
	init_sig();
	while (1)
	{
		if (g_rec_bit >= 0)
			get_msg();
		pause();
	}
	return (0);
}
