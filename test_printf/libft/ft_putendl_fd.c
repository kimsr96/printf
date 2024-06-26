/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:06:21 by seungryk          #+#    #+#             */
/*   Updated: 2023/10/14 21:29:35 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
