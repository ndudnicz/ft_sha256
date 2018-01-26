/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftasm_linux.hh                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 11:10:44 by ndudnicz          #+#    #+#             */
/*   Updated: 2017/10/20 10:33:56 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTASM_LINUX_H
# define LIBFTASM_LINUX_H
# include <unistd.h>

# define ft_isalpha _ft_isalpha
# define ft_puts _ft_puts
# define ft_strlen _ft_strlen
# define ft_bzero _ft_bzero
# define ft_isdigit _ft_isdigit
# define ft_isalnum _ft_isalnum
# define ft_isascii _ft_isascii
# define ft_isprint _ft_isprint
# define ft_tolower _ft_tolower
# define ft_toupper _ft_toupper
# define ft_strcat _ft_strcat
# define ft_memcpy _ft_memcpy
# define ft_memset _ft_memset
# define ft_strchr _ft_strchr
# define ft_atoi _ft_atoi
# define ft_atol _ft_atol
# define ft_putstr _ft_putstr
# define ft_putstr_fd _ft_putstr_fd
# define ft_putchar _ft_putchar
# define ft_putchar_fd _ft_putchar_fd
# define ft_strcmp _ft_strcmp
# define ft_strcmp_nocase _ft_strcmp_nocase
# define ft_strclr _ft_strclr

int				_ft_isalpha(int c);
int				_ft_puts(char const *str);
size_t			_ft_strlen(char const *s);
void			_ft_bzero(char const *s, size_t n);
int				_ft_isdigit(int c);
int				_ft_isalnum(int c);
int				_ft_isascii(int c);
int				_ft_isprint(int c);
int				_ft_tolower(int c);
int				_ft_toupper(int c);
char			*_ft_strcat(char *restrict s1, char const *restrict s2);
void			*_ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void			*_ft_memset(void *b, int c, size_t len);
char			*_ft_strchr(const char *s, int c);
int				_ft_atoi(const char *s);
long int		_ft_atol(const char *s);
int				_ft_putstr(const char *s);
int				_ft_putstr_fd(const char *s, int fd);
int				_ft_putchar(int c);
int				_ft_putchar_fd(int c, int fd);
int				_ft_strcmp(const char *s1, const char *s2);
int				_ft_strcmp_nocase(const char *s1, const char *s2);
void			_ft_strclr(char *s);

#endif
