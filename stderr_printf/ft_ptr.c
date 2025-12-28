/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:25:15 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/28 19:22:54 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stderr_printf.h"

int	ft_ptr(void *ptr)
{
	unsigned long long	ret;
	char				*base;
	char				buf[20];
	int					i;
	int					x;

	x = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	ret = (unsigned long long)ptr;
	base = "0123456789abcdef";
	x += ft_putstr("0x");
	i = 0;
	while (ret > 0)
	{
		buf[i] = base[ret % 16];
		ret /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		x += ft_putchar(buf[i]);
	}
	return (x);
}

// int main()
// {
// 	char *x = NULL;
// 	int count;
// 	int i;
// 	count = ft_ptr(&x);
// 	 i = printf("\n%p", &x);
// 	printf("\n%d %d", count, i);
// }
