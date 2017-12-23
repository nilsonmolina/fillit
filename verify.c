/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 12:40:28 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/21 23:24:21 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//
#include <stdio.h>
//

void	print_chunk(char *chunk, t_tet *tet)
{
	int i;

	i = 0;
	while (i < 4)
		printf("%d ", tet->hashes[i++]);
	printf("%s", "\n");
	i = 0;
	while (chunk[i])
		printf("%c", chunk[i++]);
}

int		scan_file(char *file, t_map *map)
{
	int		fd;
	int		ret;
	char	buffer[BUF_SIZE];
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buffer, BUF_SIZE)))
	{
		if (i > 25)
			return (0);
		if (!scan_chunk(buffer, &map->tets[i]))
			return (0);
		print_chunk(buffer, &map->tets[i]);
		diff_chunk(&map->tets[i]);
		if (!verify_tetrimino(&map->tets[i]))
			return (0);
		i++;
	}
	close(fd);
	map->count = i;
	return (1);
}

int		scan_chunk(char *chunk, t_tet *tet)
{
	COUNTER_VARS;
	while (chunk[i])
	{
		if (!(IS_VALID_CHAR(chunk[i])))
			return (0);
		if (chunk[i] == '#')
			tet->hashes[tiles++] = i + 1 - y;
		if (chunk[i] == '#' && tiles > 4)
			return (0);
		if (chunk[i] == '\n')
		{
			y++;
			if (x != 4 && y != 5)
				return (0);
			x = 0;
		}
		else
			x++;
		i++;
	}
	if (tiles != 4)
		return (0);
	if (i != BUF_SIZE)
		return (0);
	return (1);
}

void	diff_chunk(t_tet *tet)
{
	int		i;

	tet->deltas[0] = 0;
	i = 0;
	while (++i < 4)
		tet->deltas[i] = tet->hashes[i] - tet->hashes[i - 1];
}

int		verify_tetrimino(t_tet *tet)
{
	return (check_edge(tet->hashes) &&
		(is_square(tet->hashes) ||
		is_l(tet->hashes) ||
		is_z(tet->hashes) ||
		is_line(tet->hashes) ||
		is_t(tet->hashes)));
}

int		check_edge(int *tet)
{
	if ((tet[0] + 1 == tet[1] && tet[0] % 4 == 0) ||
		(tet[1] + 1 == tet[2] && tet[1] % 4 == 0) ||
		(tet[2] + 1 == tet[3] && tet[2] % 4 == 0))
		return (0);
	return (1);
}
