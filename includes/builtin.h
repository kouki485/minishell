#ifndef BUILTIN_H
# define BUILTIN_H

#include "minishell.h"
#include "parser.h"
int	ft_strcmp(const char *s1, const char *s2);
int do_echo(char **c);
int count_lst(t_cmd *cmd_list);
char **make_lst(t_cmd *cmd_list);
int do_pwd(void);
int compare_builtin(char **c);

#endif
