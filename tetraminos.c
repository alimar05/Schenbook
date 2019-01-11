#include <stdlib.h>
#include "fillit.h"

t_etra	*ft_create_elem(char **content, char c, char y, char x,
		char height, char width)
{
	int		i;
	t_etra	*elem;

	if (!(elem = (t_etra *)malloc(sizeof(t_etra))))
		return (NULL);
	if (content != NULL)
	{
		if (!(elem->content = (char **)malloc(sizeof(char *) * 4)))
		{
			free(elem);
			return (NULL);
		}
		i = -1;
		while (++i < 4)
			(elem->content)[i] = content[i];
		elem->c = c;
		elem->y = y;
		elem->x = x;
		elem->height = height;
		elem->width = width;
	}
	else
		elem->content = NULL;
	elem->next = NULL;
	return (elem);
}

void	ft_list_push_back(t_etra **begin_list, char **tetra, char c,
		char y, char x, char height, char width)
{
	t_etra	*list;

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

char	ft_list_count(t_etra **begin_list)
{
	char	count;
	t_etra	*buffer;

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
/*
void	converter(char **dst, char *src)
{
	int		i;
	int		j;

	while (src[j])
	{
		if (j > 0 && j % 5 == 0)
			i++;
		dst[i][j % 5] = src[j];
		j++;
	}
}
*/
char	init_map(char **map, char size)
{
	int		i;
	int		j;

//	if (!(map = (char **)malloc(sizeof(char *) * size)))
//		return (0);
	i = -1;
	while (++i < size)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * size)))
		{
			while (--i >= 0)
				free(map[i]);
			free(map);
			return (0);
		}
		j = -1;
		while (++j < size)
			map[i][j] = '.';
	}
	return (1);
}
