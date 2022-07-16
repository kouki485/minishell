#ifndef LEXER_H
# define LEXER_H

#include "minishell.h"
#include "parser.h"
typedef enum e_token_type
{
	CHAR_GENERAL		= -1,
	CHAR_PIPE			= '|',
	CHAR_QOUTE			= '\'',
	CHAR_DQOUTE			= '\"',
	CHAR_WHITESPACE		= ' ',
	CHAR_GREATER		= '>',
	CHAR_LESSER			= '<',
	TOKEN				= -1,
}		t_token_type;

typedef enum e_status
{
	STATE_IN_DQUOTE,
	STATE_IN_QUOTE,
	STATE_GENERAL,
}	t_status;

typedef struct s_token		t_token;
typedef struct s_lexer		t_lexer;
typedef struct s_cmd_len	t_cmd_len;

typedef struct s_token
{
	char	*data;
	int		type;
	t_token	*next;
}		t_token;

t_token	*token_new(void);
int	get_char_type(char c);
bool	compare_redirect(char *str);
int	check_return_status(t_token **token, int status);
int	check_status(int char_type, int status);
int	join_return_status(t_token **token, char *str, int char_type, int status);
int	assign_general(t_token **token, char *input, int char_type);
int	check_token_return_status(t_token **token, char *input, int char_type, int status);
int	lexer_build(char *input, t_token **lexerbuf);

#endif