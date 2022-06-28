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
			parser/parse_endstring.c											\
			parser/parse_endcommand.c											\
			parser/parse_asterix.c												\
			parser/check_input.c												\
			parser/check_input_2.c												\
			parser/parse_endcommand_2.c											\
			utilities/utilities_list.c											\
			tilities/utilities_list_2.c											\
			utilities/utilities_string.c										\
			execute/execute.c													\
			utilities/utils.c													\
			execute/cmd_find.c													\
			signals/signals.c													\
			builtins/echo.c														\
			builtins/cd.c														\
			builtins/env.c														\
			builtins/exit.c														\
			builtins/export.c													\
			builtins/unset.c													\
			builtins/pwd.c														\
			builtins/false.c													\
			builtins/true.c														\
			execute/execute_utils.c												\
			execute/execute_utils_2.c											\
			env/env_utils.c														\
			execute/redirect.c													\
			execute/manage_main.c
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
	@echo $(R)
	@echo " ███▄ ▄███▓ ██▓ ███▄    █  ██▓  ██████  ██░ ██ ▓█████  ██▓     ██▓    " | fmt -c $$(tput cols)
	@echo "▓██▒▀█▀ ██▒▓██▒ ██ ▀█   █ ▓██▒▒██    ▒ ▓██░ ██▒▓█   ▀ ▓██▒    ▓██▒    " | fmt -c $$(tput cols)
	@echo "▓██    ▓██░▒██▒▓██  ▀█ ██▒▒██▒░ ▓██▄   ▒██▀▀██░▒███   ▒██░    ▒██░    " | fmt -c $$(tput cols)
	@echo "▒██    ▒██ ░██░▓██▒  ▐▌██▒░██░  ▒   ██▒░▓█ ░██ ▒▓█  ▄ ▒██░    ▒██░    " | fmt -c $$(tput cols)
	@echo "▒██▒   ░██▒░██░▒██░   ▓██░░██░▒██████▒▒░▓█▒░██▓░▒████▒░██████▒░██████▒" | fmt -c $$(tput cols)
	@echo "░ ▒░   ░  ░░▓  ░ ▒░   ▒ ▒ ░▓  ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░" | fmt -c $$(tput cols)
	@echo "░  ░      ░ ▒ ░░ ░░   ░ ▒░ ▒ ░░ ░▒  ░ ░ ▒ ░▒░ ░ ░ ░  ░░ ░ ▒  ░░ ░ ▒  ░" | fmt -c $$(tput cols)
	@echo "░      ░    ▒ ░   ░   ░ ░  ▒ ░░  ░  ░   ░  ░░ ░   ░     ░ ░     ░ ░   " | fmt -c $$(tput cols)
	@echo "       ░    ░           ░  ░        ░   ░  ░  ░   ░  ░    ░  ░    ░  ░" | fmt -c $$(tput cols)
	@echo $(BLACK)
	@echo "                                               by @nschumac & @jsiller" | fmt -c $$(tput cols)
	@echo $(X);

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

val:
	docker run --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -ti -v $(PWD):/test memory-test:0.1 bash && cd test
