/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_srv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:11:06 by jcaron            #+#    #+#             */
/*   Updated: 2023/01/11 16:25:27 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_SRV_H
# define MSG_SRV_H

#include "libft.h"

# define ESC 27

extern int	g_rec_bit;

char	get_byte(void);
void	get_msg(void);

#endif
