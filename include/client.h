/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:07:07 by jcaron            #+#    #+#             */
/*   Updated: 2023/10/08 18:08:01 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

extern int		g_ack;

void	handle_sigusr(int sig);
int		get_pid(int argc, char **argv);
void	init_sig(void);

#endif /* CLIENT_H */
