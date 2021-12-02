SRC			=	./src/ft_printf.c \
				./src/ft_eval.c \
				./src/flag_handlers.c \
				./src/ft_writers.c \
				./src/ft_writer_d.c \
				./src/ch_handler.c \
				./src/ft_writer_c.c \
				./src/ft_writer_per.c \
				./src/ft_writer_p.c \
				./src/ft_writer_x.c \
				./src/ft_writer_u.c

SRC_BONUS	=	

OBJ			=	$(SRC:.c=.o)
OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

LIBFT		=	$(LIBFT_PATH)/libft.a
LIBFT_PATH	=	./libft

NAME		=	libftprintf.a

CC			=	gcc -c

AR			=	ar rc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

%.o%.c: $(LIBFT)
			$(CC) $(CFLAGS) $<	-o $@

all:		makelib $(NAME)

bonus:		

$(NAME):	$(OBJ)
			cp $(LIBFT) $(NAME)
			ar rc $(NAME) $(OBJ)

makelib:		
			@make -C $(LIBFT_PATH)

norme:
			@echo "---- INCLUDE ----"
			norminette ./include
			@echo "---- SRC ----"
			norminette ./src
			@echo "---- LIBFT ----"
			norminette ./libft

clean:
			@make -C $(LIBFT_PATH) clean
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME) $(LIBFT)

re:			fclean all

.PHONY:		all re m clean
