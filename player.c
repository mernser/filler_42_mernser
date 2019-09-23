/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <mernser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:10:24 by mernser           #+#    #+#             */
/*   Updated: 2019/07/04 14:38:46 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** CHOOSE PLAYER SYMBOL
** if mernser.filler p1 - O piece
**
** if mernser.filler p2 - X piece
*/

void	ft_player(t_filler *box)
{
	if (box->p1 != NULL)
	{
		if (ft_strstr((const char *)box->p1, "mernser.filler") != NULL)
		{
			box->map.my_char = 'O';
			box->map.enemy_char = 'X';
		}
	}
	else if (box->p2 != NULL)
	{
		if (ft_strstr((const char *)box->p2, "mernser.filler") != NULL)
		{
			box->map.my_char = 'X';
			box->map.enemy_char = 'O';
		}
		else
		{
			box->map.my_char = 'O';
			box->map.enemy_char = 'X';
		}
	}
}

/*
** CHOOSE SIDE PLAYER AND SAVE NAMES OF PLAYER
** if mernser.filler p1 - O and o piece
** if mernser.filler p2 - X and x piece
**
** p1:
** O - 79
** o - 111 - last piece placed
**
** p2:
** X - 88
** x - 120 - last piece placed
*/

int		ft_save_player(char **line, t_filler *box)
{
	char	*player;
	char	*nickname;

	player = NULL;
	nickname = NULL;
	player = ft_strchr((const char*)*line, 'p');
	nickname = ft_strchr((const char*)*line, '[');
	if (!(player) || !(nickname))
		return (0);
	nickname++;
	if (*(player + 1) == '1')
	{
		if (!(box->p1 = ft_strsub(nickname, 0, ft_str_charpos(nickname, ']'))))
			return (0);
	}
	else if (*(player + 1) == '2')
	{
		if (!(box->p2 = ft_strsub(nickname, 0, ft_str_charpos(nickname, ']'))))
			return (0);
	}
	else
		return (0);
	return (1);
}

int		ft_find_player(char **line, int fd, t_filler *box)
{
	int		gnl;
	char	*needle;

	needle = NULL;
	while ((gnl = get_next_line(fd, line) > 0))
	{
		if ((needle = ft_strstr((const char*)*line, "$$$")))
		{
			if (!(ft_save_player(line, box)))
				return (ft_strdel_int(line, 0));
		}
		else if ((needle = ft_strstr((const char*)*line, "Plateau")))
			break ;
		ft_strdel(line);
		needle = NULL;
	}
	if (gnl == -2 || gnl == 0)
		return (0);
	if (gnl == -1 || (needle != NULL && gnl == 0))
		return (ft_strdel_int(line, 0));
	ft_player(box);
	return (1);
}

void	ft_init(char **line, t_filler *box)
{
	*line = NULL;
	box->map.x = 0;
	box->map.y = 0;
	box->map.map = NULL;
	box->map.enemy_y = 0;
	box->map.enemy_x = 0;
	box->map.enemy_char = 'X';
	box->map.my_char = 'O';
	box->p1 = NULL;
	box->p2 = NULL;
	box->piece.width = 0;
	box->piece.height = 0;
	box->piece.sum = 0;
	box->piece.x = NULL;
	box->piece.y = NULL;
	box->piece.piece = NULL;
	box->put.x = 0;
	box->put.y = 0;
	box->put.sum = 1000;
	box->gnl = 0;
	box->counter = 1;
}
