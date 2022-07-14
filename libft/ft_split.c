/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 06:01:24 by kkohki            #+#    #+#             */
/*   Updated: 2021/11/10 17:24:55 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_clean(char **arr, int len)
{
	while (len > 0)
	{
		len--;
		free(arr[len]);
	}
	free(arr);
	return (NULL);
}

static size_t	ft_number_of_words(char const *str, char c)
{
	size_t	i;
	size_t	word;
	size_t	count;

	i = 0;
	word = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			word = 0;
		else if (word == 0)
		{
			word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static int	ft_wordlen(size_t i, char const *str, char c)
{
	size_t	len;

	len = 0;
	while (str[i] && str[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static void	ft_split_arg_check(char const *s, char c, char ***arr)
{
	if (!s)
	{
		*arr = NULL;
		return ;
	}
	*arr = malloc(sizeof(char *) * (ft_number_of_words(s, c) + 1));
	if (!(*arr))
		return ;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	ft_split_arg_check(s, c, &arr);
	if (!(arr))
		return (NULL);
	while (j < ft_number_of_words((char *)s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		arr[j] = malloc(ft_wordlen(i, s, c) + 1);
		if (!arr[j])
			return (ft_clean(arr, j));
		while (s[i] && s[i] != c)
			arr[j][k++] = s[i++];
		arr[j++][k] = '\0';
	}
	arr[j] = 0;
	return (arr);
}
