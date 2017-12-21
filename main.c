/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 12:35:59 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/20 17:53:50 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tet tetriminos;

	tetriminos.count = 0;
	if (argc != 2)
		ft_puterror("usage: ./fillit input_file");
	if (!(scan_file(argv[1], tetriminos)))
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
