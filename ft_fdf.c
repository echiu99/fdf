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

int	read_keys(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_win(data, 0);
	else if (keysym == 65364)
		scale_down(data);
	else if (keysym == 65362)
		scale_up(data);
	else if (keysym == 97)
		translate_left(data);
	else if (keysym == 100)
		translate_right(data);
	else if (keysym == 119)
		translate_up(data);
	else if (keysym == 115)
		translate_down(data);
	return (0);
}

void	init_mapdata(t_data *data, char *map_path)
{
	data->size = 0;
	data->r = 0;
	data->c = 0;
	ft_get_map(map_path, data);
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
	ft_placelines(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_hook(data.win_ptr, 17, 0, close_event, &data);
	mlx_key_hook(data.win_ptr, read_keys, &data);
	mlx_loop(data.mlx_ptr);
}
