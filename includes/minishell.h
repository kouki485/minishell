//
// Created by 大貫　弘貴 on 2022/07/14.
//

#ifndef MINISHELL_H
#define MINISHELL_H

#include <libc.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft.h"

typedef struct s_cmd	t_cmd;

typedef struct s_cmd
{
	char	cmd;
	int		fd_out;
	int		fd_in;

	t_list	*args;
	t_cmd	*next;
}		t_cmd;

# define SUCCESS 0
# define FAILURE 1

#endif
