/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 15:10:26 by qhonore           #+#    #+#             */
/*   Updated: 2015/12/23 15:17:31 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "block.h"
# include "goodies.h"
# include <stdlib.h>

int		solver(t_map *map, t_tritab *tetris, int position, int i);

#endif
