/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:14:32 by seungryk          #+#    #+#             */
/*   Updated: 2023/12/12 17:38:59 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_min(int a, int b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	ft_strset(char *dest, char c, int len)
{
	int	i;

	i = 0;
	if (len < 0)
		return (0);
	while (i < len)
	{
		dest[i] = c;
		i++;
	}
	return (len);
}

int	ft_strncpy(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (len);
}

char	*ft_char(int c)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * 2);
	if (!ret)
		return (NULL);
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}
