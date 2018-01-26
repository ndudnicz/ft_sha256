/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:28:08 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/19 14:52:02 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "libftasm.h"

char	*ft_strnew(size_t size)
{
	char		*new_str;

	if ((new_str = (char*)malloc(size)) == NULL)
		return (NULL);
	ft_bzero(new_str, size);
	return (new_str);
}
