/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_cli.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:19:05 by jcaron            #+#    #+#             */
/*   Updated: 2023/01/15 18:51:37 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_CLI_H
# define MSG_CLI_H

void	send_byte(int pid, char byte);
void	send_msg(int pid, char *msg);

#endif
