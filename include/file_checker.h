/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 17:27:07 by qhonore           #+#    #+#             */
/*   Updated: 2015/12/18 15:22:09 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_CHECKER_H
# define FILE_CHECKER_H

# include "libft.h"
# include "tetri_maker.h"
# include <fcntl.h>

t_tritab	*file_checker(int fd, t_tritab *tetris);

#endif
