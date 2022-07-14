/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 21:30:06 by kkohki            #+#    #+#             */
/*   Updated: 2021/11/20 17:08:05 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	need;
	size_t	i;
	size_t	j;
	char	*hay;

	hay = (char *)haystack;
	need = ft_strlen(needle);
	if (need == 0 || hay == needle)
		return (hay);
	if (len == 0)
		return (0);
	i = 0;
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (hay[i + j] != '\0' && needle[j] != '\0'
			&& hay[i + j] == needle[j] && i + j < len)
			j++;
		if (j == need)
			return (hay + i);
		i++;
	}
	return (0);
}
