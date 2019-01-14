/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:53:10 by rymuller          #+#    #+#             */
/*   Updated: 2019/01/14 18:21:36 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	c;
	char	fd;
	char	**map;
	char	coor[8];
	t_etra	*buffer;
	int		num_bytes;
	t_etra	**begin_list;
	char	buff[BUFF_SIZE + 1];

	if (argc == 2)
	{
		if (!(begin_list = (t_etra **)malloc(sizeof(t_etra *))))
			return (0);
		*begin_list = NULL;
		c = 'A';
		fd = open(argv[1], O_RDONLY);
		while ((num_bytes = read(fd, buff, BUFF_SIZE)) > 0)
		{
			k = 0;
			i = 0;
			j = -1;
			while (++j < BUFF_SIZE)
			{
				if (buff[j] == '#')
				{
					coor[k * 2] = j % 5;
					coor[k * 2 + 1] = i;
					k++;
				}
				if (buff[j] == '\n')
					i++;
			}
			ft_list_push_back(begin_list, coor, c++);
		}
		close(fd);
		/*		
		buffer = *begin_list;
		while (buffer)
		{
			i = -1;
			while (++i < 8)
				printf("%d ", buffer->coor[i]);
			printf("\n");
			printf("%c\n", buffer->c);
			buffer = buffer->next;
		}
		*/
	}
	if (!(map = (char **)malloc(sizeof(char *) * 4)))
		return (0);
	printf("%d\n", init_map(map, 4));
	tet_norm(begin_list);
	buffer = *begin_list;
//	while (buffer)
//	{
		i = -1;
		while (++i < 4)
			map[(int)buffer->coor[i * 2 + 1]][(int)buffer->coor[i * 2]] = buffer->c;

		i = -1;
		while (++i < 4)
			printf("%s\n", map[i]);
//	}
	return (0);
}
