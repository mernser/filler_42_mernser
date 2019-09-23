/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <mernser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:16:22 by mernser           #+#    #+#             */
/*   Updated: 2019/07/04 17:19:49 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_put_piece(t_filler *box, int x, int y, int sum)
{
	int	i;
	int c;

	ft_init_param(&sum, &c, &i);
	while (++y < box->map.y)
	{
		while (++x < box->map.x)
		{
			while (++i < box->piece.sum && FITS_MAP_X && FITS_MAP_Y)
				if (MAP[y + box->piece.y[i]][x + box->piece.x[i]] >= 0)
					sum = sum + MAP[y + box->piece.y[i]][x + box->piece.x[i]];
				else if (MAP[y + box->piece.y[i]][x + box->piece.x[i]] == -2)
				{
					if (c++)
						break ;
				}
				else
					break ;
			if (i == box->piece.sum && c == 1)
				ft_is_new_pos(box, x, y, sum);
			ft_init_param(&sum, &c, &i);
		}
		x = -1;
	}
}

void	ft_init_param(int *sum, int *c, int *i)
{
	*sum = 0;
	*c = 0;
	*i = -1;
}

void	ft_is_new_pos(t_filler *box, int x, int y, int sum)
{
	if (sum < box->put.sum)
	{
		box->put.x = x;
		box->put.y = y;
		box->put.sum = sum;
	}
}
