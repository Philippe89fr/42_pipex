NAME        = pipex
NAME_BONUS  = pipex_bonus
LIBFT       = libft/libft.a
SRCS        = ./srcs/ft_no_herdoc.c \
			./srcs/main.c \
			./srcs/get_next_line.c \
			./srcs/get_next_line_utils.c \
			./srcs/ft_herdoc.c \
			./srcs/ft_vie_de_famille.c \

SRCS_BONUS  = ./srcs_bonus/ft_no_herdoc_bonus.c \
			./srcs_bonus/main_bonus.c \
			./srcs_bonus/get_next_line_bonus.c \
			./srcs_bonus/get_next_line_utils_bonus.c \
			./srcs_bonus/ft_herdoc_bonus.c \
			./srcs_bonus/ft_vie_de_famille_bonus.c \

OBJS        = ${SRCS:.c=.o}
OBJS_BONUS  = ${SRCS_BONUS:.c=.o}
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3 -Ilibft -Isrcs
RM          = rm -rf

# Construction de l'exécutable standard
${NAME}: ${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -Llibft -lft -o ${NAME}

# Construction de l'exécutable bonus
${NAME_BONUS}: ${LIBFT} ${OBJS_BONUS}
	${CC} ${CFLAGS} ${OBJS_BONUS} -Llibft -lft -o ${NAME_BONUS}

# Compilation de libft
${LIBFT}:
	make -C libft

# Transformation des .c en .o
.c.o:
	${CC} ${CFLAGS} -c $< -o $@

# Règles principales
all: ${NAME}

bonus: ${NAME_BONUS}

clean:
	make clean -C libft
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	make fclean -C libft
	${RM} ${NAME} ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re bonus