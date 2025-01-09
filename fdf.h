/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:09:56 by echiu             #+#    #+#             */
/*   Updated: 2024/04/24 16:40:29 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "./libft/libft.h"
# include <math.h>
# include <errno.h>

typedef struct s_coords
{
	double	x;
	double	y;
	double	z;
}	t_coords;

typedef struct s_data
{
	unsigned int	r;
	unsigned int	c;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	l;
	unsigned int	m;
	unsigned int	size;
	double			scale;
	t_coords		*todi;
	t_coords		*tredi;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*addr;
	int				h;
	int				w;
	int				x;
	int				y;
	int				d;
	int				dx;
	int				dy;
	int				low;
	int				bpp;
	int				xhigh;
	int				yhigh;
	int				color;
	int				endian;
	int				line_len;
}	t_data;

void	scale_up(t_data *data);
void	ft_newwin(t_data *data);
void	ft_newimg(t_data *data);
void	scale_down(t_data *data);
void	translate_up(t_data *data);
void	init_mlxdata(t_data *data);
void	ft_concoords(t_data *data);
void	ft_placelines(t_data *data);
void	translate_down(t_data *data);
void	translate_left(t_data *data);
void	ft_real_coords(t_data *data);
void	ft_free_char2(char **tofree);
void	translate_right(t_data *data);
void	ft_free_char3(char ***tofree);
void	ft_putline(t_data *data, int i, int j);
void	ft_get_map(char *map_path, t_data *data);
void	init_mapdata(t_data *data, char *map_path);
void	put_pixel_img(t_data *data, int x, int y, int color);
int		ft_abs(int x);
int		close_event(t_data *data);
int		ft_strslen(char **map_lines);
int		close_win(t_data *data, int i);

#endif
