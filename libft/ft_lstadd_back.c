/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 09:03:10 by kkohki            #+#    #+#             */
/*   Updated: 2021/10/13 09:03:10 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*m;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	m = ft_lstlast(*lst);
	m->next = new;
}
