/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:47:41 by kkohki            #+#    #+#             */
/*   Updated: 2021/11/11 20:23:57 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*out;

	i = 0;
	out = malloc(ft_strlen(s1) + 1);
	if (out == NULL)
		return (NULL);
	while (s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
