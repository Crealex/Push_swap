NAME	=	push_swap
LIBFT	=	libft.a
SRCS	=	push_swap_move_chained.c main.c
OBJS	=	${SRCS:%.c=${OBJDIR}/%.o}
CC		=	gcc
CFLAGS	=	-Werror -Wextra -Wall
OBJDIR	=	objets

all:	${NAME} ${LIBFT}

#ajouter regles NAME et LIBFT

${OBJDIR}/%.o: %.c | ${OBJDIR}
	${CC} ${CFLAGS} -c -o $@ $<

${OBJDIR}:
	mkdir -p ${OBJDIR}

clean:
	rm -rf ${OBJDIR}

fclean: clean
	rm -f ${NAME}

re: fclean re

.PHONY: all clean fclean re