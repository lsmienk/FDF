/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 11:42:30 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/10 17:29:17 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		initmapsettings(t_map *map)
{
	map->zoom = 10;
	map->rotation.x = 1.5708;
	map->rotation.y = 0;
	map->rotation.z = 0;
	map->transform.x = 500;
	map->transform.y = 0;
	map->transform.z = 320;
	map->projection = normalproject;
	map->ymulti = -1;
	setrotmatrix(map);
}

static void		freeelem(void *content, size_t content_size)
{
	ft_strdel((char**)(&content));
	content = NULL;
	content_size = 0;
}

static int		setupprogram(t_mlx *mlx, char *str)
{
	int		tmp;
	int		fd;
	t_list	*list;

	tmp = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (-1);
	list = readfile(fd);
	if (!list || !validate(list))
	{
		close(fd);
		return (-1);
	}
	close(fd);
	mlx->img = mlx_new_image(mlx->info, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->img_add = mlx_get_data_addr(mlx->img, &tmp, &tmp, &tmp);
	mlx->map = (t_map *)ft_memalloc(sizeof(t_map));
	if (!convertfile(mlx->map, list))
		return (0);
	initmapsettings(mlx->map);
	ft_lstdel(&list, freeelem);
	hookcontrols(mlx);
	mlx_loop_hook(mlx->info, fdfloop, (void *)mlx);
	return (1);
}

int				main(int argc, char **argv)
{
	t_mlx mlx;

	if (argc == 2)
	{
		mlx.info = mlx_init();
		mlx.win = mlx_new_window(mlx.info, SCREEN_WIDTH, SCREEN_HEIGHT,
			"The Bestest fTf in the worlds.");
		if (setupprogram(&mlx, argv[1]) == 1)
			mlx_loop(mlx.info);
		else
		{
			ft_putendl("Invalid File");
			exit(0);
		}
	}
	else
		ft_putendl("Usage : ./fdf [Valid Heightmap File]");
	return (0);
}
