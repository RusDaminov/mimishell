#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

t_cmds	*parse(char *str, t_cmds *cur, char *av);


int	parse_redirecions(char **str, char **strbuf, t_cmds **cur);

#endif
