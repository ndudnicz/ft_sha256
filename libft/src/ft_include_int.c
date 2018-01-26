/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_include_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 13:54:04 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/03 13:55:34 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_include_int(int *array, unsigned int size, int number)
{
	unsigned int		i;

	i = 0;
	while (i < size / 4)
	{
		if (array[i] == number)
			return (1);
		i++;
	}
	return (0);
}
