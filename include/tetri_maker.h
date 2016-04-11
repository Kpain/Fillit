/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_maker.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:54:26 by qhonore           #+#    #+#             */
/*   Updated: 2015/12/23 14:56:45 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRI_MAKER_H
# define TETRI_MAKER_H

# include <stdlib.h>
# include "block.h"

t_tri	*tetri_maker(char map[4][4], t_point pos, int connect);

#endif
