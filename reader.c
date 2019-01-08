/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:53:10 by rymuller          #+#    #+#             */
/*   Updated: 2019/01/08 17:55:43 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"
#define BUFF_SIZE 8

void	size_tetra(char **tetra, char *width, char *height)
{
	int			m;
	int			n;
	char		count;

	*width = 0;
	*height = 0;
	m = -1;
	while (++m < 4)
	{
		n = -1;
		count = 0;
		while (++n < 4)
		{
			if (tetra[m][n] == '#')
				count++;
			if (count > *width)
				*width = count;
		}
		if (ft_strchr(tetra[m], '#'))
			*height = *height + 1;
	}
	printf("%d %d\n", *width, *height);
}

int		main(int argc, char **argv)
{
	int			i;

	char		fd;
	static char	str[1];
	int			num_bytes;
	char		width;
	char		height;
	char		**tetra;
	char		**strsplit;
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
	while (strsplit[++i])
	{
		if (i == 0 || i % 4 != 0)
			tetra[i % 4] = strsplit[i];
		else
			size_tetra(tetra, &width, &height);
	}
	return (0);
}
