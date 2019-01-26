/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:43:26 by chermist          #+#    #+#             */
/*   Updated: 2019/01/21 23:40:32 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
# define TETRIMINO_H
# define EXIT(msg) {ft_putstr_fd(msg, 1), exit(1);}
# include "../libft/libft.h"

typedef struct	s_mtx
{
	char		mtx[16][16];
	int			delim;
	int			x[26];
	int			y[26];
	int			j;
}				t_mtx;

void			ft_c(char *ttr, int *tetri);
void			fig(char **ttrs, int tetri[26][6]);
int				chk_fig(char *b, int elc);
char			**isvalid(int fd);
t_mtx			fillit(int tetri[27][6], int x, int y, t_mtx mat);
void			newmap(t_mtx *mat, int tetri[26][6]);

#endif
