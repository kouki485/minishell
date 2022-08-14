//
// Created by 大貫　弘貴 on 2022/08/13.
//
#include "../includes/minishell.h"

void	node_update(t_token **lexerbuf) {
	token_add_back(lexerbuf, token_new(""));
}

int	stack_token(t_token **lexerbuf, char input) {
	if (input == CHAR_WHITESPACE) {
		printf("\x1b[36m[debug] : IN CHAR_WHITESPACE\n\033[m");
		node_update(lexerbuf);
		return STATE_GENERAL;
	} else if(input == CHAR_PIPE) {
		printf("\x1b[36m[debug] : IN CHAR_PIPE\n\033[m");
		if (ft_strlen((token_last(*lexerbuf))->data) == 0) {
			printf("\x1b[36m[aaaaaaaa]\n\033[m");
			token_last(*lexerbuf)->data = ft_strjoin_c((token_last(*lexerbuf)->data), input);
		} else {
			printf("\x1b[36m[bbbbbbbb]\n\033[m");
			token_add_back(lexerbuf, token_new(""));
			token_last(*lexerbuf)->data = ft_strjoin_c((token_last(*lexerbuf)->data), input);
			token_add_back(lexerbuf, token_new(""));
		}
		return STATE_GENERAL;
	} else if (input == CHAR_QOUTE) {
		printf("\x1b[36m[debug] : IN CHAR_QOUTE\n\033[m");
		if (ft_strlen((token_last(*lexerbuf))->data) == 0) {
			token_last(*lexerbuf)->data = ft_strjoin_c((token_last(*lexerbuf)->data), input);
		} else {
			token_add_back(lexerbuf, token_new(""));
			token_last(*lexerbuf)->data = ft_strjoin_c((token_last(*lexerbuf)->data), input);
		}
		return STATE_IN_QUOTE;
	} else {
			printf("\x1b[36m[debug] : IN CHAR NORMAL\n\033[m");
			printf("\x1b[36m[debug] : input = %c\n\033[m", input);
			token_last(*lexerbuf)->data = ft_strjoin_c((token_last(*lexerbuf)->data), input);
			return STATE_GENERAL;
	}
}

int	lexer_build(char *input, t_token **lexerbuf) {
	(void)lexerbuf;
	*lexerbuf = token_new("");
	int	token_status;

	token_status = STATE_GENERAL;
	while (*input != '\0') {
		if (token_status == STATE_GENERAL) {
			token_status = stack_token(lexerbuf, *input);
		}

		else if (token_status == STATE_IN_DQUOTE) {
			printf("state_in_dquote in\n");
		}

		else if (token_status == STATE_IN_QUOTE) {
			printf("state_in_quote in\n");
			token_last(*lexerbuf)->data = ft_strjoin_c((token_last(*lexerbuf)->data), *input);
			if (*input == '\'')
				token_status = STATE_GENERAL;
		}
		input++;
	}

	debug_lexerbuf(lexerbuf);

	return (0);
}