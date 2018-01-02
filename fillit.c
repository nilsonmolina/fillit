/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:57:45 by nmolina           #+#    #+#             */
/*   Updated: 2018/01/01 12:16:14 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fillit_try(t_map *map)
{
	int		i;

	map->size = 2;
	while (map->size < MAX)
	{
		i = 0;
		map->z[map->size * map->size] = '\0';
		while (i < map->size * map->size)
			map->z[i++] = '.';
		if (fillit_go(map, 0))
			return (fillit_out(map));
		map->size++;
	}
	return (0);
}

int		fillit_go(t_map *map, int i)
{
	t_tet	*tet;
	int		j;

	if (i == map->count)
		return (1);
	tet = &map->tets[i];
	j = -1;
	while ((j = fillit_look(map, tet, j + 1)) != -1)
	{
		fillit_tet(map, tet, j, OK);
		if (fillit_go(map, i + 1))
			return (1);
		fillit_tet(map, tet, j, !OK);
	}
	return (0);
}

int		fillit_look(t_map *map, t_tet *tet, int j)
{
	int		i;
	int		k;
	int		dk;

	while (j < map->size * map->size)
	{
		i = 0;
		k = 0;
		dk = 0;
		while (i < 4)
		{
			k += tet->deltas[i] + (i && tet->deltas[i] > 1 ? map->size - 4 : 0);
			dk = k - dk;
			if (map->z[j + k] != '.' ||
				(map->size > 2 && dk == 1 && (j + k) % map->size == 0))
				break ;
			if (++i == 4)
				return (j);
			dk = k;
		}
		j++;
	}
	return (-1);
}

void	fillit_tet(t_map *map, t_tet *tet, int j, int ok)
{
	int		i;
	int		k;

	i = -1;
	k = 0;
	while (++i < 4)
	{
		k += tet->deltas[i] + (i && tet->deltas[i] > 1 ? map->size - 4 : 0);
		map->z[j + k] = (ok ? tet->c : '.');
	}
}

int		fillit_out(t_map *map)
{
	int i;

	i = 0;
	while (i < (map->size * map->size))
	{
		if (i != 0 && i % map->size == 0)
			write(1, "\n", 1);
		write(1, &map->z[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (1);
}
