/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:16:46 by jcaron            #+#    #+#             */
/*   Updated: 2023/10/08 18:08:21 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_IS_H
# define STR_IS_H

# include <stdbool.h>

# define STR_MIN_INT "2147483648"
# define STR_MAX_INT "2147483647"

bool	ft_str_is_digit(const char *str);
bool	ft_str_is_int(const char *str);

#endif /* STR_IS_H */