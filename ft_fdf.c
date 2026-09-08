/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:34:49 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 18:00:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#ifdef __APPLE__
# define KEY_ESC MLX_KEY_ESCAPE
# define KEY_UP MLX_KEY_UP
# define KEY_DOWN MLX_KEY_DOWN
# define KEY_LEFT MLX_KEY_LEFT
# define KEY_RIGHT MLX_KEY_RIGHT
# define KEY_A MLX_KEY_A
# define KEY_D MLX_KEY_D
# define KEY_W MLX_KEY_W
# define KEY_S MLX_KEY_S
# define KEY_Q MLX_KEY_Q
# define KEY_E MLX_KEY_E
# define KEY_R MLX_KEY_R
# define KEY_O MLX_KEY_O
# define KEY_C MLX_KEY_C
# define KEY_COLON 58
#else
# define KEY_ESC XK_Escape
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_A 97
# define KEY_D 100
# define KEY_W 119
# define KEY_S 115
# define KEY_Q 113
# define KEY_E 101
# define KEY_R 114
# define KEY_O 111
# define KEY_C 99
# define KEY_COLON XK_colon
#endif

static void	ft_view_keys(int keysym, t_data *data)
{
	if (keysym == KEY_DOWN)
		scale_down(data);
	else if (keysym == KEY_UP)
		scale_up(data);
	else if (keysym == KEY_LEFT)
		rotate_yaw(data, -FDF_ANGLE_STEP);
	else if (keysym == KEY_RIGHT)
		rotate_yaw(data, FDF_ANGLE_STEP);
	else if (keysym == KEY_Q)
		rotate_pitch(data, -FDF_ANGLE_STEP);
	else if (keysym == KEY_E)
		rotate_pitch(data, FDF_ANGLE_STEP);
	else if (keysym == KEY_R)
		ft_reset_view(data);
	else if (keysym == KEY_A)
		translate_left(data);
	else if (keysym == KEY_D)
		translate_right(data);
	else if (keysym == KEY_W)
		translate_up(data);
	else if (keysym == KEY_S)
		translate_down(data);
}

int	read_keys(int keysym, t_data *data)
{
	if (data->cmd_mode)
		return (ft_cmd_key(data, keysym, 0));
	if (keysym == KEY_ESC)
		close_win(data, 0);
	else if (keysym == KEY_COLON || keysym == KEY_O)
		ft_cmd_open(data);
	else if (keysym == KEY_C)
		ft_scheme_cycle(data);
	else
		ft_view_keys(keysym, data);
	return (0);
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
	ft_redraw(&data);
	ft_setup_hooks(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
