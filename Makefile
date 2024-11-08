NAME	=	push_swap
LIBFT	=	libft/libft.a
SRCS	=	push_swap_move_chained.c main.c
OBJS	=	${SRCS:%.c=${OBJDIR}/%.o}
CC		=	gcc
CFLAGS	=	-Werror -Wextra -Wall
OBJDIR	=	objets

all:	${NAME}

${NAME}:	${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

${LIBFT}:
	${MAKE} -C ./libft/ bonus

${OBJDIR}/%.o: %.c | ${OBJDIR}
	${CC} ${CFLAGS} -c -o $@ $<

${OBJDIR}:
	mkdir -p ${OBJDIR}

clean:
	rm -rf ${OBJDIR}
	${MAKE} -C ./libft/ clean

fclean: clean
	rm -f ${NAME}
	${MAKE} -C ./libft/ fclean

re: fclean all

.PHONY: all clean fclean re