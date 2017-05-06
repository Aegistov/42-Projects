#ifndef T_LIST_H
# define T_LIST_H

typedef	struct		s_list
{
	struct s_list	*head;
	struct s_list	*tail;
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void	list_print(t_list *list);
t_list	*list_add_tail(t_list *node, char *buf, size_t buf_size);
t_list	*list_init(void const *content, size_t content_size);
char	*load_list(t_list *list);
int		list_search(t_list *list, char *str);

#endif