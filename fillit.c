/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:57:45 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/20 21:05:09 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int		fillit_look(t_map *map, t_tet *tet, int j)
{
	int		i;
	int		k;

	while (j < map->size * map->size)
	{
		i = 0;
		k = 0;
		while (i < 4)
		{
			k += tet->deltas[i] + (i && tet->deltas[i] > 1 ? map->size - 4 : 0);
			//if (map->z[j + k] != '.' || (map->size > 2 && (j + k) && (j + k) % map->size == 0))
			if (map->z[j + k] != '.')
				break;
			if (++i == 4)
				return (j);
		}
		j++;
	}
	return (-1);
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
		// printf
		if (fillit_go(map, i + 1))
			return (1);
		fillit_tet(map, tet, j, !OK);
	}
	return (0);
}
