/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 19:46:31 by qhonore           #+#    #+#             */
/*   Updated: 2016/01/08 14:22:27 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_checker.h"

static t_list	*file_reader(int fd)
{
	t_list	*list;
	int		ret;
	char	buf[22];

	list = NULL;
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		ft_lstaddend(&list, ft_lstnew(buf, ft_strlen(buf) + 1));
	}
	return (list);
}

static t_tri	*content_checker(char *str)
{
	t_point	pos;
	int		diese;
	char	map[4][4];

	pos.x = 0;
	pos.y = 0;
	diese = 0;
	while (*str)
	{
		if ((*str != '.' && *str != '#' && pos.x < 4 && pos.y < 4)
			|| (*str == '\n' && pos.x != 4 && pos.y != 4)
			|| (*str != '\n' && pos.y == 4 && pos.x == 0))
			return (NULL);
		*str == '#' ? diese++ : (void)diese;
		if (*str == '.' || *str == '#')
			map[pos.y][pos.x] = *str;
		else if (*str == '\n' && pos.x == 4)
		{
			pos.y++;
			pos.x = -1;
		}
		pos.x++;
		str++;
	}
	return (diese == 4 ? tetri_maker(map, pos, 0) : NULL);
}

t_tritab		*file_checker(int fd, t_tritab *tetris)
{
	t_list	*file;
	int		i;

	i = 0;
	file = file_reader(fd);
	if (!(tetris->tab = (t_tri**)malloc(sizeof(t_tri*) * 26)))
		return (NULL);
	while (file)
	{
		if ((file->next == NULL && ft_strlen(file->content) != 20)
			|| (file->next != NULL && ft_strlen(file->content) != 21))
			return (NULL);
		tetris->tab[i] = content_checker((char*)(file->content));
		if (tetris->tab[i] == NULL)
			return (NULL);
		i++;
		tetris->nb++;
		file = file->next;
	}
	return (tetris->nb ? tetris : NULL);
}
