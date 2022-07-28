#include "../includes/minishell.h"

int	get_char_type(char c)//引数のcに概要するマクロ定義したint値を返す関数。
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

t_token	*token_new(void)//ft_lstnewの亜種。
{
	t_token	*res;

	res = malloc(sizeof(t_token));
	res->data = NULL;
	res->next = NULL;
	res->type = -1;
	return (res);
}

int	chstatus_end(t_token *token, char *input, int char_type, int status)//[']や["]の文字を読み取る関数。動きは他と同じ。
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

bool	compare_redirect(char *str)
{
	if (ft_strlen(str) == 1)
	{
		if (!ft_strncmp(str, ">", 1) || !ft_strncmp(str, "<", 1))
			return (true); 
	}
	return (false);
}

int	check_return_status(t_token **token, int status)//1つのノードが区切りを迎えた時に、ノードを新規生成し繋げる関数。
{
	if ((*token)->data != NULL)
	{
		(*token)->next = token_new();
		*token = (*token)->next;
	}
	return (status);
}

int	join_return_status(t_token **token, char *str, int char_type, int status)//statusがredirectでないなら、リスト構造のtoken->dataに1文字詰めて、元のstrをfreeする関数
{
	if (char_type == CHAR_GENERAL && compare_redirect((*token)->data))//[通常文字]かつ、[<],[>]でないとき
		status = check_return_status(&(*token), status);//nodeをつなげる
	(*token)->data = for_free(ft_strjoin((*token)->data, str), (*token)->data);//dataとstrを連結後、strをfreeしてNULL埋め、そしてdataに代入
	printf("\x1b[36m[debug] : (*token)->data = %s\n\033[m", (*token)->data);
	printf("\x1b[36m[debug] : status = %d\n\033[m", status);
	return (status);
}

int	check_token_return_status(t_token **token, char *input, int char_type, int status)
{
	if (char_type == CHAR_PIPE)//char_typeが[|]の時、token->dataに格納し、ノードを新規生成し繋げる挙動。
	{
		status = check_return_status(&(*token), status);
		status = join_return_status(&(*token), input, char_type, status);
		return (check_return_status(&(*token), status));
	}
	else if (compare_redirect((*token)->data))//dataの中身が[<],[>]のとき
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

	str = ft_substr(input, 0 , 1);//先頭アドレスから1文字抽出している。
	printf("\x1b[36m[debug] : str = %s\n\033[m", str);
	if (char_type == CHAR_QOUTE)//char_typeが[']の時
		status = join_return_status(&(*token), str, char_type, STATE_IN_QUOTE);//リスト構造のtoken->dataに1文字詰める
	else if (char_type == CHAR_DQOUTE)//char_typeが["]の時
		status = join_return_status(&(*token), str, char_type, STATE_IN_DQUOTE);
	else if (char_type == CHAR_GENERAL)//char_typeが[通常文字]の時
		status = join_return_status(&(*token), str, char_type, STATE_GENERAL);
	else if (char_type == CHAR_WHITESPACE)//char_typeが[ ]の時
		status = check_return_status(&(*token), STATE_GENERAL);
	else//char_typeが[<, >, |]とかの時
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

int	check_status(int char_type, int status)//文字リテラルが不正な状態で終わってないかチェックする関数。
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
	int		status;//['],["],[通常文字]かを判別
	int		char_type;//['],["],[|],[ ],[<],[>],[通常文字]かを判別
	t_token	*token;
	
	token = token_new();
	*lexerbuf = token;
	status = STATE_GENERAL;
	while (*input)//引数で送られたinputを一文字ずつ属性を[通常文字], ['], ["] の3つに分けながら、statusを更新していく
	{
		char_type = get_char_type(*input);
		printf("\x1b[36m[debug] : char_type = %d\n\033[m", char_type);
		if (status == STATE_GENERAL)//[通常文字],2
			status = assign_general(&token, input, char_type);
		else if (status == STATE_IN_QUOTE)//['],1
			status = chstatus_end(token, input, char_type, STATE_IN_QUOTE);
		else if (status == STATE_IN_DQUOTE)//["],0
			status = chstatus_end(token, input, char_type, STATE_IN_DQUOTE);
		input++;
	}
	debug_lexerbuf(lexerbuf);
	return (check_status(char_type, status));
}