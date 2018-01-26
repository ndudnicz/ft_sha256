/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:15:50 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/19 14:56:22 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static size_t	ft_nbwords(char const *s, char c)
{
	size_t		i;
	size_t		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i] != '\0' || s[i - 1] != c)
			n++;
	}
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		i;
	size_t		len;
	size_t		nb_words;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	nb_words = ft_nbwords(s, c);
	if ((tab = (char**)malloc(sizeof(char*) * nb_words + 1)) == NULL)
		return (NULL);
	while (i < nb_words)
	{
		len = 0;
		while (*s && *s == c)
			s++;
		while (s[len] && s[len] != c)
			len++;
		tab[i] = ft_strsub(s, 0, len);
		s = s + len;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
