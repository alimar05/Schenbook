#include <stdlib.h>
#include "fillit.h"

t_etra	*ft_create_elem(char *coor, char c)
{
	t_etra	*elem;

	if (!(elem = (t_etra *)malloc(sizeof(t_etra))))
		return (NULL);
	if (coor != NULL)
	{
		if (!(elem->coor = (char *)malloc(sizeof(char) * 8)))
		{
			free(elem);
			return (NULL);
		}
		ft_memcpy(elem->coor, coor, 8);
		elem->c = c;
	}
	else
		elem->coor = NULL;
	elem->next = NULL;
	return (elem);
}

void	ft_list_push_back(t_etra **begin_list, char *coor, char c)
{
	t_etra	*list;

	if (begin_list && *begin_list)
	{
		list = *begin_list;
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(coor, c);
	}
	else
		*begin_list = ft_create_elem(coor, c);
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

char	init_map(char **map, char size)
{
	int		i;
	int		j;

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

void	tet_norm(t_etra **begin_list)
{
	char	i;
	char	x0;
	char	y0;
	t_etra	*buffer;

	buffer = *begin_list;
	while (buffer)
	{
		i = -1;
		x0 = buffer->coor[0];
		y0 = buffer->coor[1];
		while (++i < 4)
		{
			buffer->coor[i * 2] = buffer->coor[i * 2] - x0;
			buffer->coor[i * 2 + 1] = buffer->coor[i * 2 + 1] - y0;
		}
		buffer = buffer->next;
	}
}
