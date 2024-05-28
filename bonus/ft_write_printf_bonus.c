/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_printf_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:38:25 by seungryk          #+#    #+#             */
/*   Updated: 2023/12/12 17:38:30 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	get_zero(t_write *buf, t_flag *op)
{
	int	len;

	len = 0;
	if (op->type == 's' || (op->zero && op->minus))
		return ;
	if (op->zero && op->width > op->type_len && !op->dot)
	{
		len = op->width - op->type_len - op->plus_sign;
		if (!op->minus_sign)
			len -= op->space;
	}
	else if (op->precision > op->type_len - op->minus_sign - op->hash)
	{
		if ((int)op->arg == 0)
			len = op->precision - op->type_len;
		else
			len = op->precision - (op->type_len - op->hash) + op->minus_sign;
		if (len < 0)
			return ;
		else if (op->hash && (int)op->arg != 0 \
					&& op->precision < op->type_len - op->hash)
			len += 2;
	}
	buf->idx += ft_strset(&buf->ret[buf->idx], '0', len);
	return ;
}

char	*ft_argcpy(char c, t_write *buf, t_flag *op)
{
	char	*ret;

	ret = NULL;
	if (c == 'c')
		ret = ft_char((int)op->arg);
	else if (op->dot == 1 && op->precision == 0 && (int)op->arg == 0)
		ret = ft_strdup("");
	else if (c == 'x' || c == 'p')
		ret = ft_putnbr_base((unsigned long)op->arg, op->type, HEX_LOWER);
	else if (c == 'X')
		ret = ft_putnbr_base((unsigned long)op->arg, op->type, HEX_UPPER);
	else if ((c == 'd' || c == 'i'))
		ret = ft_itoa((int)op->arg);
	else if (c == 'u')
		ret = ft_itoa((unsigned int)op->arg);
	else if (c == '%')
		ret = ft_strdup("%");
	if (!ret)
		return (NULL);
	if (op->type == 'c')
		buf->idx += ft_strncpy(&buf->ret[buf->idx], ret, 1);
	else
		buf->idx += ft_strncpy(&buf->ret[buf->idx], ret, ft_strlen(ret));
	ret = ft_free(ret);
	return (buf->ret);
}

int	write_buf(t_flag *op, t_write *buf)
{
	char	*ret;

	ft_memset(buf, 0, sizeof(t_write));
	buf->len = find_len(op);
	buf->ret = (char *)malloc(sizeof(char) * (buf->len));
	if (!buf->ret)
		return (-1);
	get_left_padding(buf, op);
	get_prefix(buf, op);
	get_zero(buf, op);
	ret = get_argument(buf, op);
	if (!ret)
	{
		buf->ret = ft_free(buf->ret);
		return (-1);
	}
	if (op->minus)
		get_right_padding(buf, op);
	if (write(1, buf->ret, buf->len) < 0)
	{
		buf->ret = ft_free(buf->ret);
		return (-1);
	}
	buf->ret = ft_free(buf->ret);
	return (buf->len);
}
