#include "../includes/execute.h"

redirect(t_cmds *data, t_execute *exec)
{
	if (!has_heredoc(data) && data->read == 1 && dup2(exec->s_fd, 0) == -1)
return (execute_errors())
}
