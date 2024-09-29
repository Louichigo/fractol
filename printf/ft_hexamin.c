/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexamin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:45:24 by lobertho          #+#    #+#             */
/*   Updated: 2022/11/18 11:08:53 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexamin(unsigned long i, int *count)
{
	if (i >= 16)
	{
		ft_hexamin(i / 16, count);
		ft_hexamin(i % 16, count);
	}
	else
	{
		if (i < 10)
			ft_putchar(i + '0', count);
		else if (i >= 10)
			ft_putchar((i - 10) + 'a', count);
	}
	return (*count);
}
