/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_cli.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:19:05 by jcaron            #+#    #+#             */
/*   Updated: 2023/01/05 18:47:05 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_CLI_H
# define MSG_CLI_H

extern int		g_ack;

void	send_byte(int pid, char byte);
void	send_msg(int pid, char *msg);

#endif
