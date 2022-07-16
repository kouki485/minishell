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

//strcmp使った方がいいかも？ >> 確かに
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

//tokenリストを作成し、要素を初期化。
t_token	*token_new(void)
{
	t_token	*res;

	res = malloc(sizeof(t_token));
	res->data = NULL;
	res->next = NULL;
	res->type = -1;
	return (res);
}

int	chstatus_end(t_token *token, char *input, int char_type, int status)
{
	char	*str;

	str = ft_substr(input, 0, 1);
	token->data = for_free(ft_strjoin(token->data, str), token->data);
	free(str);
	if (char_type == CHAR_QOUTE && status == STATE_IN_QUOTE)
		return (STATE_GENERAL);
	else if (char_type == CHAR_DQOUTE && status == STATE_IN_DQUOTE)
		return (STATE_GENERAL);
	return (status);
}

//">","<"のどちらかがきたら1を返す
bool	compare_redirect(char *str)
{
	if (ft_strlen(str) == 1)
	{
		if (!ft_strncmp(str, ">", 1) || !ft_strncmp(str, "<", 1))
			return (true); 
	}
	return (false);
}

//連結させてstatusを返す
int	check_return_status(t_token **token, int status)
{
	//もしtoken内にdataがあったら
	//リストをつなげる
	if ((*token)->data != NULL)
	{
		(*token)->next = token_new();
		*token = (*token)->next;
	}
	return (status);
}

int	join_return_status(t_token **token, char *str, int char_type, int status)
{
	//-1かつ、dataの中身が(">","<")だったら
	if (char_type == CHAR_GENERAL && compare_redirect((*token)->data))
		//statusを書き換える
		status = check_return_status(&(*token), status);
	//strjoinしてつなげる前のやつはfree
	(*token)->data = for_free(ft_strjoin((*token)->data, str), (*token)->data);
	printf("\x1b[36m[debug] : status = %d\n\033[m", status);
	return (status);
}

int	check_token_return_status(t_token **token, char *input, int char_type, int status)
{
	if (char_type == CHAR_PIPE)
	{
		status = check_return_status(&(*token), status);
		status = join_return_status(&(*token), input, char_type, status);
		return (check_return_status(&(*token), status));
	}
	else if (compare_redirect((*token)->data))
	{
		status = join_return_status(&(*token), input, char_type, status);
		return (check_return_status(&(*token), status));
	}
	status = check_return_status(&(*token), status);
	return (join_return_status(&(*token), input, char_type, status));
}

int	assign_general(t_token **token, char *input, int char_type)
{
	int		status;
	char	*str;

	//char*をcharに変換
	str = ft_substr(input, 0 , 1);
	printf("\x1b[36m[debug] : str = %s\n\033[m", str);
	//strjoinして繋げてstatusに代入
	if (char_type == CHAR_QOUTE)
		status = join_return_status(&(*token), str, char_type, STATE_IN_QUOTE);
	else if (char_type == CHAR_DQOUTE)
		status = join_return_status(&(*token), str, char_type, STATE_IN_DQUOTE);
	else if (char_type == CHAR_GENERAL)
		status = join_return_status(&(*token), str, char_type, STATE_GENERAL);
	else if (char_type == CHAR_WHITESPACE)
		//リストを連結させてstatusを返す
		status = check_return_status(&(*token), STATE_GENERAL);
	else
		status = check_token_return_status(&(*token), str, char_type, STATE_GENERAL);
	free(str);
	return (status);
}

static int	print_lexer_error(char *str)
{
	printf("syntax error near unexpected token `%s\'\n", str);
	// g_signal.exit_status = 258;
	// g_signal.is_finished = true;
	return (0);
}

//error処理
int	check_status(int char_type, int status)
{
	if (char_type == CHAR_GREATER || char_type == CHAR_LESSER)
		return (print_lexer_error("newline"));
	else if (char_type == CHAR_PIPE)
		return (print_lexer_error("|"));
	if (status == STATE_IN_DQUOTE)
		return (print_lexer_error("\""));
	else if (status == STATE_IN_QUOTE)
		return (print_lexer_error("\'"));
	return (1);
}

int	lexer_build(char *input, t_token **lexerbuf)
{
	int		status;
	int		char_type;
	//char	*input_tmp;
	t_token	*token;
	
	//新しくリストを作る
	token = token_new();
	*lexerbuf = token;
	//statusに2を代入
	status = STATE_GENERAL;
	//lineがある限り
	while (*input)
	{
		//lineを一文字ずつ比較
		char_type = get_char_type(*input);
		printf("\x1b[36m[debug] : char_type = %d\n\033[m", char_type);
		if (status == STATE_GENERAL)
			status = assign_general(&token, input, char_type);
		else if (status == STATE_IN_QUOTE)
			status = chstatus_end(token, input, char_type, STATE_IN_QUOTE);
		else if (status == STATE_IN_DQUOTE)
			status = chstatus_end(token, input, char_type, STATE_IN_DQUOTE);
		input++;
	}
	return (check_status(char_type, status));
}