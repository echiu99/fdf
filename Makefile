NAME = fdf

LIBFT_D = ./libft

LIBFT = $(LIBFT_D)/libft.a

LIBMLX_D = ../mlx_linux

LFLAGS = -L$(LIBMLX_D) -Imlx_linux -lmlx -lbsd -lXext -lX11 -lm -lz

SRC = fdf_utils.c \
      ft_create_win.c \
      ft_fdf.c \
      ft_get_vals.c \
      ft_putline.c \
      ft_concoords.c \
      ft_translate.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

CC = cc

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) ../mlx_linux/*.a ./libft/libft.a -o $(NAME)

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
