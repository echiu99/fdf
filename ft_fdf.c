/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:34:49 by echiu             #+#    #+#             */
/*   Updated: 2024/04/24 16:38:44 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdint.h>

int	read_keys(int keysym, t_data *data);

# define FDF_ZOOM_WHEEL_STEP 1.1

#ifdef __APPLE__
# define KEY_ESC MLX_KEY_ESCAPE
# define KEY_UP MLX_KEY_UP
# define KEY_DOWN MLX_KEY_DOWN
# define KEY_A MLX_KEY_A
# define KEY_D MLX_KEY_D
# define KEY_W MLX_KEY_W
# define KEY_S MLX_KEY_S
#else
# define KEY_ESC XK_Escape
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_A 97
# define KEY_D 100
# define KEY_W 119
# define KEY_S 115
#endif

#ifdef __APPLE__
void	read_keys_mac(mlx_key_data_t keydata, void *param)
{
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		read_keys((int)keydata.key, (t_data *)param);
}

void	close_event_mac(void *param)
{
	close_win((t_data *)param, 0);
}

void	scroll_hook_mac(double xdelta, double ydelta, void *param)
{
	t_data		*data;
	int32_t		mx;
	int32_t		my;

	(void)xdelta;
	data = (t_data *)param;
	if (ydelta == 0.0)
		return ;
	mlx_get_mouse_pos((mlx_t *)data->mlx_ptr, &mx, &my);
	if (ydelta > 0.0)
		ft_zoom_at(data, (int)mx, (int)my, FDF_ZOOM_WHEEL_STEP);
	else
		ft_zoom_at(data, (int)mx, (int)my, 1.0 / FDF_ZOOM_WHEEL_STEP);
}
#endif

#ifndef __APPLE__
/*
 * X11: buttons 4 / 5 are vertical wheel (typical Linux minilibx).
 */
int	mouse_hook_linux(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (button == 4)
		ft_zoom_at(data, x, y, FDF_ZOOM_WHEEL_STEP);
	else if (button == 5)
		ft_zoom_at(data, x, y, 1.0 / FDF_ZOOM_WHEEL_STEP);
	return (0);
}
#endif

int	read_keys(int keysym, t_data *data)
{
	if (keysym == KEY_ESC)
		close_win(data, 0);
	else if (keysym == KEY_DOWN)
		scale_down(data);
	else if (keysym == KEY_UP)
		scale_up(data);
	else if (keysym == KEY_A)
		translate_left(data);
	else if (keysym == KEY_D)
		translate_right(data);
	else if (keysym == KEY_W)
		translate_up(data);
	else if (keysym == KEY_S)
		translate_down(data);
	return (0);
}

void	init_mapdata(t_data *data, char *map_path)
{
	data->size = 0;
	data->r = 0;
	data->c = 0;
	ft_get_map(map_path, data);
	ft_compute_z_range(data);
	ft_real_coords(data);
	data->scale = 50;
	ft_concoords(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Map has not been supplied correctly\n");
		return (0);
	}
	init_mlxdata(&data);
	init_mapdata(&data, argv[1]);
	ft_clear_img(&data);
	ft_placelines(&data);
#ifndef __APPLE__
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_hook(data.win_ptr, 17, 0, close_event, &data);
	mlx_key_hook(data.win_ptr, read_keys, &data);
	mlx_mouse_hook(data.win_ptr, mouse_hook_linux, &data);
#else
	mlx_key_hook((mlx_t *)data.mlx_ptr, read_keys_mac, &data);
	mlx_close_hook((mlx_t *)data.mlx_ptr, close_event_mac, &data);
	mlx_scroll_hook((mlx_t *)data.mlx_ptr, scroll_hook_mac, &data);
#endif
	mlx_loop(data.mlx_ptr);
}
