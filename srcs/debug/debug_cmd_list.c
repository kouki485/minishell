//
// Created by 大貫　弘貴 on 2022/07/31.
//
#include "../includes/debug.h"

void debug_cmd_list(t_cmd *cmd_list) {
	t_cmd* initial_cmd = cmd_list;

	printf("*****[debug cmd_list]*****\n");
	while (cmd_list) {
		t_list *initail_list = cmd_list->args;
		while (cmd_list->args->content) {
			printf("\x1b[36mcmd_list->args->content = %s\n\033[m", (char *)cmd_list->args->content);
			cmd_list->args = cmd_list->args->next;
		}
		cmd_list->args = initail_list;
		cmd_list = cmd_list->next;
	}
	cmd_list = initial_cmd;
	printf("**************************\n");
}