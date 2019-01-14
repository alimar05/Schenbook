#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <stdio.h>
# include <libft.h>
# define BUFF_SIZE 21
# define SIZE 5

typedef	struct		s_etra
{
	char			*coor;
	char			c;
	struct s_etra	*next;
}					t_etra;

char	init_map(char **map, char size);
void	tet_norm(t_etra **begin_list);
void	ft_list_push_back(t_etra **begin_list, char *coor, char c);

#endif
