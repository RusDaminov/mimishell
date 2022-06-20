#include "../includes/execute.h"


void	wait_for_real(t_list *lst, t_execute *exec)
{
	t_list	head;

	head = lst;
	my_wait(0, 1);
	while (lst)
	{
		my_wait(lst->content, 0);
		lst = lst->next;
	}
	if (head)
		exec->exit = ((t_pid *) ft_lstlast(head)->content)->exit;
	my_wait(0, 1);
}
