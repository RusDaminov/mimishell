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

int	check_builtin(t_cmds *cmd, t_execute *exec)
{
	int i;

	i = 0;
	while (g_built_cmd[1].name)
	{
		if (!ft_strncmp(cmd->cmd[0], g_built_cmd[i].name,
				ft_strlen(g_built_cmd[i].name) + 1))
		{
			exec->exit = g_built_cmd[i].func[cmd->cmd];
			return (0);
		}
		i++;
	}
	return (1);
}
