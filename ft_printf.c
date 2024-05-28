/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:38:06 by seungryk          #+#    #+#             */
/*   Updated: 2023/12/12 17:38:55 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_op(const char *s, t_flag *op, t_write *buf, va_list ap)
{
	int		i;
	int		len;
	int		temp_len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[++i] != '%')
		{
			ft_memset(op, 0, sizeof(t_flag));
			i += get_flag(&s[i], op, ap);
			temp_len = write_buf(op, buf);
		}
		else
			temp_len = ft_putchar_fd(s[i++], 1);
		if (temp_len < 0)
			return (-1);
		len += temp_len;
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int			len;
	va_list		ap;
	t_flag		*op;
	t_write		*buf;

	op = init_op();
	if (!op)
		return (free_op(&op));
	buf = init_write();
	if (!buf)
	{
		free_op(&op);
		return (free_buf(&buf));
	}
	va_start(ap, s);
	len = check_op(s, op, buf, ap);
	va_end(ap);
	free_op(&op);
	free_buf(&buf);
	if (len < 0)
		return (-1);
	return (len);
}
