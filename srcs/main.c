#include "../includes/minishell.h"

void execute_minishell(char **environ)
{
	char *line;
	(void)environ;

	while (1)
	{
		line = readline("minishell> ");
		if (line == NULL)
			break;
		printf("%s\n",line);
	}
	exit(SUCCESS);
}


int main(int argc, char **argv)
{
	extern char **environ;
	(void)argv;

	if (argc == 1)
		execute_minishell(environ);
	return (0);
}