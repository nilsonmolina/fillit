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

void	fillit(t_tet tets)
{
	char	*square;
	int		size;

	size = 2;
	square = (char *)malloc(sizeof(char *) * 2);
	square = generate_square(square, size);
	print_square(square, size);
	tets.count = 0;
}

char	*generate_square(char *square, int size)
{
	char	*new;
	int 	i;

	i = 0;
	size = size * size;
	if (square)
		free(square);
	new = (char *)malloc(sizeof(char *) * (size + 1));
	while (i < size)
		new[i] = '.';
	new[i] = '\0';
	return (new);
}

void	print_square(char *square, int size)
{
	int i;

	i = 0;
	while (square[i])
	{
		write(1, &square[i], 1);
		if ((i + 1) % size == 0)
			write(1, "\n", 1);
		i++;
	}
}

//int		is_viable_position(char *square, int *tet, int tet_count)
