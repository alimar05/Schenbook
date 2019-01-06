#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <stdio.h>
# define SIZE 5

typedef	struct		s_list
{
	char			*tetra;
	char			c;
	char			y;
	char			x;
	char			height;
	char			width;
	struct s_list	*next;
}					t_list;

#endif
