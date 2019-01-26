/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 21:42:30 by chermist          #+#    #+#             */
/*   Updated: 2019/01/21 23:38:50 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tetrimino.h"

int		paint(int *s, int y, int x, t_mtx *mat)
{
	if (((x + s[0]) < 0) || ((x + s[0]) > 15) || ((y + s[1]) > 15) ||
		((x + s[2]) < 0) || ((x + s[2]) > 15) || ((y + s[3]) > 15) ||
		((x + s[4]) < 0) || ((x + s[4]) > 15) || ((y + s[5]) > 15))
		return (0);
	if ((mat->mtx[y + s[1]][x + s[0]] == '.') &&
		(mat->mtx[y + s[3]][x + s[2]] == '.') &&
		(mat->mtx[y + s[5]][x + s[4]] == '.'))
	{
		if (!(mat->mtx[x + 1][y]))
		{
			mat->y[mat->j] = y;
			mat->x[mat->j] = -1;
		}
		else
		{
			mat->x[mat->j] = x;
			mat->y[mat->j] = y - 1;
		}
		mat->mtx[y][x] = 65 + mat->j;
		mat->mtx[y + s[1]][x + s[0]] = 65 + mat->j;
		mat->mtx[y + s[3]][x + s[2]] = 65 + mat->j;
		mat->mtx[y + s[5]][x + s[4]] = 65 + mat->j;
		return (1);
	}
	return (0);
}

int		solver(t_mtx *mat, int tetri[27][6], int *y, int *x)
{
	while (++*y < mat->delim)
	{
		while (++*x < mat->delim)
			if (mat->mtx[*y][*x] == '.')
			{
				if (paint(tetri[mat->j], *y, *x, mat))
				{
					mat->j++;
					*y = -1;
					*x = -1;
					return (0);
				}
			}
		*x = -1;
	}
	return (1);
}

void	figdel(t_mtx *mat, int *s)
{
	int x;
	int y;
	int j;

	j = -1;
	if (mat->x[mat->j] != -1)
	{
		x = mat->x[mat->j];
		y = mat->y[mat->j] + 1;
	}
	else
	{
		x = mat->delim - 1;
		y = mat->y[mat->j];
	}
	mat->mtx[y][x] = '.';
	mat->mtx[y + s[1]][x + s[0]] = '.';
	mat->mtx[y + s[3]][x + s[2]] = '.';
	mat->mtx[y + s[5]][x + s[4]] = '.';
}

void	newmap(t_mtx *mat, int tetri[26][6])
{
	int			i;
	static int	flag = 1;

	i = 0;
	if (flag)
	{
		while (tetri[i][0] != 9)
			i++;
		mat->delim = ft_sqrt(i * 4);
		mat->delim = mat->delim * mat->delim < i * 4 ? mat->delim + 1 :
			mat->delim;
		flag = 0;
	}
	i = -1;
	while (++i < 16)
		ft_memset(mat->mtx[i], '\0', 16);
	i = -1;
	while (++i < mat->delim)
		ft_memset(mat->mtx[i], '.', mat->delim);
}

t_mtx	fillit(int tetri[27][6], int y, int x, t_mtx mat)
{
	int flag;

	newmap(&mat, tetri);
	while (1)
	{
		if (tetri[mat.j][0] == 9)
			return (mat);
		flag = 1;
		if (!solver(&mat, tetri, &y, &x))
			flag = 0;
		if (flag && mat.j == 0)
		{
			mat.delim++;
			newmap(&mat, tetri);
			y = -1;
			x = -1;
		}
		else if (flag && mat.j)
		{
			mat.j -= 1;
			figdel(&mat, tetri[mat.j]);
			x = mat.x[mat.j];
			y = mat.y[mat.j];
		}
	}
}
