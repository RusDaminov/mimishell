#include "../includes/execute.h"

static const	t_builtins g_built_cmd[] = {
		{"cd", &bt_cd},
		{"echo", &bt_echo},
		{"env", &bt_env},
		{"exit", &bt_exit},
		{"export", &bt_export},
		{"pwd", &bt_pwd},
		{"true", &bt_true},
		{"false", &bt_false},
		{"true", &bt_true},
		{NULL, NULL}
};

int	is_builtin(char *cmd)
{
	int	i;

	i = 0;
	while (g_built_cmd[i].name)
	{
		if (!ft_strncmp(cmd, g_built_cmd[i].name,
				ft_strlen(g_built_cmd[i].name) + 1))
			return (1);
		i++;
	}
	return (0);
}
static int safe_std(t_execute *exec, t_cmds *cmd)
{
	if (cmd->in_dir)
	{
		exec->s_in = dup(0);
		if (exec->s_in == -1)
		{
			perror("minishell");
		}
	}
}

static int reset_to_std(t_execute *exec, t_cmds *cmd)
{
	if (cmd->in_dir)
	{
		if (dup2(exec->s_in, 0) == -1)
		{
			close(exec->s_in);
			close(exec->s_out);
			return (1);
		}
		close(exec->s_in);
	}
	if (cmd->out_dir)
	{
	if (dup2(exec->s_out, 1) == -1)
		{
			close(exec->s_out);
			return (1);
		}
		close(exec->s_out);
	}
	return (0);
}


int	exec_in_main(t_execute *exec, t_cmds *cmd)
{
	if (safe_std(exec, cmd) == 1)
		return (1);
	signal(SIGNAL, heredoc_ctlc);
	if (redirect(cmd, exec) == 1)
	{
		reset_to_std(exec, cmd);
		return (1);
	}
	check_builtin(cmd, exec);
	if (reset_to_std(exec, cmd) == 1)
		return (1);
	return (exec->exit);
}
