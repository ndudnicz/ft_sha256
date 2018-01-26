/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:19:41 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/19 14:55:33 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "libftasm.h"

static void		ft_sub_itoa(unsigned int n, unsigned int i, char *str)
{
	if (n >= 10)
	{
		ft_sub_itoa(n % 10, i, str);
		ft_sub_itoa(n / 10, i + 1, str);
	}
	else
		str[i] = n + 48;
}

static void		ft_revstr(char *str)
{
	int		i;
	char	len;
	char	tmp;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		if (str[i] == '-')
		{
			i++;
			len++;
		}
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i++;
	}
}

static char		n_len(int n)
{
	char	len;

	if (n < 0)
		len = 3;
	else
		len = 2;
	while (n /= 10)
		len++;
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	char	len;

	i = 0;
	len = n_len(n);
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		ft_sub_itoa(-n, 1, str);
	}
	else
		ft_sub_itoa(n, 0, str);
	while (i < len)
		i++;
	str[i] = '\0';
	ft_revstr(str);
	return (str);
}
