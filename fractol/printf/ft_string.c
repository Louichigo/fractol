/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:27:06 by lobertho          #+#    #+#             */
/*   Updated: 2022/11/18 10:53:35 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(const char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
		*count += write(1, "(null)", 6);
	else
	{
		while (str[i] != '\0')
		{
			ft_putchar(str[i], count);
			i++;
		}
	}
	return (*count);
}
