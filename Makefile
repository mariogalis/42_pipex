SRCS	=	main.c pipex.c split.c utils.c error.c

OBJS	= ${SRCS:.c=.o}

NAME	= pipex

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
				${RM} ${OBJBS} ${OBJS}

fclean: 	clean
				${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re