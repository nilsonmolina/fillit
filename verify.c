/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 12:40:28 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/19 21:49:52 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

void	print_chunk(char *chunk, int *piece)
{
	int i;

	i = 0;
	while (piece[i])
		printf("%d ", piece[i++]);
	printf("%s", "\n");
	i = 0;
	while (chunk[i])
	{
		printf("%c", chunk[i++]);
	}
}

int		scan_file(char *file, int pos[26][4])
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
		if (!scan_chunk(buffer, pos[i]))
			return (0);
		print_chunk(buffer, pos[i]);
		if (!verify_tetrimino(pos[i]))
			return (0);
		i++;
	}
	close(fd);
	return (1);
}

int		scan_chunk(char *chunk, int *piece)
{
	COUNTER_VARS;
	while (chunk[i])
	{
		if (!(IS_VALID_CHAR(chunk[i])))
			return (0);
		if (chunk[i] == '#')
			piece[tiles++] = i + 1 - y;
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
	if (tiles < 4)
		return (0);
	if (i != BUF_SIZE)
		return (0);
	return (1);
}

int		verify_tetrimino(int *piece)
{
	if (is_square(piece) ||
		is_l(piece) ||
		is_z(piece) ||
		is_line(piece) ||
		is_t(piece))
		return (1);
	return (0);
}
