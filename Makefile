CC = gcc

LDFLAGS		= -L/Users/$(USER)/.brew/opt/readline/lib
CPPFLAGS	= -I/Users/$(USER)/.brew/opt/readline/include

INC			= -I./Libft -I./includes

CFLAGS =  $(LDFLAGS) $(CPPFLAGS) -Wall -Werror -Wextra 

LFLAGS = -ltermcap -L libft/ -lft -lreadline

NAME		= minishell
LIB_PATH	= ./Libft
LIBFT_NAME	= ./Libft/libft.a

SOURCES =	main.c																\
			parser/parser.c														\
			parser/parse_redirections.c											\
			parser/parse_redirections_2.c										\
			parser/parse_endstr.c												\
			parser/parse_endcmd.c												\
			parser/parse_asterix.c												\
			parser/input_check.c												\
			parser/input_check2.c												\
			parser/parse_endcmd2.c												\
			utils/list_utils.c													\
			utils/list_utils2.c													\
			utils/str_utils.c													\
			utils/utils.c														\
			execute/execute.c													\
			signals/signals.c													\
			builtins/echo.c														\
			builtins/cd.c														\
			builtins/env.c														\
			builtins/exit.c														\
			builtins/export.c													\
			builtins/unset.c													\
			builtins/pwd.c														\
			builtins/true_false.c												\
			execute/redirect.c													\
			execute/execute_utils2.c											\
			execute/execute_utils.c												\
			execute/manage_main.c												\
			execute/cmd_find.c

#COLORS
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
BLACK = "\033[38;2;52;52;52m"
UP = "\033[A"
CUT = "\033[K"


OBJECTS = $(SOURCES:.c=.o)
%.o: %.c
	@$(CC) -Wall -Wextra -Werror $(CPPFLAGS) $(INC) -o $@ -c $<


all: $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJECTS)
	@$(CC) $(OBJECTS) $(CFLAGS) $(LFLAGS) -o $@
	@printf $(X)""

$(LIBFT_NAME):
	@echo $(Y)
	@echo compiling libft ... | fmt -c $$(tput cols)
	@echo $(G)
	@make -C $(LIB_PATH) | fmt -c $$(tput cols)
	@printf $(X)""

clean:
	@echo $(Y)
	@echo cleaning object-files | fmt -c $$(tput cols)
	@rm -f $(OBJECTS)
	@sleep 0.2
	@make fclean -C $(LIB_PATH)
	@echo $(G)
	@echo done removing object-files | fmt -c $$(tput cols)
	@printf $(X)""

fclean:
	@echo $(Y)
	@echo cleaning all binary files | fmt -c $$(tput cols)
	@make clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_PATH)
	@sleep 0.2
	@echo $(G)
	@echo fclean done | fmt -c $$(tput cols)
	@printf $(X)""

re: fclean all

