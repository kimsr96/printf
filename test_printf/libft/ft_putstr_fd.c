/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:00:50 by seungryk          #+#    #+#             */
/*   Updated: 2023/11/29 12:09:10 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	ssize_t	cnt;

	len = 0;
	cnt = 0;
	while (len < ft_strlen(s))
	{
		cnt = write(fd, s + len, ft_strlen(s) - len);
		if (cnt < 0)
			return (-1);
		len += cnt;
	}
	return (len);
}
