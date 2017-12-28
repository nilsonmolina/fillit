/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmolina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:30:02 by nmolina           #+#    #+#             */
/*   Updated: 2017/12/22 22:04:55 by nmolina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

# define MAX 26
# define IS_VALID_CHAR(x) (x == '.' || x == '#' || x == '\n')
# define BUF_SIZE 21
# define COUNTER_VARS int i = 0; int x = 0; int y = 0; int tiles = 0;

typedef struct	s_tet
{
	int		hashes[4];
	int		deltas[4];
	int		i;
	char	c;
}				t_tet;

typedef struct	s_map
{
	int		count;
	int		size;
	//int		i;
	char	z[MAX * MAX];
	t_tet	tets[MAX];
}				t_map;

void			ft_puterror(char *msg);

int				scan_file(char *file, t_map *map);
int				scan_chunk(char *chunk, t_tet *tet);
void			diff_chunk(t_tet *tet);
int				verify_tetrimino(t_tet *tet);
int				check_edge(int *hs);

int				is_square(int *hs);
int				is_line(int *hs);
int				is_t(int *hs, int *ds);
int				is_z(int *hs, int *ds);
int				is_l(int *hs, int *ds);

int				fillit_try(t_map *map);
int				fillit_go(t_map *map, int i);
int				fillit_look(t_map *map, t_tet *tet, int j);
void			fillit_tet(t_map *map, t_tet *tet, int j, int ok);

#endif
