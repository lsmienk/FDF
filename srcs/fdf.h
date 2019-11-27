/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 12:39:44 by lsmienk        #+#    #+#                */
/*   Updated: 2019/06/11 11:12:27 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "keycodes.h"
# include "values.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

typedef struct	s_melm
{
	int			val;
	int			colour;
}				t_melm;

typedef struct	s_rotmatrix
{
	double		a;
	double		b;
	double		c;
	double		x;
	double		y;
	double		z;
	double		i;
	double		j;
	double		k;
}				t_rotmatrix;

typedef struct	s_map
{
	t_melm		**map;
	t_point		map_size;
	int			min;
	int			max;
	t_point		rotation;
	t_rotmatrix	rotmatrix;
	t_point		transform;
	double		zoom;
	double		ymulti;
	t_point		*(*projection)(t_point *pos, t_point *offset);
}				t_map;

typedef struct	s_mlx
{
	void		*info;
	void		*win;
	void		*img;
	void		*img_add;
	t_map		*map;
}				t_mlx;

t_list			*readfile(int fd);
t_map			*convertfile(t_map *map, t_list *lst);
void			drawinfo(t_mlx *mlx, int colour);
void			hookcontrols(t_mlx *mlx);
int				closeprogram(void *param);
int				fdfloop(void *param);
int				inbounds(int x, int y);
void			plotpoint(int x, int y, int colour, void *img_add);
void			bcolour(t_mlx *mlx, int colour);
t_point			*isoproject(t_point *pos, t_point *offset);
t_point			*fisoproject(t_point *pos, t_point *offset);
t_point			*parallelproject(t_point *pos, t_point *offset);
t_point			*normalproject(t_point *pos, t_point *offset);
void			drawmap(t_map *map, t_mlx *mlx);
void			drawline(t_point *pos1, t_point *pos2,
						void *img_add, int colour);
char			**rowtoarray(char *str, t_map *map);
void			switchpos(t_point *pos1, t_point *pos2);
void			setrotmatrix(t_map *map);
t_point			*rotate(t_point *pos, t_rotmatrix *matrix,
						t_point *mapsize, double zoom);
int				validate(t_list *lst);
int				colourconvert(t_melm *current, int min, int max);
void			changeprojection(t_mlx *mlx,
					t_point *(*projection)(t_point *pos, t_point *offset),
					t_point offset);
void			resetmap(t_map *map);

#endif
