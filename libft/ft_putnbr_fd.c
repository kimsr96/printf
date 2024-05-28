/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:10:20 by seungryk          #+#    #+#             */
/*   Updated: 2023/11/07 14:17:29 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static long long	recursion(long long n, int fd, int cnt)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		if (write(fd, &c, 1) < 0)
			return (-1);
		return (cnt);
	}
	else
	{
		c = (n % 10) + '0';
		cnt = recursion(n / 10, fd, cnt + 1);
		if (cnt == -1 || write(fd, &c, 1) < 0)
			return (-1);
	}
	return (cnt);
}

int	ft_putnbr_fd(char c, void *n, int fd)
{
	int			cnt;
	long long	num;

	cnt = 0;
	num = 0;
	if (c == 'u')
	{
		num = (unsigned int)num;
		num = (unsigned int)n;
	}
	else
		num = (int)n;
	if (num < 0)
	{
		if (write(fd, "-", 1) < 0)
			return (-1);
		cnt += 1;
		num *= -1;
	}
	cnt = recursion(num, fd, cnt + 1);
	if (cnt < 0)
		return (-1);
	return (cnt);
}
