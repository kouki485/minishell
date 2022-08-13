#include "../includes/builtin.h"


int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1) && (*s2))
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char **make_lst(t_cmd *cmd_list)
{
    char **split_command;
    int   i;
    int len;

    printf("cmd_list = %s\n",(char *)cmd_list->args->content);
    printf("cmd_list = %s\n",(char *)cmd_list->args->next->content);
    len = ft_lstsize(cmd_list->args);
    split_command = (char **)malloc(sizeof(char *) * len + 1);
    i = 0;
    // printf("len = %d\n",len);
   // while (cmd_list->args)
   while (i < len - 1)
    {
        split_command[i] = ft_strdup(cmd_list->args->content);
        cmd_list->args = cmd_list->args->next;
        printf("split_command = %s\n",split_command[i]);
        i++;
    }
    printf("%d\n",i);
    split_command[i] = NULL;
        printf("split_command2 = %s\n",split_command[0]);
        printf("split_command = %s\n",split_command[1]);
        printf("split_command = %p\n",split_command[2]);
    return (split_command);
}

int do_echo(char **c)
{
    int     i;
	char	n;

	n = 0;
	i = 1;
	if (c[1])
	{
		if (!ft_strcmp(c[i], "-n"))
		{
			n = 1;
			i++;
		}
		while (c[i])
		{
			printf("%*s", (int)ft_strlen(c[i]) + (c[i + 1] != 0), c[i]);
			i++;
		}
	}
	if (n == 0)
		printf("%c", '\n');
	return (1);
}

int do_pwd(void)
{
    char  *pwd;

    pwd = getcwd(NULL, 0);
    if (!pwd)
        return (1);
    printf("%s\n",pwd);
    return (0);
}

//int do_cd()

int compare_builtin(char **c)
{
    printf("c[0] = %s\n",c[0]);
    printf("c[1] = %s\n",c[1]);

    if (!(ft_strcmp("pwd", c[0])))
        return (do_pwd());
    else if (!(ft_strcmp("echo", c[0])))
        return (do_echo(c));
    // else if (!(ft_strcmp("echo",c, 5)))
    //     return (do_cd(c));
    return (0);
}


// int main(int argc, char **argv)
// {
//    (void)argc;
//     compare_builtin(argv);

// }