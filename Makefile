COMMON_SRCS	=	src/parser.c src/minilibft.c src/instructions.c src/list_utils.c src/ft_split_aux.c src/ft_split.c src/arg_parser.c

COMMON_OBJS	=	${COMMON_SRCS:.c=.o}

SRCS		=	ps_src/main.c ps_src/arr_utils.c ps_src/solver_chunk.c ps_src/solver_chunk_utils.c ps_src/small_solver.c

OBJS		=	${SRCS:.c=.o}

BONUS_SRCS	=	checker_src/main.c

BONUS_OBJS	=	${BONUS_SRCS:.c=.o}

NAME		=	push_swap

BONUS_NAME 	=	checker

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

%.o: %.c
				$(CC) $(CFLAGS) -I./includes $< -c -o ${<:.c=.o}

all:			${NAME}

${NAME}:		${OBJS} ${COMMON_OBJS}
				${CC} ${CFLAGS} ${OBJS} ${COMMON_OBJS} -o ${NAME}

${BONUS_NAME}:	${BONUS_OBJS} ${COMMON_OBJS}
				${CC} ${CFLAGS} ${BONUS_OBJS} ${COMMON_OBJS} -o ${BONUS_NAME}

bonus:			${BONUS_NAME}
			
clean:
				rm -f ${OBJS} ${COMMON_OBJS} ${BONUS_OBJS}

fclean:			clean
				rm -f ${NAME} ${BONUS_NAME}

re:				fclean all

.PHONY:			all clean fclean re bonus
