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
	t_etra	*tetra;

	count = 0;
	tetra = *begin_list;
	while (tetra)
	{
		count++;
		tetra = tetra->next;
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
		if (!(map[i] = (char *)malloc(sizeof(char) * (size + 1))))
		{
			while (--i >= 0)
				free(map[i]);
			free(map);
			return (0);
		}
		j = -1;
		while (++j < size)
			map[i][j] = '.';
		map[i][j] = '\0';
	}
	return (1);
}

static char	tet_min_x(char *coor)
{
	char	i;
	char	xmin;

	i = -1;
	xmin = coor[0];
	while (++i < 4)
		if (coor[i * 2] < xmin)
			xmin = coor[i * 2];
	return (xmin);
}

static char	tet_max_x(char *coor)
{
	char	i;
	char	xmax;

	i = -1;
	xmax = coor[0];
	while (++i < 4)
		if (coor[i * 2] > xmax)
			xmax = coor[i * 2];
	return (xmax);
}

static char	tet_min_y(char *coor)
{
	char	i;
	char	ymin;

	i = -1;
	ymin = coor[1];
	while (++i < 4)
		if (coor[i * 2 + 1] < ymin)
			ymin = coor[i * 2 + 1];
	return (ymin);
}

static char	tet_max_y(char *coor)
{
	char	i;
	char	ymax;

	i = -1;
	ymax = coor[1];
	while (++i < 4)
		if (coor[i * 2 + 1] > ymax)
			ymax = coor[i * 2 + 1];
	return (ymax);
}

void	tet_norm(t_etra **begin_list)
{
	char	i;
	char	xmin;
	char	ymin;
	t_etra	*tetra;

	tetra = *begin_list;
	while (tetra)
	{
		i = -1;
		xmin = tet_min_x(tetra->coor);
		ymin = tet_min_y(tetra->coor);
		while (++i < 4)
		{
			tetra->coor[i * 2] = tetra->coor[i * 2] - xmin;
			tetra->coor[i * 2 + 1] = tetra->coor[i * 2 + 1] - ymin;
		}
		tetra = tetra->next;
	}
}
/*
char	tet_place(char **map, t_etra **begin_list)
{
	int		i;
	t_etra	*tetra;

	tetra = *begin_list;
	while (buffer)
	{
		i = -1;
		while (++i < 4)
			if (map[(int)tetra->coor[i * 2 + 1]][(int)tetra->coor[i * 2]] == '.')
				map[(int)tetra->coor[i * 2 + 1]][(int)tetra->coor[i * 2]] = tetra->c;
	}
}
*/
char	tet_place_map(char **map, t_etra *tetra)
{
	char	i;

	i = -1;
	while (++i < 4)
		if (map[(int)tetra->coor[i * 2 + 1]][(int)tetra->coor[i * 2]] != '.')
			return (0);
	i = -1;
	while (++i < 4)
		map[(int)tetra->coor[i * 2 + 1]][(int)tetra->coor[i * 2]] = tetra->c;
	return (1);
}

char	tet_move(char size_map, t_etra *tetra)
{
	char	i;
	char	xmin;

	i = -1;
	while (++i < 4)
		tetra->coor[i * 2] = tetra->coor[i * 2] + 1;
	if (tet_max_x(tetra->coor) >= size_map)
	{
		i = -1;
		xmin = tet_min_x(tetra->coor);
		while (++i < 4)
			tetra->coor[i * 2] = tetra->coor[i * 2] - xmin;
		i = -1;
		while (++i < 4)
			tetra->coor[i * 2 + 1] = tetra->coor[i * 2 + 1] + 1;
		if (tet_max_y(tetra->coor) >= size_map)
			return (0);
	}
	return (1);
}
