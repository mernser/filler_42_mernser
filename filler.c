/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <mernser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:27:46 by mernser           #+#    #+#             */
/*   Updated: 2019/07/04 16:59:32 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(int argc, char **argv)
{
	char		*line;
	int			fd;
	t_filler	box;

	fd = 0;
	if (FILE)
	{
		if (argc == 2)
			fd = open(argv[1], O_RDONLY);
		if (fd == -1 || fd == 0)
			return (1);
	}
	(void)argc;
	(void)argv;
	ft_init(&line, &box);
	if (!(ft_find_player(&line, fd, &box)) || !(ft_map_create(&line, &box, fd)))
		return (ft_player_free(&box));
	ft_map_read(&box, &line, fd, (int)-1);
	ft_crash_map(&box, box.map.y);
	ft_player_free(&box);
	return (1);
}
