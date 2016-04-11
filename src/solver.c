/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:30:29 by qhonore           #+#    #+#             */
/*   Updated: 2015/12/23 14:59:15 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

static int		is_good(t_map *map, t_point pos, t_tri *tetri)
{
	int		i;
	t_point	tmp;

	i = 0;
	while (i < 4)
	{
		tmp.y = tetri->dot[i].y;
		tmp.x = tetri->dot[i].x;
		if ((pos.y + tmp.y >= map->size)
			|| (pos.x + tmp.x >= map->size)
			|| (map->map[pos.y + tmp.y][pos.x + tmp.x] != '.'))
			return (0);
		i++;
	}
	return (1);
}

static t_map	*place_block(t_map *map, t_point pos, t_tri *tetri, int i)
{
	int		j;
	t_point	tmp;

	j = 0;
	while (j < 4)
	{
		tmp.y = tetri->dot[j].y;
		tmp.x = tetri->dot[j].x;
		map->map[pos.y + tmp.y][pos.x + tmp.x] = i + 'A';
		j++;
	}
	return (map);
}

int				solver(t_map *map, t_tritab *tetris, int position, int i)
{
	t_point	pos;

	while (i < tetris->nb && position < map->size * map->size)
	{
		pos.y = position / map->size;
		pos.x = position % map->size;
		if (is_good(map, pos, tetris->tab[i]))
		{
			place_block(map, pos, tetris->tab[i], i);
			if (solver(map, tetris, 0, i + 1))
				return (1);
			del_block(map, tetris->tab[i], pos);
		}
		++position;
	}
	if (i == tetris->nb)
		return (1);
	if (i == 0)
	{
		map->size++;
		return (solver(map, tetris, 0, 0));
	}
	return (0);
}
