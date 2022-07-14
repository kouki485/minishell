/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:49:10 by kkohki            #+#    #+#             */
/*   Updated: 2021/10/08 13:49:11 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*chr;
	size_t	n;

	n = count * size;
	if (n == 0)
		n = 1;
	chr = malloc(n);
	if (!(chr))
		return (NULL);
	ft_bzero(chr, n);
	return (chr);
}
