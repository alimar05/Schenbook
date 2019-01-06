#include "fillit.h"

static void	tet_print(char tet[][SIZE])
{
	int		i;
	int		j;

	i = -1;
	while (++i < SIZE - 1)
	{
		j = -1;
		while (++j < SIZE)
		{
			printf("%c", tet[i][j]);
		}
	}
}

static char	tet_place(char map[][SIZE], char tet[][SIZE], char y, char x, char heigth, char width)
{
	int		i;
	int		j;
	int		x0;
	int		y0;

	x0 = x;
	y0 = y;
	while (y < y0 + heigth)
	{
		x = x0;
		while (x < x0 + width)
		{
			if (map[y][x] != '.')
				return (0);
			x++;
		}
		y++;
	}
	i = -1;
	while (++i < heigth)
	{
		j = -1;
		while (++j < width)
			map[y0 + i][x0 + j] = tet[i][j];
	}
	return (1);
}

int			main(void)
{
	int		i;
	int		j;
	char	tet[][SIZE] =
	{
		{'.','.','.','.','\n'},
		{'.','.','.','.','\n'},
		{'.','.','.','.','\n'},
		{'.','.','.','.','\n'},
	};
	char	tet1[SIZE][SIZE];
	char	tet11[] = "AA..\n.A..\n.A..\n....\n";
	char	tet2[][SIZE] =
	{
		{'B','B','B','B', '\n'},
		{'.','.','.','.', '\n'},
		{'.','.','.','.', '\n'},
		{'.','.','.','.', '\n'},
	};
/*	char	tet3[][SIZE] =
	{
		{'C','.','.','.', '\n'},
		{'C','C','C','.', '\n'},
		{'.','.','.','.', '\n'},
		{'.','.','.','.', '\n'},
	};
	char	tet4[][SIZE] =
	{
		{'.','.','.','.', '\n'},
		{'D','D','.','.', '\n'},
		{'.','D','D','.', '\n'},
		{'.','.','.','.', '\n'},
	};
*/
	i = 0;
	j = 0;
	while (tet11[j])
	{
		if (j > 0 && j % 5 == 0)
			i++;
		tet1[i][j % 5] = tet11[j];
		j++;
	}
	printf("%d\n", tet_place(tet, tet1, 0, 0, 3, 2));
//	printf("%d\n", tet_place(tet, tet2, 3, 0, 1, 4));
//	printf("%d\n", tet_place(tet, tet1, 1, 1, 3, 2));
//	printf("%d\n", tet_place(tet, tet1, 1, 1, 3, 2));
	tet_print(tet);
	return (0);
}
