/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:37:06 by seungryk          #+#    #+#             */
/*   Updated: 2023/12/12 17:37:13 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	check_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p')
		return (1);
	else if (c == 'd' || c == 'i' || c == 'u')
		return (1);
	else if (c == 'x' || c == 'X')
		return (1);
	else if (c == '%')
		return (1);
	else
		return (0);
}

int	get_type_len(t_flag *op, char c, va_list ap)
{
	if (c == '%')
		return (1);
	op->arg = va_arg(ap, void *);
	if (c == 'c')
		return (1);
	if (c == 's')
	{
		if ((char *)op->arg == NULL && (!op->dot || op->precision != 0))
			return (ft_strlen("(null)"));
		return (ft_strlen((char *)op->arg));
	}
	else if (c == 'd' || c == 'i')
	{
		if ((int)op->arg < 0)
			op->minus_sign = 1;
		return (ft_check_len((int)op->arg));
	}
	else if (c == 'u')
		return (ft_check_len((unsigned int)op->arg));
	else if (c == 'x' || c == 'X')
		return (ft_base_len((unsigned int)op->arg, HEX_LEN));
	else if (c == 'p')
		return (ft_base_len((unsigned long)op->arg, HEX_LEN) + 2);
	else
		return (0);
}

int	check_first_flag(char c, t_flag *op)
{
	if (c == '0')
		op->zero = 1;
	else if (c == '+')
		op->plus_sign = 1;
	else if (c == '-')
		op->minus = 1;
	else if (c == ' ')
		op->space = 1;
	else if (c == '#')
	{
		op->hash = 2;
		op->type_len += 2;
	}
	else
		return (0);
	return (1);
}

int	get_len(const char *s, t_flag *op, char flag)
{
	int	i;
	int	num;

	i = 0;
	while (s[i] && check_first_flag(s[i], op))
		i += 1;
	num = ft_atoi(&s[i]);
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
		i++;
	if (flag == 'w')
		op->width = num;
	else if (flag == '.')
	{
		op->dot = 1;
		op->precision = num;
	}
	return (i);
}

int	get_flag(const char *s, t_flag *op, va_list ap)
{
	int	i;

	i = get_len(s, op, 'w');
	while (s[i])
	{
		if (s[i] == '.')
			i += get_len(&s[i + 1], op, '.');
		else if (s[i] == '+')
			op->plus_sign = 1;
		else if (check_type(s[i]))
		{
			op->type = s[i];
			op->type_len += get_type_len(op, s[i], ap);
			if (op->hash && (int)op->arg == 0)
				op->type_len -= 2;
			if (op->plus_sign && (int)op->arg < 0)
				op->plus_sign = 0;
			return (++i);
		}
		else
			return (i);
		i++;
	}
	return (i);
}
