//
// Created by 大貫　弘貴 on 2022/08/13.
//
#include "../includes/minishell.h"

void	node_update(t_token **lexerbuf) {
	(void)lexerbuf;
}

int	stack_token(t_token **lexerbuf, char *input) {
	if (*input == CHAR_WHITESPACE) {
		node_update(lexerbuf);
		return STATE_GENERAL;
	} else {
		ft_strjoin((*lexerbuf)->data, input);
	}
	return (0);
}

int	lexer_build(char *input, t_token **lexerbuf) {
	(void)lexerbuf;
	*lexerbuf = token_new();
	int	token_status;

	token_status = STATE_GENERAL;
	while (*input != '\0') {
		if (token_status == STATE_GENERAL) {
			token_status = stack_token(lexerbuf, input);
		}

		if (token_status == STATE_IN_DQUOTE) {
			printf("state_in_dquote in");
		}

		if (token_status == STATE_IN_QUOTE) {
			printf("state_in_quote in");
		}
		input++;
	}

	return (0);
}