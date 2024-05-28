/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:43:05 by seungryk          #+#    #+#             */
/*   Updated: 2023/12/12 20:50:36 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	s_len(t_flag *op)
{
	int	len;

	if (op->dot)
		len = ft_max(op->width, ft_min(op->type_len, op->precision));
	else
		len = ft_max(op->width, op->type_len);
	return (len);
}

static int	d_len(t_flag *op)
{
	int	value_len;

	if ((int)op->arg == 0 && op->dot)
		value_len = op->precision + op->plus_sign + op->space;
	else
	{
		value_len = (((op->plus_sign || op-> space) && !op->minus_sign) + \
			ft_max(op->type_len, op->precision + op->minus_sign));
	}
	value_len = ft_max(op->width, value_len);
	return (value_len);
}

static int	else_len(t_flag *op)
{
	int	len;

	if ((int)op->arg == 0)
	{
		if (op->dot)
			len = ft_max(op->width, op->precision);
		else
			len = ft_max(op->width, op->type_len);
	}
	else
	{
		len = ft_max(op->precision + op->hash, op->type_len);
		if (op->width > 0)
			len = ft_max(op->width, len);
	}
	return (len);
}

int	find_len(t_flag *op)
{
	int	len;

	len = 0;
	if (op->type == 'd' || op->type == 'i')
	{
		len = d_len(op);
		if ((int)op->arg < 0 && len == op->precision)
			len += 1;
	}
	else if (op->type == 's')
		len = s_len(op);
	else
		len = else_len(op);
	return (len);
}
