/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <mernser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:16:40 by mernser           #+#    #+#             */
/*   Updated: 2019/07/04 17:16:43 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_piece_save(char **line, t_filler *box, int fd)
{
	int	i;
	int	c;

	i = -1;
	c = -1;
	box->piece.sum = 0;
	while (++c < Y && (box->gnl = get_next_line(fd, line)) > 0)
	{
		while (++i < X)
		{
			box->piece.piece[c][i] = (*line)[i];
			if (box->piece.piece[c][i] == '*')
				box->piece.sum++;
		}
		i = -1;
		ft_strdel(line);
	}
	if (box->gnl < 0)
		return (0);
	if (!(ft_piece_coordintes(box)))
		return (0);
	return (1);
}

int	ft_piece_coordintes(t_filler *box)
{
	int i;
	int c;
	int	z;

	z = -1;
	i = -1;
	c = -1;
	if (box->piece.sum == 0)
		return (1);
	if (!(box->piece.x = (int*)malloc(sizeof(int) * box->piece.sum)))
		return (0);
	if (!(box->piece.y = (int*)malloc(sizeof(int) * box->piece.sum)))
		return (ft_arrdel(&(box->piece.x), 0));
	while (++c < Y)
	{
		while (++i < X)
			if (box->piece.piece[c][i] == '*')
			{
				z++;
				box->piece.x[z] = i;
				box->piece.y[z] = c;
			}
		i = -1;
	}
	return (1);
}

int	ft_piece_create(char **line, t_filler *box)
{
	int	i;

	i = -1;
	while ((*line)[++i] != '\0')
		if (ft_isdigit((int)(*line)[i]))
		{
			Y = ft_atoi(&(*line)[i]);
			while (ft_isdigit((int)(*line)[i]))
				i++;
			if ((*line)[i] == ' ')
				i++;
			else
				return (ft_strdel_int(line, 0));
			X = ft_atoi(&(*line)[i]);
			ft_strdel(line);
			if (X > 0 && Y > 0)
				if (!(ft_piece_allocate(box)))
					return (0);
			return (1);
		}
	return (0);
}

int	ft_piece_allocate(t_filler *box)
{
	int	i;

	i = -1;
	if (!(box->piece.piece = (int**)malloc(sizeof(int*) * (Y + 1))))
		return (0);
	while (++i < Y)
	{
		if (!(box->piece.piece[i] = (int*)malloc(sizeof(int) * X)))
			return (ft_crash_piece(box, i));
	}
	box->piece.piece[i] = NULL;
	return (1);
}
