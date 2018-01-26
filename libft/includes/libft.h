/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:50:56 by ndudnicz          #+#    #+#             */
/*   Updated: 2017/10/20 10:39:55 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

# define BUFF_SIZE 4096

void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t n);
char		*ft_strncat(char *s1, const char *s2, size_t n);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);
char		*ft_itoa(int n);
int			ft_putendl(char const *s);
void		ft_putnbr(int n);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);

void		ft_putnbr_endl(int n);
char		*ft_strdupchr(const char *s1, int c);
char		*ft_strndup(const char *s1, size_t n);
size_t		ft_strlenchr(const char *s, int c);
char		*ft_itoa_base(int value, int base);
void		ft_putbase(long int value, char base, char upper);
int			ft_include_int(int *array, int size, int number);
int			ft_include_strstr(char **array, char *str);
void		ft_sleep(int second);
int			ft_putnstr(char *str, int n);
int			ft_putnchar(char c, int n);
int			ft_numberlen(long int number, int base);
int			gnl(int const fd, char **line);
int			ft_atoi_base(char *str, int base);
char		*ft_strdup(char const *s);
char		*ft_ltoa(long int n);
char		*ft_strjoin_free(char const *s1, char const *s2,
								char const a, char const b);
int			ft_array_length(char const **array);

#endif
