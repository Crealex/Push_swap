SRCS 	=	ft_atoi.c ft_bzero.c ft_calloc.c \
			ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_itoa.c \
			ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_putchar_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			ft_split.c ft_strchr.c ft_strdup.c \
			ft_striteri.c ft_strjoin.c ft_strlcat.c \
			ft_strlcpy.c ft_strlen.c ft_strmapi.c \
			ft_strncmp.c ft_strnstr.c ft_strrchr.c \
			ft_strtrim.c ft_substr.c ft_tolower.c \
			ft_toupper.c ${PRINTF}

SRCSB	=	ft_lstadd_back.c ft_lstadd_front.c \
			ft_lstclear.c ft_lstdelone.c \
			ft_lstiter.c ft_lstlast.c ft_lstmap.c \
			ft_lstnew.c ft_lstsize.c

PRINTF	=	ft_printf_print.c print_arg1.c \
			print_arg2.c

OBJS	= ${SRCS:%.c=${OBJDIR}/%.o}
OBJSB	=  ${SRCSB:%.c=${OBJDIR}/%.o}
OBJDIR	= objets
CFLAGS	= -Wall -Werror -Wextra
CC		= gcc
NAME	= libft.a
AR		= ar rcs

all: ${NAME}

${NAME}: ${OBJS}
	@${AR} ${NAME} ${OBJS}

${OBJDIR}/%.o: %.c | ${OBJDIR}
	@echo "\033[1m\033[38;5;55m  COMPILING..."
	@${CC} ${CFLAGS} -c -o $@ $<

${OBJDIR}:
	@mkdir -p ${OBJDIR}

clean:
	@rm -rf ${OBJDIR}

fclean:	clean
	@rm -f ${NAME}

re:	fclean all

bonus: ${OBJSB} ${OBJS}
	@${AR} ${NAME} ${OBJSB} ${OBJS}

.PHONY: all clean fclean re
