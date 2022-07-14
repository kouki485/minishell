/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:26:38 by kkohki            #+#    #+#             */
/*   Updated: 2021/10/28 04:20:28 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	i;

	if (!s || !f)
		return (NULL);
	p = (char *)malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	i = 0;
	p[ft_strlen(s)] = '\0';
	while (s[i])
	{
		p[i] = (*f)(i, s[i]);
		i++;
	}
	return (p);
}
