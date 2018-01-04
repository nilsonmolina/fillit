/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:57:45 by nmolina           #+#    #+#             */
/*   Updated: 2018/01/04 15:13:23 by ndoorn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		//
		fillit_out(map);
		//
		if (fillit_go(map, i + 1))
			return (1);
		fillit_tet(map, tet, j, !OK);
		//
		fillit_out(map);
		//
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
			dk = k;
			k += tet->deltas[i] + (i && tet->deltas[i] > 1 ? map->size - 4 : 0);
			dk = k - dk;
			if ((map->z[j + k] != '.') ||
				((map->size == 2 && !is_square(tet->hashes)) ||
				(map->size == 3 && is_line(tet->hashes))) ||
				(map->size == 3 && i && tet->deltas[i] != 2 &&
				dk == 1 && (j + k) % map->size == 0) ||
				((map->size > 3 && dk == 1 && (j + k) % map->size == 0)))
				break ;
			if (++i == 4)
				return (j);
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
