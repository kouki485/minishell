//
// Created by 大貫　弘貴 on 2022/07/14.
//

#ifndef MINISHELL_H
#define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdbool.h>
#include "../libft/libft.h"
//# include "./get_next_line.h"
# include "./lexer.h"
//# include "./builtin.h"
//# include "./env.h"
//# include "./execute.h"
//# include "./expand.h"
# include "./parser.h"
//# include "./utils.h"
# include "./debug.h"

char	*for_free(char *res, char *free_str);
# define SUCCESS 0
# define FAILURE 1

#endif
