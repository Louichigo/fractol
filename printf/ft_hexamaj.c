/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexamaj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:58:07 by lobertho          #+#    #+#             */
/*   Updated: 2022/11/18 11:08:44 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexamaj(unsigned long i, int *count)
{
	if (i >= 16)
	{
		ft_hexamaj(i / 16, count);
		ft_hexamaj(i % 16, count);
	}
	else if (i < 10)
		ft_putchar(i + '0', count);
	else
		ft_putchar((i - 10 + 'A'), count);
	return (*count);
}
