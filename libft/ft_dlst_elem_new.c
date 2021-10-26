#include "libft.h"

t_dlist	*ft_dlst_elem_new(t_dlist **lst, void *elem)
{
	t_dlist	*new;

	new = ft_dlst_new(elem);
	if (new == NULL)
		return (NULL);
	return (ft_dlst_add_elem(lst, new));
}
