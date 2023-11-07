/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:57:07 by seungryk          #+#    #+#             */
/*   Updated: 2023/11/07 14:32:55 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int	get_op(char c, void *arg)
{
	if (c == 'c')
		return (ft_putchar_fd((char)arg, 1));
	else if (c == 's')
		return (ft_putstr_fd((char *)arg, 1));
	else if (c == 'd' || c == 'i' || c == 'u')
		return (ft_putnbr_fd(c, arg, 1));
	else if (c == 'p')
		return (ft_print_memory((unsigned long long)arg, HEX_LOWER));
	else if (c == 'x')
		return (ft_putnbr_base((long long)arg, HEX_LOWER));
	else if (c == 'X')
		return (ft_putnbr_base((long long)arg, HEX_UPPER));
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	int			i;
	int			len;
	int			cnt;
	va_list		ap;

	i = -1;
	len = 0;
	cnt = 0;
	va_start(ap, s);
	while (s[++i])
	{
		if (s[i] == '%' && s[++i] != '%')
		{
			cnt = get_op(s[i], va_arg(ap, void *));
			if (cnt < 0)
				return (cnt);
			len += cnt;
			continue ;
		}
		if (ft_putchar_fd(s[i], 1) < 0)
			return (-1);
		len++;
	}
	va_end(ap);
	return (len);
}
/*
#include <stdio.h>
#include <limits.h>
int main(void)
{
	char *s = "hello";
	//ft_printf("\"X*U_yJ%pZRYZDn<\tc%%`y#o :Q0\"", (void *)-7492728973942173635);
	ft_printf("Hello: %%b%cc", 'x');
	return (0);
}
*/
