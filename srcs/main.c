/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:24:00 by chermist          #+#    #+#             */
/*   Updated: 2019/01/21 23:38:32 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tetrimino.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd;
	char	**ttrs;
	int		i;
	int		tetri[27][6];
	t_mtx	mat;

	mat.j = 0;
	mat.delim = 0;
	if ((ac != 2) || ((fd = open(av[1], O_RDONLY)) == -1))
		EXIT("usage: ./fillit source_file\n");
	if (!(ttrs = isvalid(fd)))
		EXIT("error\n");
	close(fd);
	i = -1;
	fig(ttrs, tetri);
	mat = fillit(tetri, -1, -1, mat);
	while (*mat.mtx[++i])
	{
		ft_putstr(mat.mtx[i]);
		write(1, "\n", 1);
	}
	return (0);
}
