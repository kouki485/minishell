/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:10:13 by kkohki            #+#    #+#             */
/*   Updated: 2021/11/16 21:16:13 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*m;
	t_list	*n;

	if (lst && *lst)
	{
		n = *lst;
		while (n)
		{
			m = n;
			n = n->next;
			ft_lstdelone(m, del);
		}
		*lst = NULL;
	}
}
