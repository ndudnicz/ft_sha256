/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 18:38:19 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/19 14:54:44 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "libftasm.h"

static int		cut(char *str_chr, char *save)
{
	save[0] = 0;
	if (!str_chr)
		return (0);
	*str_chr = '\0';
	str_chr++;
	ft_strcpy(save, str_chr);
	ft_memset(str_chr, 0, ft_strlen(str_chr));
	return (1);
}

static char		*strjoin_free(char **line, char *buf)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, buf);
	free(tmp);
	tmp = NULL;
	return (*line);
}

int				gnl(int const fd, char **line)
{
	int				ret;
	char			*str_chr;
	char			buf[BUFF_SIZE + 1];
	static char		save[15][BUFF_SIZE];

	if (!line || fd < 0 || fd > 14)
		return (-1);
	if (!(*line = *save[fd] ? ft_strdup(save[fd]) : ft_strnew(1)))
		return (-1);
	buf[0] = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(*line = strjoin_free(line, buf)))
			return (-1);
		if (ft_strchr(buf, '\n') != NULL)
			break ;
	}
	str_chr = ft_strchr(*line, '\n');
	if (cut(str_chr, save[fd]) == 1 || ft_strlen(*line) || ret > 0)
		return (1);
	free(*line);
	*line = NULL;
	return (ret == 0 ? 0 : -1);
}
