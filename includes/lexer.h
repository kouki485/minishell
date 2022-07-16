#ifndef LEXER_H
# define LEXER_H

#include "../libft/libft.h"
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

t_token	*token_new(void);
int	get_char_type(char c);
bool	compare_redirect(char *str);
int	check_return_status(t_token **token, int status);
int	check_status(int char_type, int status);
int	join_return_status(t_token **token, char *str, int char_type, int status);
int	assign_general(t_token **token, char *input, int char_type);
int	check_token_return_status(t_token **token, char *input, int char_type, int status);

#endif