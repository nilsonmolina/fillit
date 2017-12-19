/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:30:02 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/19 13:57:00 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define IS_VALID_CHAR(x) (x == '.' || x == '#' || x == '\n')
# define BUF_SIZE 21
# define COUNTER_VARS int i = 0; int x = 0; int y = 0; int tiles = 0;

void			ft_putstr(char *str);
int				scan_file(char *file, int pos[26][4]);
int				scan_chunk(char *chunk, int *piece);
int				verify_tetrimino(int *piece);

int				is_square(int *tet);
int				is_line(int *tet);
int				is_t(int *tet);
int				is_z(int *tet);
int				is_l(int *tet);

void			print_chunk(char *chunk, int *piece);

#endif