/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:08:16 by jcaron            #+#    #+#             */
/*   Updated: 2023/10/08 18:02:47 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file error.c
 * 
 * @brief Contains functions to handle error messages and exit the program.
 * 
 * @author jcaron
 * 
 * @date December 2022
 * 
 * This file contains functions to handle error messages and exit the program.
 * The error function takes an error code as an argument and displays the
 * corresponding error message to the standard error output. It then exits the
 * program with a non-zero exit status. The error messages are defined in an
 * enumeration in the error.h file.
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "error.h"

/**
 * @brief Prints an error message and exits the program.
 *
 * This function prints an error message to stderr and exits the program with a
 * non-zero exit code, depending on the specified error code.
 *
 * @param code The error code indicating the type of error that occurred.
 *
 * @attention This function does not return.
 */

void	error(enum e_code_error code, bool to_exit)
{
	if (code == MEM_ALLOC)
		write(2, "Error : memory allocation failed\n", 33);
	else if (code == NUM_ARG)
		write(2, "Error : not 2 argument\n", 23);
	else if (code == BAD_ARG)
		write(2, "Error : invalid argument\n", 25);
	else if (code == BAD_PID)
		write(2, "Error : invalid PID\n", 20);
	else if (code == TIMEOUT_SRV)
		write(2, "Error : timeout, no acknowledge from server\n", 44);
	else if (code == TIMEOUT_CLI)
		write(2, "Error : timeout, client stop to send\n", 37);
	else
		write(2, "Error : unknown error\n", 22);
	if (code == NUM_ARG || code == BAD_ARG)
		write(1, "use : ./client [SERVER_PID] [message]\n", 38);
	if (to_exit)
		exit(1);
	return ;
}
