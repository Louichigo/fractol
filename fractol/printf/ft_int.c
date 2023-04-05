/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:33:54 by lobertho          #+#    #+#             */
/*   Updated: 2022/11/14 12:26:38 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int(int i, int *count)
{
	if (i == -2147483648)
	{
		ft_string("-2147483648", count);
		return (*count);
	}
	if (i < 0)
	{
		ft_putchar('-', count);
		i = -i;
	}
	if (i > 9)
		ft_int(i / 10, count);
	ft_putchar(i % 10 + '0', count);
	return (*count);
}
