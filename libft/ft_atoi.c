/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:46:25 by kkohki            #+#    #+#             */
/*   Updated: 2021/10/14 18:51:54 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	res;
	int			num;

	res = 0;
	num = 1;
	while (('\t' <= *str && *str <= '\r') || (*str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			num *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
		if (res > (long int)INT_MIN * -1 && num == -1)
			return (0);
		if (res > INT_MAX && num == 1)
			return (-1);
	}
	return ((int)res * num);
}
