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

#include <stdio.h>

void	print_chunk(char *chunk, int *tet)
{
	int i;

	i = 0;
	while (i < 4)
		printf("%d ", tet[i++]);
	printf("%s", "\n");
	i = 0;
	while (chunk[i])
	{
		printf("%c", chunk[i++]);
	}
}

int		scan_file(char *file, t_tet tets)
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
		if (!scan_chunk(buffer, tets.positions[i]))
			return (0);
		print_chunk(buffer, tets.positions[i]);
		if (!verify_tetrimino(tets.positions[i]))
			return (0);
		i++;
	}
	close(fd);
	tets.count = i;
	return (1);
}

int		scan_chunk(char *chunk, int *tet)
{
	COUNTER_VARS;
	while (chunk[i])
	{
		if (!(IS_VALID_CHAR(chunk[i])))
			return (0);
		if (chunk[i] == '#')
			tet[tiles++] = i + 1 - y;
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

int		verify_tetrimino(int *tet)
{
	return (check_edge(tet) &&
		(is_square(tet) ||
		is_l(tet) ||
		is_z(tet) ||
		is_line(tet) ||
		is_t(tet)));
}

int		check_edge(int *tet)
{
	if ((tet[0] + 1 == tet[1] && tet[0] % 4 == 0) ||
		(tet[1] + 1 == tet[2] && tet[1] % 4 == 0) ||
		(tet[2] + 1 == tet[3] && tet[2] % 4 == 0))
		return (0);
	return (1);
}
