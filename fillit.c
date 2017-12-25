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

int		fillit_tet(t_map *map, t_tet *tet, int ok)
{
	int		i;
	int		j;

	i = 0;
	while (++i < 4)
	{
		j = tet->deltas[i] - tet->deltas[i - 1];
		map->z[j] = (ok ? tet->c : '.');
	}
	return (ok ? 1 : 0);
}

int		fillit_look(t_map *map, t_tet *tet)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < map->size)
	{
		// check wall?
	}
	j = 0;
	while (++j < 4)
	{
		k = tet->deltas[j] - tet->deltas[j - 1];
	}
	return (map != NULL && tet != NULL);
	//return (0);
}

int		fillit_ok(t_map *map, t_tet *tet)
{
	return (map != NULL && tet != NULL);
	//return (0);
}

int		fillit_go(t_map *map, int i)
{
	t_tet	*tet;
	int ok;

	tet = &map->tets[i];

	if (fillit_look(map, tet))
	{
		ok = fillit_ok(map, tet);
		if (fillit_tet(map, tet, ok))
		{
			/*
			if (fillit_go(map, i + 1))
				return (1);
			else
				fillit_tet(map, tet, !ok);
			*/
		}
	}
	return (1);
	//return (0);
}
