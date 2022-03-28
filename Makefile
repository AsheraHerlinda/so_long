NAME = so_long

SRCS = 	so_long.c \
		verify_map.c \
		parce_map.c \
		find_positions.c \
		show_map.c \
		create_field.c \
		hooks.c \
		mlx_utils.c \
		end_game.c \
		refresh_map.c \
		moves.c	\
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \


OBJS = ${SRCS:.c=.o}

CC 		= gcc
RM 		= rm -f
FLAGS 	=	-Wall -Wextra -Werror
MLX		=	mlx/Makefile.gen
LFT		=	libft/libft.a
INC		=	-I ./inc -I ./libft -I ./mlx
LIB		=	-L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd

HEAD = so_long.h

all:	${MLX} ${LFT} ${NAME}

${NAME}: ${OBJS} ${HEAD}
		${CC} -o ${NAME} ${OBJS} ${LIB}

${MLX}:
		@make -s -C mlx_linux

${LFT}:
		@make -s -C libft

%.o:	%.c 
		gcc ${FLAGS} ${INC} -c $< -o $@ 

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re