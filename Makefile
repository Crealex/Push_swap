NAME	=	push_swap
LIBFT	=	libft/libft.a
SRCS	=	push_swap_move_chained.c main.c libft_pimp.c
OBJS	=	${SRCS:%.c=${OBJDIR}/%.o}
CC		=	gcc
CFLAGS	=	-Werror -Wextra -Wall
OBJDIR	=	objets
END := "\033[0m"
WHITE := "\033[1;37m"
NC := \033[0m
PINK := "\033[1;35m"
GREEN := "\033[32m"
BOLD := "\033[1m"
L_PURPLE :="\033[38;5;55m"

all:	${NAME} display_ascii

${NAME}:	${OBJS} ${LIBFT}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

${LIBFT}:
	@echo "\033[1mBuilding the project..."${END}
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

.PHONY: display_ascii
display_ascii:
	@echo $(BOLD)$(GREEN); cat ascii_art.txt; echo $(END)
	@echo $(BOLD)$(L_PURPLE) ✨Push_Swap✨ $(GREEN)is ready 🎉 $(END)