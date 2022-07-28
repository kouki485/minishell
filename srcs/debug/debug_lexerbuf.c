//
// Created by 大貫　弘貴 on 2022/07/17.
//
#include "../includes/debug.h"

void debug_lexerbuf(t_token **lexerbuf)
{
	t_token* initial_token = *lexerbuf;
	printf("*****[debug lexerbuf]*****\n");
	 while (*lexerbuf)
	 {
		printf("\x1b[36mlexerbuf->data = %s\n\033[m", (*lexerbuf)->data);
		printf("\x1b[36mlexerbuf->type = %d\n\033[m", (*lexerbuf)->type);
		*lexerbuf = (*lexerbuf)->next;
	}
	*lexerbuf = initial_token;
	printf("**************************\n");
}