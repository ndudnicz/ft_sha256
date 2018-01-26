/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:10:41 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/19 14:58:49 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	if ((!*s1 && !*s2) || n == 0)
		return (1);
	else if (*s1 != *s2)
		return (0);
	else
		return (ft_strnequ(s1 + 1, s2 + 1, n - 1));
}
