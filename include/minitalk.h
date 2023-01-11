/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:35:40 by jcaron            #+#    #+#             */
/*   Updated: 2023/01/10 16:58:01 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>

/**
 * signal for the value of send bit
**/

# define SIG_BIT_0 SIGUSR1
# define SIG_BIT_1 SIGUSR2

/**
 * acknownlegment signal for each bit or for the end of message
**/

# define SIG_ACK_BIT SIGUSR1
# define SIG_ACK_MSG SIGUSR2

# define WAIT_NEXT -1

/**
 * timeout in us
 **/

# define TIMEOUT 10000

#endif
