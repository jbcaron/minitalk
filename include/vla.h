/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vla.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:12:18 by jcaron            #+#    #+#             */
/*   Updated: 2023/01/05 15:25:41 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VLA_H
# define VLA_H

typedef struct s_vla
{
	size_t	nb_elem;
	size_t	index;
	char	*content;
}	t_vla;

void	vla_init(t_vla *vla, size_t nb_elem);
void	vla_add(t_vla *vla, char new_elem);
void	vla_destroy(t_vla *vla);

#endif
