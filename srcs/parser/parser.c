#include "../../includes/minishell.h"

int	print_pars_error(char *str)
{
	printf("syntax error near unexpected token `%s\'\n", str);
//	g_signal.exit_status = 258;
//	g_signal.is_finished = true;
	return (0);
}

void	create_new_cmd(t_cmd **cmd_list, t_token *token, int *flg)
{
	if (*token->next->data == '|')
		*flg = print_pars_error(token->next->data);
	(*cmd_list)->next = cmd_new();
	*cmd_list = (*cmd_list)->next;
}

int	is_redirect(char *data)
{
	if (!ft_strncmp(data, ">", 1))
		return (1);
	else if (!ft_strncmp(data, ">>", 1))
		return (2);
	else if (!ft_strncmp(data, "<", 1))
		return (3);
	else if (!ft_strncmp(data, "<<", 1))
		return (4);
	else if (!ft_strncmp(data, "|", 1))
		return (5);
	return (0);
}

void	insert_redirect_list(t_redirect **redirect, t_token **token, int *flg)
{
	(*redirect)->redirect_type = is_redirect((*token)->data);
	*token = (*token)->next;
	if (is_redirect((*token)->data) != 0)
		*flg = print_pars_error((*token)->data);
	(*redirect)->file_name = ft_strdup((*token)->data);
	(*redirect)->next = redirect_new();
	*redirect = (*redirect)->next;
}

void	insert_general_list(t_list **args, t_token *token)
{
	(*args)->content = ft_strdup(token->data);
	(*args)->next = ft_lstnew(NULL);
	*args = (*args)->next;
}

void	parser(t_token *token, t_cmd *cmd_list, int *flg)
{
	t_list		*args;
	t_redirect	*redirect;

	args = cmd_list->args;
	redirect = cmd_list->redirect;
	if (token->data == NULL)
		*flg = 0;
	if (!ft_strncmp(token->data, "|", 1))
		*flg = print_pars_error(token->data);

	while(*flg && token != NULL && token->data != NULL)
	{
		if (!ft_strncmp(token->data, "|", 1))
		{
			create_new_cmd(&cmd_list, token, flg);
			redirect = cmd_list->redirect;
			args = cmd_list->args;
		}
		else if (is_redirect(token->data))
			insert_redirect_list(&redirect, &token, flg);
		else
			insert_general_list(&args, token);
		token = token->next;
	}
}

void	free_token_list(t_token *token_list)
{
	t_token	*tmp;

	while (token_list->next != NULL)
	{
		tmp = token_list->next;
		free(token_list->data);
		token_list->data = NULL;
		free(token_list);
		token_list = NULL;
		token_list = tmp;
	}
	free(token_list->data);
	token_list->data = NULL;
	free(token_list);
	token_list = NULL;
}

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
		cmd_list = cp_cmd_list;
		parser(lexerbuf, cp_cmd_list, &res);
	}
	free_token_list(lexerbuf);
	return (cmd_list);
}