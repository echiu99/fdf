/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:09:56 by echiu             #+#    #+#             */
/*   Updated: 2026/03/27 16:30:00 by echiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifdef __APPLE__
#  include <MLX42/MLX42.h>
# else
#  include <mlx.h>
# endif
# include "./libft/libft.h"
# include <math.h>
# include <errno.h>
# include <fcntl.h>
# ifndef __APPLE__
#  include <X11/keysym.h>
# endif

# ifdef __APPLE__
#  define FDF_COLOR_CLEAR 0x000000FF
# else
#  define FDF_COLOR_CLEAR 0x00000000
# endif

# define FDF_ISO_Z 0.78539816339
# define FDF_ISO_X 0.6154
# define FDF_ANGLE_STEP 0.08
# define FDF_SCALE_MIN 2.0
# define FDF_SCALE_MAX 400.0
# define FDF_DEFAULT_SCALE 50.0
# define FDF_PAN_STEP 20.0
# define FDF_ZOOM_WHEEL 1.1
# define FDF_GRAD_R0 0x6B
# define FDF_GRAD_G0 0x2D
# define FDF_GRAD_B0 0x9E
# define FDF_GRAD_R1 0x1E
# define FDF_GRAD_G1 0x90
# define FDF_GRAD_B1 0xFF

typedef struct s_coords
{
	double	x;
	double	y;
	double	z;
}	t_coords;

typedef struct s_plot
{
	int		steep;
	int		x;
	int		y;
	double	bright;
	int		color;
}	t_plot;

typedef struct s_wu
{
	double	x0;
	double	y0;
	double	x1;
	double	y1;
	double	z0;
	double	z1;
	double	gradient;
	double	intery;
	int		xpxl1;
	int		xpxl2;
	int		steep;
}	t_wu;

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
	double			off_x;
	double			off_y;
	double			angle_x;
	double			angle_y;
	double			z_min;
	double			z_max;
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
void	ft_destroy_mlx(t_data *data);
void	ft_init_window(t_data *data);
void	ft_init_image(t_data *data);
void	scale_down(t_data *data);
void	ft_zoom_at(t_data *data, int mx, int my, double factor);
void	translate_up(t_data *data);
void	init_mlxdata(t_data *data);
void	ft_rebuild_view(t_data *data);
void	ft_redraw(t_data *data);
void	ft_alloc_view(t_data *data);
void	ft_reset_view(t_data *data);
void	rotate_yaw(t_data *data, double delta);
void	rotate_pitch(t_data *data, double delta);
void	ft_placelines(t_data *data);
void	translate_down(t_data *data);
void	translate_left(t_data *data);
void	ft_free_char2(char **tofree);
void	translate_right(t_data *data);
void	ft_free_char3(char ***tofree);
void	ft_putline(t_data *data, int i, int j);
void	ft_get_map(char *map_path, t_data *data);
void	ft_fail_map(t_data *data, char ***map_vals, char *msg);
int		ft_valid_token(char *str);
char	**ft_get_map_lines(int map_fd);
char	***ft_mapline_tostr(char **map_lines);
void	init_mapdata(t_data *data, char *map_path);
void	ft_compute_z_range(t_data *data);
void	ft_clear_img(t_data *data);
void	ft_put_img(t_data *data);
void	ft_setup_hooks(t_data *data);
void	put_pixel_img(t_data *data, int x, int y, int color);
int		fdf_pack_rgb(int r, int g, int b);
int		fdf_scale_color(int color, double brightness);
int		fdf_color_height(t_data *data, double z);
void	fdf_plot_aa(t_data *data, t_plot *p);
int		ft_wu_ipart(double x);
double	ft_wu_round(double x);
double	ft_wu_fpart(double x);
double	ft_wu_rfpart(double x);
void	ft_wu_swap(double *a, double *b);
int		ft_abs(int x);
int		close_event(t_data *data);
int		ft_strslen(char **map_lines);
int		close_win(t_data *data, int i);
int		read_keys(int keysym, t_data *data);

# ifdef __APPLE__

void	read_keys_mac(mlx_key_data_t keydata, void *param);
void	close_event_mac(void *param);
void	scroll_hook_mac(double xdelta, double ydelta, void *param);

# else

int		mouse_hook_linux(int button, int x, int y, void *param);

# endif

#endif
