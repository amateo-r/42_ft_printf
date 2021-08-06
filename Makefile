SRC			=	./src/ft_printf.c \
				./src/ft_eval.c \
				./src/flag_handlers.c \
				./src/ft_writers.c \
				./src/ft_writer_d.c \
				./src/ch_handler.c \
				./src/ft_writer_c.c \
				./src/ft_writer_per.c \
				./src/ft_writer_p.c

SRC_BONUS	=	

OBJ			=	${SRC:.c=.o}
OBJ_BONUS	=	${SRC_BONUS:.c=.o}

LIBFT		=	libft.a
LIBFT_PATH	=	./libft/
LIBFT_OBJS	=	${LIBFT_PATH}*.o

NAME		=	libftprintf.a

CC			=	gcc -c

AR			=	ar rc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} $<	-o ${<:.c=.o}

all:		${NAME}

bonus:		

${NAME}:	${OBJ} makelib
			${AR} ${NAME} ${OBJ} ${LIBFT_OBJS}
			ranlib ${NAME}

makelib:		
			@make -C ${LIBFT_PATH}

norme:
			@echo "---- INCLUDE ----"
			norminette ./include
			@echo "---- SRC ----"
			norminette ./src
			@echo "---- LIBFT ----"
			norminette ./libft

clean:
			make -C ${LIBFT_PATH} clean
			${RM} ${OBJ} ${OBJ_BONUS}

fclean:		clean
			${RM} ${NAME} ${LIBFT_PATH}${LIBFT}

re:			fclean all
