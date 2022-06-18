.PHONY	:	all clean fclean re

NAME	=	minishell
HEADERS =	includes/minishell.h
LIBFT	=	libft/libft.a

#//////////////////////////////////////////////////////////////////////////////
#		ALL FILES
#//////////////////////////////////////////////////////////////////////////////

SRCS	=	main.c env.c prompt.c


OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc
CFLAGS	=	#-ltermcap #-Wall -Wextra -Werror

RM		= rm -rf

#//////////////////////////////////////////////////////////////////////////////
#		COLORS
#//////////////////////////////////////////////////////////////////////////////

BLUE	=	\033[1;34m
TURQUOISE =	\033[36;1m
END		=	\033[0m

#//////////////////////////////////////////////////////////////////////////////
#		RULES
#//////////////////////////////////////////////////////////////////////////////

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADERS) ${SRCS} ${HEAD}
	@echo "\n$(BLUE)Compilation of $(NAME)$(END)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(TURQUOISE)\n[ Completed $(NAME) ]\n$(END)"

%.o		:	%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
# $< - Имя первого пререквизита (подставляется первая зависимость).
# $@ - Имя файла цели обрабатываемого правила.

clean:
			@$(RM) $(OBJ) $(OBJ_B)
			@$(RM) $(OBJ)
			@rm -f $(OBJS)
			@echo "$(BLUE)\nCleaning done\n$(END)"

fclean	:	clean
			@echo Deleting $(NAME)
			@$(RM) $(NAME) $(NAME_B)
			@echo "$(BLUE)\nDeleting done!\n$(END)"

re:			fclean all
			@echo "$(BLUE)Remake done\n$(END)"