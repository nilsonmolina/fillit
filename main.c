/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 12:35:59 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/18 19:59:38 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

int		main(int argc, char **argv)
{
	int pos[26][4];
	
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input_file");
		return (1);
	}
	if (!(scan_file(argv[1], pos)))
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int		counter;

	counter = 0;
	while (str[counter])
		counter++;
	write(1, str, counter);
}
