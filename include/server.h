/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:06:29 by jcaron            #+#    #+#             */
/*   Updated: 2023/01/05 18:46:26 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

extern int	g_rec_bit;

int		pid_cli(int new_pid);
void	handle_sigusr(int sig, siginfo_t *info, void *ucontext);
void	init_sig(void);

#endif
