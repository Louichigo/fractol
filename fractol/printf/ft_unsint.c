/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:42:07 by lobertho          #+#    #+#             */
/*   Updated: 2022/11/14 12:27:19 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsint(unsigned int i, int *count)
{
	if (i >= 10)
	{
		ft_int((i / 10), count);
		ft_int((i % 10), count);
	}
	else
		ft_putchar((i + '0'), count);
	return (*count);
}
