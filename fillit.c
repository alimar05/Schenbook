#include <stdio.h>
#define SIZE 5

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
	char	tet[][SIZE] =
	{
		{'.','.','.','.','\n'},
		{'.','.','.','.','\n'},
		{'.','.','.','.','\n'},
		{'.','.','.','.','\n'},
	};
	char	tet1[][SIZE] =
	{
		{'A','A','.','.','\n'},
		{'.','A','.','.','\n'},
		{'.','A','.','.','\n'},
		{'.','.','.','.','\n'},
	};
/*	char	tet2[][SIZE] =
	{
		{'.','.','.','.', '\n'},
		{'B','B','B','B', '\n'},
		{'.','.','.','.', '\n'},
		{'.','.','.','.', '\n'},
	};
	char	tet3[][SIZE] =
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
	printf("%d\n", tet_place(tet, tet1, 2, 2, 3, 2));
//	printf("%d\n", tet_place(tet, tet1, 1, 1, 3, 2));
//	printf("%d\n", tet_place(tet, tet1, 1, 1, 3, 2));
//	printf("%d\n", tet_place(tet, tet1, 1, 1, 3, 2));
	tet_print(tet);
	return (0);
}