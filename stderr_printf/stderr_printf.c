/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stderr_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:21:20 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/28 19:39:49 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stderr_printf.h"

int	stderr_ft_check(char prin, va_list cpy)
{
	int	count;

	count = 0;
	if (prin == 'c')
		count += ft_putchar(va_arg(cpy, int));
	else if (prin == 's')
		count += ft_putstr(va_arg(cpy, char *));
	else if (prin == 'p')
		count += ft_ptr(va_arg(cpy, void *));
	else if (prin == 'd' || prin == 'i')
		count += ft_putnbr(va_arg(cpy, int));
	else if (prin == 'u')
		count += ft_putnbr_uns(va_arg(cpy, int));
	else if (prin == 'x')
		count += ft_hexa(va_arg(cpy, int), 0);
	else if (prin == 'X')
		count += ft_hexa(va_arg(cpy, int), 1);
	else if (prin == '%')
		count += ft_putchar('%');
	return (count);
}

int	stderr_printf(const char *prin, ...)
{
	va_list	cpy;
	int		count;

	if (!prin)
		return (-1);
	count = 0;
	va_start(cpy, prin);
	while (*prin)
	{
		if (*prin == '%')
			count += stderr_ft_check(*++prin, cpy);
		else
			count += write(2, prin, 1);
		++prin;
	}
	va_end(cpy);
	return (count);
}
