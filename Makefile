CC				= 	cc
CFLAGS			= 	-Wall -Wextra -Werror -g
NAME			= 	minishell
INCLUDES		= 	includes

LIBFT_PATH		= 	./libft/
SRCS_PATH		= 	./srcs/
SRCS_FILES		= 	main.c lexer/lexer.c lexer/lexer_utils.c free/free.c debug/debug_lexerbuf.c debug/debug_cmd_list.c parser/parser.c parser/parse_utils.c builtin/builtin.c

SRCS			=	$(addprefix $(SRCS_PATH), $(SRCS_FILES))
SRCS_OBJS		= 	$(SRCS:.c=.o)

LIBFTMAKE		= 	$(MAKE) -C $(LIBFT_PATH)
LIBFTFLAG		=	-L$(LIBFT_PATH) -lft
#LDFLAGS			=	-L$(shell brew --prefix readline)/lib -lreadline

ifeq ($(shell uname), Darwin)
	LDFLAGS += -L$(shell brew --prefix readline)/lib -lreadline
else
	LDFLAGS += -L/usr/include -lreadline
endif

all:			$(NAME)

$(NAME):		 $(SRCS_OBJS)
				$(LIBFTMAKE)
				$(LIBFTMAKE) bonus
				$(CC) $(CFLAGS) $(SRCS_OBJS) $(LIBFTFLAG) $(LDFLAGS) -o $(NAME)

.c.o:
				$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
				$(LIBFTMAKE) clean
				$(RM) $(SRCS_OBJS)

fclean:			clean
				$(LIBFTMAKE) fclean
				$(RM) $(NAME) $(SRCS_OBJS)

re:				fclean all

test:	all
	./minishell

.PHONY:			all clean fclean re test