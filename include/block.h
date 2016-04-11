/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 18:18:31 by qhonore           #+#    #+#             */
/*   Updated: 2015/12/22 21:13:03 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCK_H
# define BLOCK_H

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_tri
{
	t_point	dot[4];
}				t_tri;

typedef struct	s_map
{
	char	map[15][15];
	int		size;
}				t_map;

typedef	struct	s_tritab
{
	t_tri	**tab;
	int		nb;
}				t_tritab;

#endif
