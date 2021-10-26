#include "libft.h"

t_dlist	*ft_dlst_add_elem(t_dlist **lst, t_dlist *new)
{
	if (!lst || !new)
		return (NULL);
	if (!*lst)
	{
		*lst = new;
		(*lst)->next = *lst;
		(*lst)->prev = *lst;
	}
	else
	{
		new->next = *lst;
		new->prev = (*lst)->prev;
		(*lst)->prev->next = new;
		(*lst)->prev = new;
	}
	*lst = new;
	return (*lst);
}
