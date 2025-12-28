/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshikder <rshikder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:24:56 by rshikder          #+#    #+#             */
/*   Updated: 2025/12/28 19:35:35 by rshikder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stderr_printf.h"

int	ft_putstr(char *s)
{
	int	x;

	if (s == NULL)
		return (write(2, "(null)", 6));
	x = 0;
	while (s[x])
	{
		write(2, &s[x], 1);
		x++;
	}
	return (x);
}

// int main()
// {
// 	char *s = "sldkjfds";
// 	ft_putstr_fd(s, 1);
// }