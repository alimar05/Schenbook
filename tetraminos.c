#include <stdlib.h>
#include "fillit.h"

t_list	*ft_create_elem(char *tetra, char c, char y, char x,
		char height, char width)
{
	t_list	*elem;

	if (!(elem = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	elem->tetra = tetra;
	elem->c = c;
	elem->y = y;
	elem->x = x;
	elem->height = height;
	elem->width = width;
	elem->next = NULL;
	return (elem);
}

void	ft_list_push_back(t_list **begin_list, char *tetra, char c,
		char y, char x, char height, char width)
{
	t_list	*list;

	if (begin_list && *begin_list)
	{
		list = *begin_list;
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(tetra, c, y, x, height, width);
	}
	else
		*begin_list = ft_create_elem(tetra, c, y, x, height, width);
}

char	ft_list_count(t_list **begin_list)
{
	char	count;
	t_list	*buffer;

	count = 0;
	buffer = *begin_list;
	while (buffer)
	{
		count++;
		buffer = buffer->next;
	}
	return (count);
}

char	smallest_squre_size(char n)
{
	char	size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

int		main(void)
{
	t_list	*buffer;
	t_list	**begin_list;
	char	map[] = "....\n....\n....\n....\n";
	char	tet1[] = "....\n##..\n.#..\n.#..\n";
	char 	tet2[] = "....\n####\n....\n....\n";
	char	tet3[] = "#...\n###.\n....\n....\n";
	char	tet4[] = "....\n##..\n.##.\n....\n";

	*begin_list = NULL;
	ft_list_push_back(begin_list, tet1, 'A', 1, 0, 3, 2);
	ft_list_push_back(begin_list, tet2, 'B', 1, 0, 1, 4);
	ft_list_push_back(begin_list, tet3, 'C', 0, 0, 2, 3);
	ft_list_push_back(begin_list, tet4, 'D', 1, 0, 2, 3);

	buffer = *begin_list;
	return (0);
}
