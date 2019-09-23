/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <mernser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:48:16 by mernser           #+#    #+#             */
/*   Updated: 2019/07/04 17:06:33 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# define X box->piece.width
# define Y box->piece.height
# define MAP box->map.map
# define ME -2
# define ENEMY -3
# define FILE 0
# define FITS_MAP_X x + box->piece.x[i] < box->map.x
# define FITS_MAP_Y y + box->piece.y[i] < box->map.y

typedef struct	s_map
{
	int		x;
	int		y;
	int		**map;
	int		enemy_y;
	int		enemy_x;
	int		enemy_char;
	int		my_char;
}				t_map;

typedef struct	s_piece
{
	int		width;
	int		height;
	int		sum;
	int		*x;
	int		*y;
	int		**piece;
}				t_piece;

typedef struct	s_put
{
	int		x;
	int		y;
	int		sum;
}				t_put;

typedef struct	s_filler
{
	char	*p1;
	char	*p2;
	t_map	map;
	t_piece	piece;
	t_put	put;
	int		gnl;
	int		counter;
	int		score_x;
	int		score_y;
}				t_filler;

int				ft_find_player(char **line, int fd, t_filler *box);
void			ft_init(char **line, t_filler *box);
int				ft_crash_map(t_filler *box, int i);
int				ft_map_allocate(t_filler *box);
int				ft_map_create(char **line, t_filler *box, int fd);
void			ft_map_read(t_filler *box, char **line, int fd, int y);
int				ft_map_fill(t_filler *box, char **line, int y);
void			ft_map_fill_sub(t_filler *box, char **line, int y, int i);
void			ft_player(t_filler *box);
int				ft_player_free(t_filler *box);
int				ft_strdel_int(char **as, int ret);
int				ft_skip(char **line, int fd);
int				ft_piece_allocate(t_filler *box);
int				ft_piece_create(char **line, t_filler *box);
int				ft_piece_save(char **line, t_filler *box, int fd);
int				ft_crash_piece(t_filler *box, int i);
int				ft_piece_coordintes(t_filler *box);
int				ft_arrdel(int **as, int ret);
int				ft_crash_piece_coordinates(t_filler *box);
int				ft_map_surround(t_filler *box, int y, int x);
int				ft_map_transform(t_filler *box, int x, int y);
int				ft_map_surround_whole(t_filler *box, int i, int next);
void			ft_check_surroundings(t_filler *box, int next, int y, int x);
void			ft_print_map(t_filler *box);
void			ft_print_piece(t_filler *box, int num);
void			ft_put_piece(t_filler *box, int x, int y, int sum);
void			ft_write_stdout(t_filler *box);
void			ft_zero_to_max(t_filler *box, int max);
void			ft_piece(t_filler *box, char **line, int *y, int fd);
void			ft_is_new_pos(t_filler *box, int x, int y, int sum);
void			ft_map_prepare(t_filler *box);
void			ft_init_param(int *sum, int *c, int *i);
void			ft_upper(t_filler *box, int y, int x);
void			ft_under(t_filler *box, int y, int x);

#endif
