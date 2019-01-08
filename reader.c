/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:53:10 by rymuller          #+#    #+#             */
/*   Updated: 2019/01/08 15:52:59 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"
#define BUFF_SIZE 8

int		main(int argc, char **argv)
{
	int			i;
	int			m;
	int			n;
	char		fd;
	static char	str[1];
	int			num_bytes;
	char		width;
	char		height;
	char		count;
	char		**temp;
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
	if (!(temp = (char **)malloc(sizeof(char *) * 4)))
		return (0);
	i = -1;
	while (strsplit[++i])
	{
		if (i != 0 && i % 4 == 0)
		{
			height = 0;
			width = 0;
			m = -1;
			while (++m < 4)
			{
				n = -1;
				count = 0;
				while (++n < 4)
				{
					if (temp[m][n] == '#')
						count++;
					if (count > width)
						width = count;
				}
				if (ft_strchr(temp[m], '#'))
					height++;
			}
			printf("%d %d\n", width, height);
		}
		temp[i % 4] = strsplit[i];
	}
	return (0);
}
