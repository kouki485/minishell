//
// Created by 大貫　弘貴 on 2022/07/17.
//
#include "minishell.h"

t_redirect	*redirect_new(void)
{
	t_redirect *new;

	new = malloc(sizeof(t_redirect));
	new->file_name = NULL;
	new->redirect_type = 0;
	return (new);
}

t_cmd	*cmd_new(void)
{
	t_cmd	*res;

	res = malloc(sizeof(t_cmd));
	res->next = NULL;
	res->args = ft_lstnew(NULL);
	res->heredocend = NULL;
	res->fd_out = -1;
	res->fd_in = -1;
	res->redirect = redirect_new();
	return (res);
}