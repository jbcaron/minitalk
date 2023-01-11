/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:42:10 by jcaron            #+#    #+#             */
/*   Updated: 2023/01/11 13:23:09 by jcaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_dyn_str
{
	size_t	len;
	size_t	capacity;
	char	*str;
}			t_dyn_str;

t_dyn_str	*ds_create(size_t capacity);
void		ds_destroy(t_dyn_str *ds);
size_t		ds_append_char(t_dyn_str *ds, char c);
size_t		ds_append_str(t_dyn_str *ds, char *str);
size_t		get_closer_pow(size_t n);
int			ft_str_is_digit(const char *str);
int			ft_str_is_int(char *str);
char		*get_next_line(int fd);
int			ft_printf(const char *format, ...);
int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
bool		ft_isdigit(char c);
bool		ft_islower(char c);
bool		ft_isupper(char c);
bool		ft_isalpha(char c);
bool		ft_isalnum(char c);
bool		ft_isascii(char c);
bool		ft_isprint(char c);
bool		ft_isspace(char c);
void		*ft_memchr(const void *s, unsigned char c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
int			ft_putchar_fd(char c, int fd);
int			ft_putendl_fd(char *str, int fd);
int			ft_putstr_fd(char *str, int fd);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *string);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strncat(char *dest, const char *src, size_t n);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_tolower(char c);
int			ft_toupper(char c);
#endif
