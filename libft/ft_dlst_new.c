#include "libft.h"

t_dlist	*ft_dlst_new(void *elem)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (new == NULL)
		return (NULL);
	new->elem = elem;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
