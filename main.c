/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 12:35:59 by nmolina           #+#    #+#             */
/*   Updated: 2018/01/01 18:06:06 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_map	map;

	map.count = 0;
	if (argc != 2)
		ft_puterror("usage: ./fillit input_file");
	if (!(scan_file(argv[1], &map) && fillit_try(&map)))
		ft_puterror("error");
	return (0);
}

void	ft_puterror(char *msg)
{
	int		counter;

	counter = 0;
	while (msg[counter])
		counter++;
	write(1, msg, counter);
	write(1, "\n", 1);
	exit(1);
}
