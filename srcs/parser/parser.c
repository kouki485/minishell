#include "../../includes/minishell.h"

t_cmd	*lex_pars(char *input, t_cmd *cmd_list)
{
	int		res;
	t_token	*lexerbuf;
	t_cmd 	*cp_cmd_list;

	printf("\x1b[36m[debug] : input = %s\n\033[m", input);
	res = lexer_build(input, &lexerbuf);
	free(input);

	if (res == 0 || lexerbuf->data == NULL)
		return (NULL);
	else if (res == 1)
	{
		cp_cmd_list = cmd_new();
	}
	return (cmd_list);
}