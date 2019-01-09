/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:53:10 by rymuller          #+#    #+#             */
/*   Updated: 2019/01/10 00:52:30 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"
#define BUFF_SIZE 80

void	size_tetra(char **tetra, char *width, char *height)
{
	int			m;
	int			n;

	*width = 0;
	*height = 0;
	m = -1;
	while (++m < 4)
	{
		n = -1;
		while (++n < 4)
			if (tetra[n][m] == '#')
			{
				*width = *width + 1;
				break ;
			}
		if (ft_strchr(tetra[m], '#'))
			*height = *height + 1;
	}
}

int		main(int argc, char **argv)
{
	int			i;
	char		c;
	char		fd;
	static char	str[1];
	int			num_bytes;
	char		width;
	char		height;
	char		**tetra;
	char		**strsplit;
	t_etra		*buffer;
	t_etra		**begin_list;
	char		buff[BUFF_SIZE + 1];

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((num_bytes = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[num_bytes] = '\0';
			ft_strcat(str, buff);
		}
		close(fd);
	}
	strsplit = ft_strsplit(str, '\n');
	if (!(tetra = (char **)malloc(sizeof(char *) * 4)))
		return (0);
	i = -1;
	c = 'A';
	*begin_list = NULL;
	while (strsplit[++i])
	{
		if (i != 0 && i % 4 == 0)
		{
			size_tetra(tetra, &width, &height);
			ft_list_push_back(begin_list, tetra, c++, 0, 0, height, width);
		}
		tetra[i % 4] = strsplit[i];
	}
	if (i != 0 && i % 4 == 0)
	{
		size_tetra(tetra, &width, &height);
		ft_list_push_back(begin_list, tetra, c, 0, 0, height, width);
		free(tetra);
	}
	buffer = *begin_list;
	while (buffer)
	{
		i = -1;
		while (++i < 4)
			printf("%s\n", buffer->content[i]);
		printf("%c\n", buffer->c);
		printf("%d %d\n", buffer->height, buffer->width);
		buffer = buffer->next;
	}
	return (0);
}
