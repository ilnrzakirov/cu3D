#include "../../include/cub3d.h"

void	ft_pixel_put(int y, int x, t_data *data, unsigned int color)
{
	int i = -1, j = 0;
	while (++i < 31)
	{
		j = -1;
		while (++j < 31)
			mlx_pixel_put(data->mlx, data->win, x + i, y + j, (int)color);
	}
}

void	draw_map(t_data *data)
{
	int x, y = -1;

	while (++y < size_arr(data->map->map))
	{
		x = -1;
		while (++x < ft_strlen(data->map->map[y]))
		{
			if ((ft_strchr("1", data->map->map[y][x])))
				ft_pixel_put(y * 30, x * 30, data, 0xFFFFFF);
			else if ((ft_strchr("NSEW", data->map->map[y][x])))
				ft_pixel_put(y * 30, x * 30, data, 0xFF69B4);
		}
	}
}

int	game_close(t_data *data)
{
	clear_and_exit(data);
	return (0);
}

static int	press_key(int key, t_data *data)
{
	data->active_key[key] = 1;
	return (0);
}

int	unpress_key(int key, t_data *data)
{
	data->active_key[key] = 0;
	return (0);
}

void	game_hook(t_data *data)
{
	mlx_hook(data->win, 17, 0, game_close, data);
	mlx_hook(data->win, 2, 1L << 0, press_key, data);
	mlx_hook(data->win, 3, 1L << 0, unpress_key, data);
}

void	player_up_down(double x, double y, t_data *data)
{
	if (data->active_key[13] == 1) {
		if (data->map->map[(int) data->ply->y][(int) (data->ply->x + x)] == '0')
			data->ply->x = data->ply->x + x;
		if (data->map->map[(int)(data->ply->y + y)][(int)data->ply->x] == '0')
			data->ply->y = data->ply->y + y;
	}
	else if (data->active_key[1] == 1)
	{
		if (data->map->map[(int) data->ply->y][(int) (data->ply->x - x)] == '0')
			data->ply->x = data->ply->x - x;
		if (data->map->map[(int)(data->ply->y - y)][(int)data->ply->x] == '0')
			data->ply->y = data->ply->y - y;
	}
}

void	get_coordinates(t_data *data)
{
	double x;
	double y;

	x = data->ply->move_k * cos(data->ply->angle * PI / 180);
	y = data->ply->move_k * sin(data->ply->angle * PI / 180);
	player_up_down(x, y, data);
//	player_left_right(x, y, data);
}

int	render(t_data *data)
{
	if (data->active_key[53] == 1)
		clear_and_exit(data);
	get_coordinates(data);
	return (0);
}

void	run_game(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 640, 480, "cub3D");
	game_hook(data);
	mlx_loop_hook(data->mlx, &render, data);
	draw_map(data);
	mlx_loop(data->mlx);
}