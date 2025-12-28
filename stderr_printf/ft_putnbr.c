/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:24:13 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/28 19:35:35 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stderr_printf.h"

int	ft_putnbr(int n)
{
	int	x;

	x = 0;
	if (n == -2147483648)
		x += write (2, "-2147483648", 11);
	else if (n < 0)
	{
		x += write (2, "-", 1);
		n *= -1;
	}
	if (n >= 0 && n <= 9)
	{
		n = n + '0';
		x += ft_putchar(n);
		return (x);
	}
	if (n > 9)
	{
		x += ft_putnbr ((n / 10));
		n = (n % 10) + '0';
		x += ft_putchar(n);
	}
	return (x);
}

// int main()
// {
// 	int i = -12212121;
// 	int x;
// 	x = ft_putnbr(i);
// 	printf("\n");
// 	ft_putnbr(x);
// }