/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 19:59:53 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/20 13:39:24 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_line(int *tet)
{
	if (tet[0] + 1 == tet[1] &&
		tet[1] + 1 == tet[2] &&
		tet[2] + 1 == tet[3])
		return (1);
	if (tet[0] + 4 == tet[1] &&
		tet[1] + 4 == tet[2] &&
		tet[2] + 4 == tet[3])
		return (1);
	return (0);
}

int		is_z(int *tet)
{
	if (tet[0] + 1 == tet[1] &&
		tet[1] + 4 == tet[2] &&
		tet[2] + 1 == tet[3])
		return (1);
	if (tet[0] + 3 == tet[1] &&
		tet[1] + 1 == tet[2] &&
		tet[2] + 3 == tet[3])
		return (1);
	if (tet[0] + 1 == tet[1] &&
		tet[1] + 2 == tet[2] &&
		tet[2] + 1 == tet[3])
		return (1);
	if (tet[0] + 4 == tet[1] &&
		tet[1] + 1 == tet[2] &&
		tet[2] + 4 == tet[3])
		return (1);
	return (0);
}

int		is_square(int *tet)
{
	if (tet[0] + 1 == tet[1] &&
		tet[1] + 3 == tet[2] &&
		tet[2] + 1 == tet[3])
		return (1);
	return (0);
}

int		is_t(int *tet)
{
	if (tet[0] + 4 == tet[1] &&
		tet[1] + 1 == tet[2] &&
		tet[2] + 3 == tet[3])
		return (1);
	if (tet[0] + 3 == tet[1] &&
		tet[1] + 1 == tet[2] &&
		tet[2] + 4 == tet[3])
		return (1);
	if (tet[0] + 3 == tet[1] &&
		tet[1] + 1 == tet[2] &&
		tet[2] + 1 == tet[3])
		return (1);
	if (tet[0] + 1 == tet[1] &&
		tet[1] + 1 == tet[2] &&
		tet[2] + 3 == tet[3])
		return (1);
	return (0);
}

int		is_l(int *tet)
{
	if (tet[0] + 4 == tet[1] && tet[1] + 4 == tet[2] && tet[2] + 1 == tet[3])
		return (1);
	if (tet[0] + 1 == tet[1] && tet[1] + 4 == tet[2] && tet[2] + 4 == tet[3])
		return (1);
	if (tet[0] + 2 == tet[1] && tet[1] + 1 == tet[2] && tet[2] + 1 == tet[3])
		return (1);
	if (tet[0] + 1 == tet[1] && tet[1] + 1 == tet[2] && tet[2] + 2 == tet[3])
		return (1);
	if (tet[0] + 4 == tet[1] && tet[1] + 3 == tet[2] && tet[2] + 1 == tet[3])
		return (1);
	if (tet[0] + 1 == tet[1] && tet[1] + 3 == tet[2] && tet[2] + 4 == tet[3])
		return (1);
	if (tet[0] + 4 == tet[1] && tet[1] + 1 == tet[2] && tet[2] + 1 == tet[3])
		return (1);
	if (tet[0] + 1 == tet[1] && tet[1] + 1 == tet[2] && tet[2] + 4 == tet[3])
		return (1);
	return (0);
}
