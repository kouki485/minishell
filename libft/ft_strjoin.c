/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 06:18:04 by kkohki            #+#    #+#             */
/*   Updated: 2021/10/10 06:55:34 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	sum;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	sum = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(sum + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (*s1)
		ptr[i++] = *s1++;
	while (*s2)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	return (ptr);
}
