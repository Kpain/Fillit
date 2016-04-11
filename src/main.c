/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:18:44 by qhonore           #+#    #+#             */
/*   Updated: 2015/12/29 18:06:04 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_checker.h"
#include "solver.h"
#include "goodies.h"

int			main(int ac, char **av)
{
	t_tritab	*tetris;
	t_map		solved;
	int			fd;

	if (!(tetris = (t_tritab*)malloc(sizeof(t_tritab))))
		return (0);
	tetris->nb = 0;
	if (ac == 2 && (fd = open(av[1], O_RDONLY)) > 0
		&& (file_checker(fd, tetris)))
	{
		solved.size = 1;
		while ((solved.size * solved.size) < tetris->nb * 4)
			solved.size++;
		map_init(&solved);
		solver(&solved, tetris, 0, 0);
		print_map(solved);
	}
	else
		write(1, "error\n", 6);
	return (0);
}
