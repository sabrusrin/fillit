/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_fig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:10:43 by chermist          #+#    #+#             */
/*   Updated: 2019/01/21 23:38:58 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tetrimino.h"

void	ft_c(char *ttr, int *tetri)
{
	int		flag;
	int		i;
	int		x;
	int		y;
	int		j;

	flag = 1;
	i = 0;
	j = 0;
	while (ttr[i])
	{
		if (flag && (ttr[i] == '#'))
		{
			x = i % 5;
			y = i / 5;
			flag = 0;
			i++;
		}
		if (ttr[i] == '#')
		{
			tetri[j++] = (i % 5) - x;
			tetri[j++] = (i / 5) - y;
		}
		i++;
	}
}

void	fig(char **ttrs, int tetri[26][6])
{
	int		i;
	char	**ttmp;

	ttmp = ttrs;
	i = 0;
	while (*ttrs)
	{
		ft_c(*ttrs++, tetri[i]);
		i++;
	}
	ft_arrdel((void**)ttmp);
	tetri[i][0] = 9;
}
