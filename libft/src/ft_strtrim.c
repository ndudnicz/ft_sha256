/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:32:59 by ndudnicz          #+#    #+#             */
/*   Updated: 2017/11/29 23:02:53 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "libftasm.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		n;
	int		len;
	char	*str;

	i = 0;
	n = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	if ((str = (char*)malloc(sizeof(char) * (len + 2))) == NULL)
		return (NULL);
	while (i < len + 1)
	{
		str[n] = s[i];
		n++;
		i++;
	}
	str[n] = '\0';
	return (str);
}
