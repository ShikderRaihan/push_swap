 .SILENT:

NAME = push_swap
BONUS = checker
SRCS = main.c
COMMON_SRCS = push_swap.c  simple_sort.c medium_sort.c medium_sort_utils.c complex_sort.c simple_sort_utils.c stack_index.c push.c swap.c rotate.c reverse_rotate.c flags.c error.c check_input.c ft_atol.c turk_algo.c disorder_metric.c bench.c sortthree.c turk_utils1.c turk_utils2.c turk_utils3.c tur_cal_cost.c
B_SRCS = ./bonus/checker.c ./bonus/main.c ./bonus/checker_utils.c
OBJS = ${SRCS:.c=.o}
COMMON_OBJS = ${COMMON_SRCS:.c=.o}
B_OBJS = ${B_SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = ./Libft
FT_PRINTF_DIR = ./ft_printf
STDERR_PRINTF_DIR = ./stderr_printf
GNL_DIR = ./get_next_line
LIBFT = ${LIBFT_DIR}/libft.a
FT_PRINTF = ${FT_PRINTF_DIR}/libftprintf.a
STDERR_PRINTF = ${STDERR_PRINTF_DIR}/libstderr_ftprintf.a
GNL = ${GNL_DIR}/libget_next_line.a

all: ${NAME}
bonus: ${BONUS}

${NAME}: ${COMMON_OBJS} ${OBJS} ${LIBFT} ${FT_PRINTF} ${STDERR_PRINTF}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${COMMON_OBJS} -L${LIBFT_DIR} -L${FT_PRINTF_DIR} -L${STDERR_PRINTF_DIR} -lft -lftprintf -lstderr_ftprintf
${BONUS}: ${COMMON_OBJS} ${B_OBJS} ${LIBFT} ${FT_PRINTF} ${STDERR_PRINTF} ${GNL}
	${CC} ${CFLAGS} -o ${BONUS} ${B_OBJS} ${COMMON_OBJS} -L${LIBFT_DIR} -L${FT_PRINTF_DIR} -L${STDERR_PRINTF_DIR} -L${GNL_DIR} -lft -lftprintf -lstderr_ftprintf -lget_next_line

${LIBFT}:
	make -C ${LIBFT_DIR}

${FT_PRINTF}:
	make -C ${FT_PRINTF_DIR}

${STDERR_PRINTF}:
	make -C ${STDERR_PRINTF_DIR}

${GNL}:
	make -C ${GNL_DIR}

.c.o:
	${CC} ${CFLAGS} -c ${@:.o=.c} -o ${@:.c=.o}

clean: 
	${RM} ${OBJS} ${COMMON_OBJS} ${B_OBJS}
	make -C ${LIBFT_DIR} clean
	make -C ${FT_PRINTF_DIR} clean
	make -C ${STDERR_PRINTF_DIR} clean
	make -C ${GNL_DIR} clean

fclean: clean 
	${RM} ${NAME}
	make -C ${LIBFT_DIR} fclean
	make -C ${FT_PRINTF_DIR} fclean
	make -C ${STDERR_PRINTF_DIR} fclean
	make -C ${GNL_DIR} fclean

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus