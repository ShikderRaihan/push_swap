 .SILENT:

NAME = push_swap
SRCS = main.c push_swap.c push.c swap.c rotate.c reverse_rotate.c error.c disorder_metric.c flags.c bench.c check_input.c complex_sort.c medium_sort.c stack_index.c hybrid.c turk_algo.c sortthree.c turk_util.c ultra.c 
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./Libft
FT_PRINTF_DIR = ./ft_printf
STDERR_PRINTF_DIR = ./stderr_printf
LIBFT = ${LIBFT_DIR}/libft.a
FT_PRINTF = ${FT_PRINTF_DIR}/libftprintf.a
STDERR_PRINTF = ${STDERR_PRINTF_DIR}/libstderr_ftprintf.a

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT} ${FT_PRINTF} ${STDERR_PRINTF}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${LIBFT_DIR} -L${FT_PRINTF_DIR} -L${STDERR_PRINTF_DIR} -lft -lftprintf -lstderr_ftprintf

${LIBFT}:
	make -C ${LIBFT_DIR}

${FT_PRINTF}:
	make -C ${FT_PRINTF_DIR}

${STDERR_PRINTF}:
	make -C ${STDERR_PRINTF_DIR}

.c.o:
	${CC} ${CFLAGS} -c ${@:.o=.c} -o ${@:.c=.o}

clean: 
	${RM} ${OBJS}
	make -C ${LIBFT_DIR} clean
	make -C ${FT_PRINTF_DIR} clean
	make -C ${STDERR_PRINTF_DIR} clean

fclean: clean 
	${RM} ${NAME}
	make -C ${LIBFT_DIR} fclean
	make -C ${FT_PRINTF_DIR} fclean
	make -C ${STDERR_PRINTF_DIR} fclean

re: fclean all 


.PHONY: all clean fclean re