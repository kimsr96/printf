/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:47:02 by seungryk          #+#    #+#             */
/*   Updated: 2023/12/12 14:03:22 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_base_len(unsigned long nbr, unsigned long len_base)
{
	unsigned long	cnt;

	cnt = 0;
	if (nbr == 0)
		cnt += 1;
	while (nbr > 0)
	{
		nbr /= len_base;
		cnt += 1;
	}
	return (cnt);
}

char	*ft_putnbr_base(unsigned long nbr, char c, char *base)
{
	size_t	len_base;
	size_t	ret_len;
	char	*ret;

	if (c == 'x' || c == 'X')
		nbr = (unsigned int)nbr;
	len_base = ft_strlen(base);
	ret_len = ft_base_len(nbr, len_base);
	ret = (char *)malloc(sizeof(char) * (ret_len + 1));
	if (!ret)
		return (0);
	ret[ret_len] = '\0';
	if (nbr == 0)
		ret[0] = '0';
	else
	{
		while (nbr)
		{
			ret[--ret_len] = base[nbr % len_base];
			nbr /= len_base;
		}
	}
	return (ret);
}
