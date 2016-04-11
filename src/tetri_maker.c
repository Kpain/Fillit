/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:51:12 by qhonore           #+#    #+#             */
/*   Updated: 2015/12/22 22:39:29 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetri_maker.h"

static int		is_valid(char map[4][4], t_point pos, int *connect)
{
	int		i;

	i = 0;
	if (pos.y > 0 && map[pos.y - 1][pos.x] == '#')
		i++;
	if (pos.x > 0 && map[pos.y][pos.x - 1] == '#')
		i++;
	if (pos.y < 3 && map[pos.y + 1][pos.x] == '#')
		i++;
	if (pos.x < 3 && map[pos.y][pos.x + 1] == '#')
		i++;
	*connect += i;
	if (i)
		return (1);
	return (0);
}

static t_tri	*set_final_pos(t_tri *tetri)
{
	int		i;
	t_point	min;

	i = 0;
	min.x = 4;
	min.y = 4;
	while (i < 4)
	{
		if (min.x > tetri->dot[i].x)
			min.x = tetri->dot[i].x;
		if (min.y > tetri->dot[i].y)
			min.y = tetri->dot[i].y;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		tetri->dot[i].x = tetri->dot[i].x - min.x;
		tetri->dot[i].y = tetri->dot[i].y - min.y;
		i++;
	}
	return (tetri);
}

t_tri			*tetri_maker(char map[4][4], t_point pos, int connect)
{
	t_tri	*tetri;
	int		i;

	pos.x = -1;
	pos.y = -1;
	i = 0;
	if (!(tetri = (t_tri*)malloc(sizeof(t_tri))))
		return (NULL);
	while (++pos.y < 4)
	{
		pos.x = -1;
		while (++pos.x < 4)
		{
			if (map[pos.y][pos.x] == '#' && !is_valid(map, pos, &connect))
				return (NULL);
			if (map[pos.y][pos.x] == '#')
			{
				tetri->dot[i].x = pos.x;
				tetri->dot[i].y = pos.y;
				i++;
			}
		}
	}
	return (connect >= 6 ? set_final_pos(tetri) : NULL);
}
