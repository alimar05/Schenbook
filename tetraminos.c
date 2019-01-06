#include <stdlib.h>
#include "fillit.h"

t_list	*ft_create_elem(char **tetra, char c, char y, char x,
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

void	ft_list_push_back(t_list **begin_list, char **tetra, char c,
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

void	tet_print(char **tetra)
{
	int		i;
	int		j;

	i = -1;
	while (++i < SIZE - 1)
	{
		j = -1;
		while (++j < SIZE)
		{
			printf("%c", tetra[i][j]);
		}
	}
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
char	is_tet_place(char **map, t_list *tet)
{
	int		y;
	int		x;

	x = tet->x;
	y = tet->y;
	while (y < tet->y + tet->height)
	{
		x = tet->x;
		while (x < tet->x + tet->width)
		{
			if (map[y][x] != '.')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int		main(void)
{
	char	mapl[4][4];
	t_list	*buffer;
	t_list	**begin_list;
	char	tet[][SIZE] =
	{
		{'.','.','.','.','\n'},
		{'.','.','.','.','\n'},
		{'.','.','.','.','\n'},
		{'.','.','.','.','\n'},
	};
	char	tet1[][SIZE] =
	{
		{'#','#','.','.','\n'},
		{'.','#','.','.','\n'},
		{'.','#','.','.','\n'},
		{'.','.','.','.','\n'},
	};
	char	tet2[][SIZE] =
	{
		{'#','#','#','#', '\n'},
		{'.','.','.','.', '\n'},
		{'.','.','.','.', '\n'},
		{'.','.','.','.', '\n'},
	};
	char	tet3[][SIZE] =
	{
		{'#','.','.','.', '\n'},
		{'#','#','#','.', '\n'},
		{'.','.','.','.', '\n'},
		{'.','.','.','.', '\n'},
	};
	char	tet4[][SIZE] =
	{
		{'#','#','.','.', '\n'},
		{'.','#','#','.', '\n'},
		{'.','.','.','.', '\n'},
		{'.','.','.','.', '\n'},
	};

	*begin_list = NULL;
	ft_list_push_back(begin_list, tet1, 'A', 1, 0, 3, 2);
	ft_list_push_back(begin_list, tet2, 'B', 1, 0, 1, 4);
	ft_list_push_back(begin_list, tet3, 'C', 0, 0, 2, 3);
	ft_list_push_back(begin_list, tet4, 'D', 1, 0, 2, 3);

	buffer = *begin_list;
	while (buffer)
	{
		tet_print(buffer->tetra);
		buffer = buffer->next;
	}
	return (0);
}
