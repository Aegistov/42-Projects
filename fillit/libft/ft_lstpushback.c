t_list	*ft_pushback(t_list *node, char *buf, size_t buf_size)
{
	t_list	*new;
	t_list	*tmp;

	new = ft_lstnew(buf, buf_size);
	if (node)
	{
		tmp = node;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		node = new;
	return (node);
}
