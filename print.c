/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <mernser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:07:51 by mernser           #+#    #+#             */
/*   Updated: 2019/07/04 16:58:35 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print_map(t_filler *box)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < box->map.y)
	{
		while (++x < box->map.x)
		{
			if (MAP[y][x] >= 0)
				ft_putnbr(MAP[y][x]);
			else if (MAP[y][x] == -2 && write(1, COLOR_BLUE, 5))
				ft_putchar(box->map.my_char);
			else if (MAP[y][x] == -3 && write(1, COLOR_RED, 5))
				ft_putchar(box->map.enemy_char);
			write(1, COLOR_RESET, 5);
			ft_putchar(' ');
		}
		ft_putchar('\n');
		x = -1;
	}
	ft_putchar('\n');
}

void	ft_print_piece(t_filler *box, int num)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < Y)
	{
		while (++x < X)
		{
			if (num)
				ft_putnbr(box->piece.piece[y][x]);
			else
				ft_putchar(box->piece.piece[y][x]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
		x = -1;
	}
	ft_putchar('\n');
}

void	ft_write_stdout(t_filler *box)
{
	ft_putnbr(box->put.y);
	write(1, " ", 1);
	ft_putnbr(box->put.x);
	write(1, "\n", 1);
	box->put.y = 0;
	box->put.x = 0;
}

/*
** Canvas for func
*/

int		ft_map_num(t_filler *box)
{
	int	x;
	int	y;
	int	i;

	i = 1;
	x = -1;
	y = -1;
	while (i)
	{
		i = 0;
		while (++y < box->map.y)
		{
			while (++x < box->map.x)
				if (MAP[y][x] == '.')
					;
			x = -1;
		}
	}
	return (1);
}
