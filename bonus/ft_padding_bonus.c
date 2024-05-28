/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:37:46 by seungryk          #+#    #+#             */
/*   Updated: 2023/12/12 17:37:50 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	d_padding(t_flag *op)
{
	int	value_len;

	if ((int)op->arg == 0 && op->dot)
		value_len = op->precision + op->plus_sign;
	else
		value_len = ((op->plus_sign && !op->minus_sign) + \
			ft_max(op->type_len, op->precision + op->minus_sign));
	return (value_len);
}

static int	s_padding(t_flag *op)
{
	int	value_len;

	if (op->dot)
		value_len = ft_min(op->type_len, op->precision);
	else if ((int)op->arg == 0)
		value_len = op->type_len;
	else
		value_len = op->type_len;
	return (value_len);
}

static int	else_padding(t_flag *op)
{
	int	value_len;

	if ((int)op->arg == 0)
	{
		if (op->dot)
			value_len = op->precision;
		else
			value_len = op->type_len;
	}
	else
		value_len = ft_max(op->precision + op->hash, op->type_len);
	return (value_len);
}

void	get_left_padding(t_write *buf, t_flag *op)
{
	int	len;
	int	value_len;

	if (op->type == 'd' || op->type == 'i')
		value_len = d_padding(op);
	else if (op->type == 's')
		value_len = s_padding(op);
	else
		value_len = else_padding(op);
	if (!op->dot && !op->minus_sign && op->type != 's')
		value_len += op->space;
	len = op->width - value_len;
	if (op->minus || (op->zero && !op->dot))
		return ;
	buf->idx += ft_strset(&buf->ret[buf->idx], ' ', len);
}

void	get_right_padding(t_write *buf, t_flag *op)
{
	int	len;
	int	value_len;

	if (op->type == 'd' || op->type == 'i')
		value_len = d_padding(op);
	else if (op->type == 's')
		value_len = s_padding(op);
	else
		value_len = else_padding(op);
	if (op->minus_sign)
		op->space = 0;
	len = op->width - value_len - op->space;
	if (len <= 0)
		return ;
	buf->idx += ft_strset(&buf->ret[buf->idx], ' ', len);
}
