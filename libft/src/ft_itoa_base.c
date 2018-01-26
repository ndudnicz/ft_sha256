/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:26:38 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/12/12 18:18:22 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void		ft_strclr(char *str, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		str[i] = 0;
		i++;
	}
}

static int		n_len(int value, int base)
{
	int		len;

	len = 2;
	if (base == 10 && value < 0)
		len++;
	while (value /= base)
		len++;
	return (len);
}

static void		rev_str(int value, int base, char *str)
{
	int		len;
	int		i;
	char	temp;

	len = n_len(value, base);
	i = 0;
	if (value < 0 && base == 10)
	{
		len++;
		i = 1;
	}
	while (i < (len / 2))
	{
		temp = str[i];
		str[i] = str[len - i - 2];
		str[len - i - 2] = temp;
		i++;
	}
}

static void		putnbr_str(long int value, int base, char *str)
{
	if (value < 0 && base == 10)
	{
		str[0] = '-';
		value = -value;
		str++;
	}
	if (value < 0)
		value = -value;
	if (value >= base)
	{
		putnbr_str(value / base, base, str + 1);
		putnbr_str(value % base, base, str);
	}
	else
	{
		if (value > 9)
			*str = value + 55;
		else
			*str = value + 48;
	}
}

char			*ft_itoa_base(int value, int base)
{
	char	*str;
	int		len;

	len = n_len(value, base);
	if (base < 2 || base > 16)
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	ft_strclr(str, len);
	putnbr_str(value, base, str);
	rev_str(value, base, str);
	str[len - 1] = '\0';
	return (str);
}
