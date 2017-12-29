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

	j = 0;
	i = -1;
	/*
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
	*/
	return (map != NULL && tet != NULL);
	//return (0);
}

int		fillit_go(t_map *map, int i)
{
	t_tet	*tet;
	int j;

	tet = &map->tets[i];

	j = 0;
	while (0)
	{
		j = fillit_look(map, tet, j);
		fillit_tet(map, tet, j, 1);
		if (fillit_go(map, i + 1))
			return (1);
		fillit_tet(map, tet, j, 0);
	}
	return (1);
	//return (0);
}
