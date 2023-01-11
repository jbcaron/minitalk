/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:09:02 by jcaron            #+#    #+#             */
/*   Updated: 2023/01/11 13:24:53 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdbool.h>

enum e_code_error
{
	MEM_ALLOC,
	NUM_ARG,
	BAD_ARG,
	BAD_PID,
	TIMEOUT_SRV,
	TIMEOUT_CLI
};

void	error(enum e_code_error code, bool to_exit);

#endif
