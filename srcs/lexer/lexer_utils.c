//
// Created by 大貫　弘貴 on 2022/08/13.
//
#include "../includes/lexer.h"

t_token*	token_new(char *content) {
	t_token	*new;

	new = malloc(sizeof(new));
	if (new == NULL)
		return (NULL);
	printf("\x1b[36m[debug] : content = %s\n\033[m", content);
	new->data = ft_strdup(content);
	new->type = TOKEN;
	new->next = NULL;
	return (new);
}

t_token	*token_last(t_token *list) {
	while (list) {
		if (list->next == NULL)
			return (list);
		list = list->next;
	}
	return (list);
}

void	token_add_back(t_token **list, t_token *new) {
	t_token	*tmp;

	if (list) {
		if (*list) {
			tmp = token_last(*list);
			tmp->next = new;
		}
		else
			*list = new;
	}
}
char	*ft_strjoin_c(char const *s1, char c)
{
	char	*str;
	size_t	s1_len;
	size_t	i;

	printf("\x1b[36m[debug] : s1 = %s\n\033[m", s1);
	printf("\x1b[36m[debug] : c = %c\n\033[m", c);
	s1_len = ft_strlen(s1);
	str = malloc(sizeof(char) * (s1_len + 2));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		str[i] = s1[i];
	str[i] = c;
	str[i + 1] = '\0';
	printf("\x1b[36m[debug] : str = %s\n\033[m", str);
	return (str);
}


