/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <mernser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:18:46 by mernser           #+#    #+#             */
/*   Updated: 2019/07/04 17:16:54 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** GNL:
** 0 DELETE PIECE
** 1 UPDATE MAP
** 1.1 SKIP GNL TILL 000 (STRDEL AND GNL)
** 1.2 UPD EACH LINE TILL map.y (GNL)
** 2 SAVE PIECE
** 2.1 find "PIECE" STR
** 2.2 MALLOC FOR PIECE
** 2.3
** main function
** skip coordinates
*/

/*
** нам нужно:
** 0. чтобы сумма координат не вылезала за пределы карты
** После этого
** 1. чтобы клетки содержали положительные чисел (суммируем их)
** или
** 2. чтобы ровна одна клетка содержала -2
** Если все условия выполнены
** 1 сохраняем сумму чисел
** 2 сохраняем координаты в put.x put.y
** в дальнейших итерациях после выполнения всех условий
** сравниваем сумму - если сумма меньше, перезаписываем координаты и сумму
** меньше или равно?
** если координаты в пределах карты
** то чекаем что там под ними
*/

void	ft_map_read(t_filler *box, char **line, int fd, int y)
{
	while ((box->gnl = get_next_line(fd, line)) > 0)
	{
		if ((ft_strstr((const char*)*line, "Plateau")))
		{
			if (ft_skip(line, fd))
				continue ;
			break ;
		}
		if ((ft_strstr((const char*)*line, "Piece")))
		{
			if (MAP != NULL)
				ft_map_prepare(box);
			ft_piece(box, line, &y, fd);
			continue ;
		}
		++y;
		if (ft_isdigit(**line) && ft_map_fill(box, line, y)
		&& ft_strdel_int(line, 1))
			continue ;
		y = -1;
		ft_strdel(line);
	}
	if (FILE)
		ft_print_map(box);
}

void	ft_map_prepare(t_filler *box)
{
	ft_map_surround(box, box->map.enemy_y, box->map.enemy_x);
	while (ft_map_surround_whole(box, box->counter, box->counter + 1))
		box->counter++;
	ft_zero_to_max(box, box->counter);
	box->counter = 1;
}

void	ft_piece(t_filler *box, char **line, int *y, int fd)
{
	ft_piece_create(line, box);
	ft_piece_save(line, box, fd);
	*y = -1;
	ft_put_piece(box, -1, -1, 0);
	box->put.sum = 2000;
	ft_write_stdout(box);
	ft_crash_piece(box, Y);
	ft_crash_piece_coordinates(box);
}

void	ft_zero_to_max(t_filler *box, int max)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < box->map.y)
	{
		while (++x < box->map.x)
		{
			if (MAP[y][x] == 0)
				MAP[y][x] = max;
		}
		x = -1;
	}
}

int		ft_skip(char **line, int fd)
{
	ft_strdel(line);
	if ((get_next_line(fd, line) == -1))
		return (0);
	ft_strdel(line);
	return (1);
}
