//
// Created by 大貫　弘貴 on 2022/07/16.
//
#include "../../includes/minishell.h"

t_cmd	*lex_pars(char *input, t_cmd *cmd_list)
{
	int		res;
	t_token	*lexerbuf;

	//lexerを作る
	res = lexer_build(input, &lexerbuf);
	free(input);
	if (res == 0 || lexerbuf->data == NULL)
		return (NULL);
	return (cmd_list);
}