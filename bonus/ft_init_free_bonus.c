/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_free_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:37:27 by seungryk          #+#    #+#             */
/*   Updated: 2023/12/12 17:37:33 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_flag	*init_op(void)
{
	t_flag	*op;

	op = (t_flag *)malloc(sizeof(t_flag));
	if (!op)
		return (NULL);
	return (op);
}

t_write	*init_write(void)
{
	t_write	*buf;

	buf = (t_write *)malloc(sizeof(t_write));
	if (!buf)
		return (NULL);
	return (buf);
}

int	free_op(t_flag **op)
{
	free(*op);
	*op = NULL;
	return (-1);
}

int	free_buf(t_write **buf)
{
	free(*buf);
	*buf = NULL;
	return (-1);
}

void	*ft_free(char *s)
{
	free(s);
	s = NULL;
	return (NULL);
}
