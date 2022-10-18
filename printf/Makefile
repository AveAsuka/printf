NAME		= libftprintf.a

SRCS		=	ft_convert.c ft_printf.c \
				ft_star.c ft_putnbrplus_fd.c \
				ft_putcharline.c ft_putchar_fd.c \
				ft_putnbr_fd.c
				
OBJS		= ${SRCS:.c=.o}

CC			= cc
AR			= ar rcs
FLAGS		= -Wall -Wextra -Werror
RM			= rm -f
HEADER		= ft_printf.h

all:	${NAME}

${NAME}:	${OBJS}
			${AR} ${NAME} $?

${OBJS} : ${HEADER} Makefile

.c.o:	
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean:	
		${RM} ${OBJS}
		
fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
