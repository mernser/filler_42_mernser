/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <mernser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:43:56 by mernser           #+#    #+#             */
/*   Updated: 2019/07/04 17:21:21 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** put line and fills array
** also finds top left figure piece
** enemy.x and enemy.y
** ACTUALLY WE DONT CARE WHERE NEW FIGURE IS PLACED
** SO WE PUT ALL LOWERCASE TO UPPERCASE o to O or x to X
** line 35
** FOUND STARTING POS AND THEM JUST FILL MAP
** !!!WE DONT NEED TO PUT OUR CHAR TO UPPER SINCE WE RECIEVE OURS AS UPPERCASE
*/
/*
** CHOOSE SIDE PLAYER AND SAVE NAMES OF PLAYER
** if mernser.filler p1 - O and o piece
** if mernser.filler p2 - X and x piece
**
** p1:
** O - 79
** o - 111 last piece placed
**
** p2:
** X - 88
** x - 120
*/

/*
** Convert map
** dots - to zeros '.' -> 0
** enemy char - to ENEMY_CHAR -> -1
** my char -> -2
** -1 >> -3
*/

/*
** Second func needed to avoid if statment
*/

int		ft_map_fill(t_filler *box, char **line, int y)
{
	int		i;
	char	a;

	a = (char)box->map.enemy_char + 32;
	i = -1;
	if (y >= box->map.y)
		return (0);
	while (++i < box->map.x)
	{
		if ((*line)[i + 4] == '.')
			MAP[y][i] = 0;
		else if ((*line)[i + 4] == box->map.enemy_char || (*line)[i + 4] == a)
		{
			MAP[y][i] = -1;
			box->map.enemy_x = i;
			box->map.enemy_y = y;
			break ;
		}
		else
			MAP[y][i] = -2;
	}
	ft_map_fill_sub(box, line, y, i);
	return (1);
}

void	ft_map_fill_sub(t_filler *box, char **line, int y, int i)
{
	char	a;

	a = (char)box->map.enemy_char + 32;
	while (++i < box->map.x)
	{
		if ((*line)[i + 4] == '.')
			MAP[y][i] = 0;
		else if ((*line)[i + 4] == box->map.enemy_char || (*line)[i + 4] == a)
			MAP[y][i] = -1;
		else
			MAP[y][i] = -2;
	}
}

/*
** CLEARS **MAP i - NULL POINTER POS
*/

int		ft_crash_map(t_filler *box, int i)
{
	int		c;

	c = -1;
	if (box->map.map == NULL)
		return (0);
	while (++c < i)
	{
		free(box->map.map[c]);
		box->map.map[c] = NULL;
	}
	free(box->map.map);
	box->map.map = NULL;
	return (0);
}

/*
** ALLOCATES **MAP
*/

int		ft_map_allocate(t_filler *box)
{
	int		i;

	i = -1;
	if (!(box->map.map = (int**)malloc(sizeof(int*) * (box->map.y + 1))))
		return (0);
	while (++i < box->map.y)
	{
		if (!(box->map.map[i] = (int*)malloc(sizeof(int) * box->map.x)))
			return (ft_crash_map(box, i));
	}
	box->map.map[i] = NULL;
	return (1);
}

/*
** LOOKING FOR x AND y coordintaes to create a map
*/

int		ft_map_create(char **line, t_filler *box, int fd)
{
	int		i;

	i = -1;
	if (*line == NULL)
		return (0);
	while ((*line)[++i] != '\0')
		if (ft_isdigit((int)(*line)[i]))
		{
			box->map.y = ft_atoi(&(*line)[i]);
			while (ft_isdigit((int)(*line)[i]))
				i++;
			if ((*line)[i] == ' ')
				i++;
			else
				return (ft_strdel_int(line, 0));
			box->map.x = ft_atoi(&(*line)[i]);
			ft_strdel(line);
			if (box->map.x > 0 && box->map.y > 0)
				if (!(ft_map_allocate(box)))
					return (0);
			if (!(ft_skip(line, fd)))
				return ((ft_crash_map(box, box->map.y)));
			return (1);
		}
	return (0);
}
