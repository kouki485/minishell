//
// Created by 大貫　弘貴 on 2022/07/17.
//

#ifndef MINISHELL_DEBUG_H
#define MINISHELL_DEBUG_H

#include "minishell.h"

typedef struct s_token		t_token;

void debug_lexerbuf(t_token **lexerbuf);
void debug_cmd_list(t_cmd *cmd_list);

#endif //MINISHELL_DEBUG_H
