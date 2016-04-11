/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goodies.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:37:37 by qhonore           #+#    #+#             */
/*   Updated: 2015/12/22 23:31:40 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOODIES_H
# define GOODIES_H

# include "libft.h"
# include "block.h"

void	map_init(t_map *map);
void	del_block(t_map *map, t_tri *tetri, t_point pos);
void	print_map(t_map solved);

#endif
