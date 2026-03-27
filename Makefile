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
else
LIBMLX_D = ../mlx_linux
MLX_INC = -I$(LIBMLX_D)
LFLAGS = -L$(LIBMLX_D) -lmlx -lbsd -lXext -lX11 -lm -lz
endif

SRC = fdf_utils.c \
      ft_create_win.c \
      ft_fdf.c \
      ft_get_vals.c \
      ft_putline.c \
      ft_concoords.c \
      ft_translate.c

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
