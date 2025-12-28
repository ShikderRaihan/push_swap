 .SILENT:

NAME = libstderr_ftprintf.a
SRCS = ft_putchar.c ft_hexa.c ft_putstr.c ft_ptr.c ft_putnbr_uns.c stderr_printf.c ft_putnbr.c
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

all: ${NAME}

${NAME}: ${OBJS} 
	${AR} ${NAME} ${OBJS}

.c.o:
	${CC} ${CFLAGS} -c ${@:.o=.c} -o ${@:.c=.o}

clean: 
	${RM} ${OBJS} 

fclean: clean 
	${RM} ${NAME}

re: fclean all 


.PHONY: all clean fclean re