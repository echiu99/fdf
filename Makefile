NAME = fdf

LIBFT_D = ./libft

LIBFT = $(LIBFT_D)/libft.a

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
LIBMLX_D = ../mlx_macos
MLX_INC = -I$(LIBMLX_D)/include
LFLAGS = $(LIBMLX_D)/build/libmlx42.a \
	-L/opt/homebrew/lib -L/usr/local/lib -lglfw \
	-framework Cocoa -framework OpenGL -framework IOKit -lm
PLATFORM_SRC = ft_hooks_mac.c ft_setup_mac.c ft_win_mac.c ft_pixel_mac.c \
	ft_cmd_key_mac.c
else
LIBMLX_D = ../mlx_linux
MLX_INC = -I$(LIBMLX_D)
LFLAGS = -L$(LIBMLX_D) -lmlx -lbsd -lXext -lX11 -lm -lz
PLATFORM_SRC = ft_hooks_linux.c ft_setup_linux.c ft_win_linux.c ft_pixel_linux.c \
	ft_cmd_key_linux.c
endif

SRC = fdf_utils.c \
      ft_create_win.c \
      ft_fdf.c \
      ft_get_vals.c \
      ft_map_valid.c \
      ft_map_read.c \
      ft_map_switch.c \
      ft_maps_dir.c \
      ft_cmd.c \
      ft_cmd_run.c \
      ft_init_map.c \
      ft_scheme.c \
      ft_hud.c \
      ft_hud_glyph.c \
      ft_clear.c \
      ft_color.c \
      ft_plot.c \
      ft_wu_math.c \
      ft_wu_line.c \
      ft_placelines.c \
      ft_project.c \
      ft_view_ctrl.c \
      ft_zoom.c \
      ft_put_img.c \
      ft_translate.c \
      $(PLATFORM_SRC)

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g $(MLX_INC)

CC = cc

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LFLAGS) -o $(NAME)

clean:
	@make clean -s -C $(LIBFT_D)
	rm -fr $(OBJ)

fclean: clean
	@make fclean -s -C $(LIBFT_D)
	rm -fr $(NAME)

re: fclean all

$(LIBFT):
	@make all -s -C $(LIBFT_D)

.PHONY: all clean fclean
