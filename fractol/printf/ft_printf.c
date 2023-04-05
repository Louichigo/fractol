/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:46:27 by lobertho          #+#    #+#             */
/*   Updated: 2022/11/15 15:16:48 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	writeconv(va_list *args, const char *strf, int *count, int i)
{
	if (strf[i] == 'c')
		ft_putchar(va_arg(*args, int), count);
	else if (strf[i] == 's')
		ft_string(va_arg(*args, char *), count);
	else if (strf[i] == 'p')
		ft_pointeur(va_arg(*args, void *), count);
	else if (strf[i] == 'i' || strf[i] == 'd')
		ft_int(va_arg(*args, int), count);
	else if (strf[i] == 'u')
		ft_unsint(va_arg(*args, unsigned int), count);
	else if (strf[i] == 'x')
		ft_hexamin(va_arg(*args, unsigned int), count);
	else if (strf[i] == 'X')
		ft_hexamaj(va_arg(*args, unsigned int), count);
	else if (strf[i] == '%')
		ft_putchar(strf[i], count);
	return (*count);
}

int	ft_printf(const char *strf, ...)
{
	va_list	args;
	int		i;
	int		reslen;

	va_start(args, strf);
	i = 0;
	reslen = 0;
	while (strf[i])
	{
		if (strf[i] != '%')
			ft_putchar(strf[i], &reslen);
		else
		{
			i++;
			writeconv(&args, strf, &reslen, i);
		}
		i++;
	}
	va_end(args);
	return (reslen);
}
