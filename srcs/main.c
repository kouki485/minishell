#include "../includes/minishell.h"

void execute_minishell(char **environ)
{
	char *line;
	t_cmd *cmd_list;

	(void)environ;
	while (1)
	{
		line = readline("minishell> ");
		if (line == NULL)
			break;
		add_history(line);
		cmd_list = lex_pars(line, cmd_list);
		printf("\x1b[36m[debug] : return main.c\n\033[m");
	}
	free(line);
	exit(SUCCESS);
}


int main(int argc, char **argv)
{
	//環境変数
	extern char **environ;
	(void)argv;

	if (argc == 1)
		execute_minishell(environ);
	return (0);
}