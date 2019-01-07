/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:53:10 by rymuller          #+#    #+#             */
/*   Updated: 2019/01/07 20:38:46 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"
#define BUFF_SIZE 8

int		main(int argc, char **argv)
{
	int			i;
	char		fd;
	static char	str[1];
	int			num_bytes;
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
	i = 0;
	*begin_list = NULL;
	while (strsplit[i])
	{
		temp[i % 5] = str_split[i];
		if (i % 5 == 0)
			ft_list_push_back(begin_list, temp, )
	}
	printf("%s\n", str_split[4]);
	return (0);
}
