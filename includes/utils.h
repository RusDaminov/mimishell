#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

int	clear_list(t_cmds *node, int ret);
int	append_list(t_cmds **node);

int	darr_size(char **str);

#endif
