#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

int		clear_list(t_cmds *node, int ret);
t_cmds	*find_listhead(t_cmds *node);
t_cmds	*find_last(t_cmds *node);

int		append_list(t_cmds **node);

int		darr_size(char **str);

#endif
