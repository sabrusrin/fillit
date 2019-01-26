/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:10:27 by chermist          #+#    #+#             */
/*   Updated: 2019/01/22 00:07:33 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tetrimino.h"

int		chk_fig(char *b, int elc)
{
	int		i;
	int		ch;
	int		val;

	i = 0;
	ch = 0;
	val = 0;
	while ((b[i] != '\n') && (b[i] == '.' || b[i] == '#'))
	{
		if (b[i] == '#')
		{
			ch++;
			if (((i + 1) < 21) && (b[i + 1] == '#'))
				val++;
			if (((i + 5) < 21) && (b[i + 5] == '#'))
				val++;
		}
		elc++;
		if ((((elc % 4) == 0) && b[i + 1] == '\n') && (i += 2))
			continue ;
		i++;
	}
	if (elc != 16 || ch != 4 || val < 3 || b[i - 1] != '\n')
		return (1);
	return (0);
}

char	**isvalid(int fd)
{
	char	buff[22];
	char	**ttrs;
	int		elc;
	int		rd;
	int		j;

	elc = 0;
	rd = 0;
	j = 0;
	if (!(ttrs = (char**)malloc(sizeof(*ttrs) * 27)))
		return (NULL);
	while ((rd = read(fd, buff, 21)))
	{
		if (chk_fig(buff, elc) || (j == 27))
			return ((elc == 0) ? NULL : (ft_arrdel((void**)ttrs)));
		if (!(ttrs[j] = malloc(sizeof(char) * (rd + 1))))
			return (ft_arrdel((void**)ttrs));
		buff[rd] = '\0';
		ft_memcpy(ttrs[j++], &buff, 22);
	}
	if (!(ttrs[j] = NULL) && (ft_strlen(buff) != 20))
		return (ft_arrdel((void**)ttrs));
	return (ttrs);
}
