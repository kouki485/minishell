/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 04:26:47 by kkohki            #+#    #+#             */
/*   Updated: 2022/07/15 06:20:15 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/lexer.h"

//tokenリストを作成し、要素を初期化。
t_token	*token_new(void)
{
	t_token	*res;

	res = malloc(sizeof(t_token));
	if (!res)
	{
		perror("malloc error");
		exit(FAILURE);
	}
	res->data = NULL;
	res->next = NULL;
	res->type = -1;
	return (res);
}

//strcmp使った方がいいかも？
//charを比較してそれを返してる。
int	get_char_type(char c)
{
	char	res;

	if (c == '\'')
		res = CHAR_QOUTE;
	else if (c == '\"')
		res = CHAR_DQOUTE;
	else if (c == '|')
		res = CHAR_PIPE;
	else if (c == ' ')
		res = CHAR_WHITESPACE;
	else if (c == '>')
		res = CHAR_GREATER;
	else if (c == '<')
		res = CHAR_LESSER;
	else
		res = CHAR_GENERAL;
	return (res);
}

int	assign_general(t_token **token, char *input, int char_type)
{
	int		status;
	char	*str;

	str = ft_substr(input, 0 , 1);
	//この処理がよくわからない。
	if (char_type == CHAR_QOUTE)
		status = join_return_status
}

int	lexer_build(char *input, t_token **lexerbuf)
{
	int		status;
	int		char_type;
	char	*input_tmp;
	t_token	*token;
	
	token = token_new();
	*lexerbuf = token;
	status = STATE_GENERAL;
	while (*input)
	{
		char_type = get_char_type(*input);
		if (status == STATE_GENERAL)
			status = assign_general(&token, input, char_type);
	}
}

t_cmd	*lex_pars(char *input, t_cmd *cmd_list)
{
	int		res;
	t_token	*lexerbuf;
	
	res = lex_build(input, &lexerbuf);
	free(input);
	if (res == 0 || lexerbuf->data == NULL)
		return (NULL);
	rerurn (cmd_list);
}