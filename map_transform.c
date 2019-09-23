/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <mernser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:19:25 by mernser           #+#    #+#             */
/*   Updated: 2019/07/04 16:45:15 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** SECOND PUT REST NUMS ITERATIVE
*/

int		ft_map_surround_whole(t_filler *box, int current, int next)
{
	int	x;
	int	y;
	int	is_place;

	is_place = 0;
	x = -1;
	y = -1;
	while (++y < box->map.y)
	{
		while (++x < box->map.x)
			if (MAP[y][x] == current && ++is_place)
			{
				ft_check_surroundings(box, next, y, x);
			}
		x = -1;
	}
	return (is_place);
}

void	ft_check_surroundings(t_filler *box, int next, int y, int x)
{
	if (y - 1 > -1)
		if (MAP[y - 1][x] == 0)
			MAP[y - 1][x] = next;
	if (x + 1 < box->map.x)
		if (MAP[y][x + 1] == 0)
			MAP[y][x + 1] = next;
	if (y + 1 < box->map.y)
		if (MAP[y + 1][x] == 0)
			MAP[y + 1][x] = next;
	if (x - 1 > -1)
		if (MAP[y][x - 1] == 0)
			MAP[y][x - 1] = next;
}

/*
** FIRST PUT ALL 1 AROUND FIGURE RECURSIVE
*/

int		ft_map_surround(t_filler *box, int y, int x)
{
	if (MAP[y][x] != -1)
		return (0);
	MAP[y][x] = -3;
	if (y - 1 > -1)
		ft_upper(box, y, x);
	if (x + 1 < box->map.x)
	{
		if (MAP[y][x + 1] == 0)
			MAP[y][x + 1] = 1;
		else if (MAP[y][x + 1] == -1)
			ft_map_surround(box, y, x + 1);
	}
	if (y + 1 < box->map.y)
		ft_under(box, y, x);
	if (x - 1 > -1)
	{
		if (MAP[y][x - 1] == 0)
			MAP[y][x - 1] = 1;
		else if (MAP[y][x - 1] == -1)
			ft_map_surround(box, y, x - 1);
	}
	return (1);
}

void	ft_under(t_filler *box, int y, int x)
{
	if (MAP[y + 1][x] == 0)
		MAP[y + 1][x] = 1;
	else if (MAP[y + 1][x] == -1)
		ft_map_surround(box, y + 1, x);
	if (x - 1 > -1)
	{
		if (MAP[y + 1][x - 1] == 0)
			MAP[y + 1][x - 1] = 1;
		else if (MAP[y + 1][x - 1] == -1)
			ft_map_surround(box, y + 1, x - 1);
	}
	if (x + 1 < box->map.x)
	{
		if (MAP[y + 1][x + 1] == 0)
			MAP[y + 1][x + 1] = 1;
		else if (MAP[y + 1][x + 1] == -1)
			ft_map_surround(box, y + 1, x + 1);
	}
}

void	ft_upper(t_filler *box, int y, int x)
{
	if (MAP[y - 1][x] == 0)
		MAP[y - 1][x] = 1;
	else if (MAP[y - 1][x] == -1)
		ft_map_surround(box, y - 1, x);
	if (x + 1 < box->map.x)
	{
		if (MAP[y - 1][x + 1] == 0)
			MAP[y - 1][x + 1] = 1;
		else if (MAP[y - 1][x + 1] == -1)
			ft_map_surround(box, y - 1, x + 1);
	}
	if (x - 1 > -1)
	{
		if (MAP[y - 1][x - 1] == 0)
			MAP[y - 1][x - 1] = 1;
		else if (MAP[y - 1][x - 1])
			ft_map_surround(box, y - 1, x - 1);
	}
}
