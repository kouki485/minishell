//
// Created by 大貫　弘貴 on 2022/08/13.
//
#include "../includes/lexer.h"

t_token*	token_new() {
	t_token	*new;

	new = malloc(sizeof(new));
	if (new == NULL)
		return (NULL);
	new->data = NULL;
	new->type = TOKEN;
	new->next = NULL;
	return (new);
}

t_token	*token_last(t_token *list) {
	while (list) {
		if (list->next == NULL)
			return (list);
		list = list->next;
	}
	return (list);
}

void	token_add_back(t_token **list, t_token *new) {
	t_token	*tmp;

	if (list) {
		if (*list) {
			tmp = token_last(*list);
			tmp->next = new;
		}
		else
			*list = new;
	}
}
