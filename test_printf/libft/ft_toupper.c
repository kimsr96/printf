/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:32:34 by seungryk          #+#    #+#             */
/*   Updated: 2023/10/17 14:20:14 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	int	diff;

	diff = 'a' - 'A';
	if (c >= 'a' && c <= 'z')
		return (c - diff);
	else
		return (c);
}