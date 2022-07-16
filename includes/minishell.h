//
// Created by 大貫　弘貴 on 2022/07/14.
//

#ifndef MINISHELL_H
#define MINISHELL_H

#include <libc.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft.h"

typedef struct s_cmd		t_cmd;
typedef struct s_token		t_token;


typedef struct s_token
{
	char	*data;
	int		type;
	t_token	*next;
}		t_token;

typedef struct s_cmd
{
	char	cmd;
	int		fd_out;
	int		fd_in;

	t_list	*args;
	t_cmd	*next;
}		t_cmd;

//enumで0、1、2が割り当てられた。
typedef enum e_status
{
	STATE_IN_DQUOTE,
	STATE_IN_QUOTE,
	STATE_GENERAL,
}	t_status;

char	*for_free(char *res, char *free_str);
# define SUCCESS 0
# define FAILURE 1

#endif
