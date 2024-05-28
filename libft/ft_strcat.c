/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:01:45 by seungryk          #+#    #+#             */
/*   Updated: 2023/12/12 14:33:59 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t	idx;
	size_t	len_dst;
	size_t	len_src;

	idx = 0;
	len_dst = 0;
	len_src = 0;
	while (dst[len_dst])
		len_dst++;
	while (src[len_src])
		len_src++;
	while (src[++len_src] || dst[len_dst + idx])
	{
		dst[len_dst + idx] = src[len_src];
		idx++;
	}
	dst[len_dst + idx] = '\0';
	return (dst);
}
