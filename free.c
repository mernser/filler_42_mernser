/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <mernser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:03:15 by mernser           #+#    #+#             */
/*   Updated: 2019/07/04 14:10:00 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** FREE/NULL FOR x and y array of coordinates
*/

int	ft_crash_piece_coordinates(t_filler *box)
{
	if (box->piece.y != NULL)
	{
		free(box->piece.y);
		box->piece.y = NULL;
	}
	if (box->piece.x != NULL)
	{
		free(box->piece.x);
		box->piece.x = NULL;
	}
	return (1);
}

/*
** FREE/NULL FOR **piece array of shape
*/

int	ft_crash_piece(t_filler *box, int i)
{
	int	c;

	c = -1;
	if (box->piece.piece == NULL)
		return (0);
	while (++c < i)
	{
		free(box->piece.piece[c]);
		box->piece.piece[c] = NULL;
	}
	free(box->piece.piece);
	box->piece.piece = NULL;
	return (0);
}

int	ft_strdel_int(char **as, int ret)
{
	if (as == NULL || *as == NULL)
		return (ret);
	free(*as);
	*as = NULL;
	return (ret);
}

int	ft_arrdel(int **as, int ret)
{
	if (as == NULL || *as == NULL)
		return (ret);
	free(*as);
	*as = NULL;
	return (ret);
}

int	ft_player_free(t_filler *box)
{
	if (box->p1 != NULL)
	{
		free(box->p1);
		box->p1 = NULL;
	}
	if (box->p2 != NULL)
	{
		free(box->p2);
		box->p2 = NULL;
	}
	return (1);
}
