/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goodies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:48:21 by qhonore           #+#    #+#             */
/*   Updated: 2015/12/30 19:45:13 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "goodies.h"

void	map_init(t_map *map)
{
	t_point	pos;

	pos.y = 0;
	while (pos.y < 15)
	{
		pos.x = 0;
		while (pos.x < 15)
		{
			map->map[pos.y][pos.x] = '.';
			pos.x++;
		}
		pos.y++;
	}
}

void	del_block(t_map *map, t_tri *tetri, t_point pos)
{
	int		i;
	t_point	tmp;

	i = 0;
	while (i < 4)
	{
		tmp.y = tetri->dot[i].y;
		tmp.x = tetri->dot[i].x;
		map->map[pos.y + tmp.y][pos.x + tmp.x] = '.';
		i++;
	}
}

void	print_map(t_map solved)
{
	t_point	pos;

	pos.y = -1;
	while (++pos.y < solved.size)
	{
		pos.x = -1;
		while (++pos.x < solved.size)
		{
			ft_putchar(solved.map[pos.y][pos.x]);
		}
		ft_putchar('\n');
	}
}
