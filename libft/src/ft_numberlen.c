/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numberlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 11:41:21 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/07 11:45:47 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_numberlen(long int number, int base)
{
	int		i;

	i = 1;
	if (number < 0 && base == 10)
		i++;
	while (number /= base)
		i++;
	return (i);
}
