/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:30:02 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/21 23:24:27 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# define IS_VALID_CHAR(x) (x == '.' || x == '#' || x == '\n')
# define BUF_SIZE 21
# define COUNTER_VARS int i = 0; int x = 0; int y = 0; int tiles = 0;

typedef struct	s_tet
{
	int			positions[26][4];
	int			count;
}				t_tet;

void			ft_puterror(char *msg);

int				scan_file(char *file, t_tet tets);
int				scan_chunk(char *chunk, int *tet);
int				verify_tetrimino(int *tet);
int				check_edge(int *tet);
void			print_chunk(char *chunk, int *tet);

int				is_square(int *tet);
int				is_line(int *tet);
int				is_t(int *tet);
int				is_z(int *tet);
int				is_l(int *tet);

//void			fillit(t_tet tets);
//char			*generate_square(char *square, int size);
//void			print_square(char *square, int size);		

#endif
