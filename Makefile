SRCS	=	main.c pipex.c split.c utils.c error.c

OBJS	= ${SRCS:.c=.o}

NAME	= pipex.a

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

AR = ar rc

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				${AR} ${NAME} ${OBJS}
				ranlib ${NAME}

all:		${NAME}

clean:
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re: 		fclean

.PHONY:		all clean fclean re
