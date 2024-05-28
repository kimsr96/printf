/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_info_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:37:19 by seungryk          #+#    #+#             */
/*   Updated: 2023/12/12 17:37:22 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	get_space(t_write *buf, t_flag *op)
{
	int	value_len;

	if ((int)op->arg == 0)
		value_len = 0;
	else
		value_len = op->type_len;
	if (op->dot)
	{
		if (!op->minus_sign && ft_max(op->precision, value_len) >= op->width)
			buf->idx += ft_strset(&buf->ret[buf->idx], ' ', 1);
		else if (op->minus && !op->minus_sign)
			buf->idx += ft_strset(&buf->ret[buf->idx], ' ', 1);
	}
	else if (!op->minus_sign)
		buf->idx += ft_strset(&buf->ret[buf->idx], ' ', 1);
}

void	get_prefix(t_write *buf, t_flag *op)
{
	if (op->type == 'd' || op->type == 'i')
	{
		if (op->space)
			get_space(buf, op);
		if ((int)op->arg < 0)
			buf->idx += ft_strset(&buf->ret[buf->idx], '-', 1);
		else if (op->plus_sign)
			buf->idx += ft_strset(&buf->ret[buf->idx], '+', 1);
	}
	else if (op->type == 'p' || (op->hash && op->type == 'x' && (int)op->arg))
	{
		if (op->type == 'p' || (unsigned long)op->arg != 0)
			buf->idx += ft_strncpy(&buf->ret[buf->idx], "0x", 2);
		else
			return ;
	}
	else if (op->hash && op->type == 'X' && (int)op->arg)
		buf->idx += ft_strncpy(&buf->ret[buf->idx], "0X", 2);
	else
		return ;
}

char	*get_argument(t_write *buf, t_flag *op)
{
	char	*ret;
	char	*arg;
	int		len;

	if (op->type == 's')
	{
		arg = (char *)op->arg;
		if (!op->dot)
			len = op->type_len;
		else
			len = ft_min(op->type_len, op->precision);
		if (arg == NULL)
			buf->idx += ft_strncpy(&buf->ret[buf->idx], "(null)", len);
		else
			buf->idx += ft_strncpy(&buf->ret[buf->idx], arg, len);
	}
	else
	{
		ret = ft_argcpy(op->type, buf, op);
		if (!ret)
			return (NULL);
	}
	return (buf->ret);
}
