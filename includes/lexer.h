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

#endif