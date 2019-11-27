/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hookcontrols.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 13:44:15 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/28 11:37:51 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	swapprojection(t_mlx *mlx)
{
	if (mlx->map->projection == normalproject)
		changeprojection(mlx, isoproject, (t_point){200, -300, 320});
	else if (mlx->map->projection == isoproject)
		changeprojection(mlx, fisoproject, (t_point){200, -300, 320});
	else if (mlx->map->projection == fisoproject)
		changeprojection(mlx, parallelproject, (t_point){160, 0, 320});
	else if (mlx->map->projection == parallelproject)
		changeprojection(mlx, normalproject, (t_point){500, 0, 320});
}

static void	rotatecontroller(int key, t_mlx *mlx)
{
	if (key == KEY_R)
		resetmap(mlx->map);
	else if (key == KEY_LEFT)
		mlx->map->rotation.x += ROT_AMOUNT;
	else if (key == KEY_RIGHT)
		mlx->map->rotation.x -= ROT_AMOUNT;
	else if (key == KEY_UP)
		mlx->map->rotation.y += ROT_AMOUNT;
	else if (key == KEY_DOWN)
		mlx->map->rotation.y -= ROT_AMOUNT;
	else if (key == KEY_PGUP)
		mlx->map->rotation.z += ROT_AMOUNT;
	else if (key == KEY_PGDOWN)
		mlx->map->rotation.z -= ROT_AMOUNT;
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP
		|| key == KEY_DOWN || key == KEY_PGUP || key == KEY_PGDOWN)
		setrotmatrix(mlx->map);
}

static int	keycontroller(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	if (key == KEY_ESC)
		closeprogram(param);
	else if (key == KEY_A)
		mlx->map->transform.x -= TRANS_AMOUNT;
	else if (key == KEY_D)
		mlx->map->transform.x += TRANS_AMOUNT;
	else if (key == KEY_W)
		mlx->map->transform.z -= TRANS_AMOUNT;
	else if (key == KEY_S)
		mlx->map->transform.z += TRANS_AMOUNT;
	else if (key == KEY_Z)
		mlx->map->transform.y += TRANS_AMOUNT;
	else if (key == KEY_X)
		mlx->map->transform.y -= TRANS_AMOUNT;
	else if (key == KEY_P)
		swapprojection(mlx);
	else if (key == KEY_MINUS)
		mlx->map->ymulti += 1;
	else if (key == KEY_PLUS)
		mlx->map->ymulti -= 1;
	rotatecontroller(key, mlx);
	return (0);
}

static int	mousezoom(int button, int x, int y, void *param)
{
	t_mlx *mlx;

	x -= y;
	mlx = (t_mlx*)param;
	if (button == 4 && mlx->map->zoom < 411)
		mlx->map->zoom *= 1.1;
	else if (button == 5 && mlx->map->zoom > 1.5)
		mlx->map->zoom /= 1.1;
	return (0);
}

void		hookcontrols(t_mlx *mlx)
{
	mlx_hook(mlx->win, KEY_PRESS_EVENT, NULL_MASK, keycontroller, (void*)mlx);
	mlx_hook(mlx->win, CLOSE_EVENT, NULL_MASK, closeprogram, NULL);
	mlx_mouse_hook(mlx->win, mousezoom, mlx);
}
