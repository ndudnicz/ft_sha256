/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_limits.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <ndudnicz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 09:24:01 by ndudnicz          #+#    #+#             */
/*   Updated: 2016/01/20 09:24:19 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LIMITS_H
# define MY_LIMITS_H

# define CHARMAX 127
# define CHARMIN -128
# define UCHARMAX 255

# define SHORTMAX 32767
# define SHORTMIN -32768
# define USHORTMAX 65535

# define INTMAX 2147483647
# define INTMIN -2147483648
# define UINTMAX 4294967295

# define LONGMAX 9223372036854775807L
# define LONGMIN -9223372036854775807L

# define LLONGMAX 9223372036854775807LL
# define LLONGMIN -9223372036854775807LL

#endif

/*
**Set LONGMIN - 1 for the real value
**Set LLONGMIN - 1 for the real value
**ULONGMAX & ULLONGMAX = LLONGMAX * 2 + 1
*/
