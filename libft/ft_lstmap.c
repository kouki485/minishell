/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 06:53:47 by kkohki            #+#    #+#             */
/*   Updated: 2021/10/20 06:55:34 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*ret;

	if (!lst || !f)
		return (NULL);
	ret = ft_lstnew((*f)(lst->content));
	if (!ret)
		return (NULL);
	tmp = ret;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew((*f)(lst->content));
		if (!(tmp->next))
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (ret);
}
