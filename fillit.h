#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <stdio.h>
#include <libft.h>
# define SIZE 5

typedef	struct		s_etra
{
	char			**tetra;
	char			c;
	char			y;
	char			x;
	char			height;
	char			width;
	struct s_etra	*next;
}					t_etra;

void	ft_list_push_back(t_etra **begin_list, char **tetra, char c,
		char y, char x, char height, char width);

#endif
