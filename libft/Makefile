SRC			=	ft_strlen.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_itoa.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_strcpy.c \
				ft_substr.c \
				ft_memset.c \
				ft_memcpy.c \
				ft_bzero.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isascii.c \
				ft_isalnum.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strdup.c \
				ft_strstr.c \
				ft_strchr.c \
				ft_calloc.c \
				ft_strnstr.c \
				ft_split.c \
				ft_strtrim.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strjoin.c \
				ft_strmapi.c \
				ft_strrchr.c \
				ft_digits.c \
				ft_digits_base.c \
				ft_itoa_base.c \
				ft_uitoa.c \
				ft_putnbr_base.c

SRC_BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ			=	${SRC:.c=.o}
OBJ_BONUS	=	${SRC_BONUS:.c=.o}

NAME		=	libft.a

CC			=	gcc -c

AR			=	ar rc

RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} $<	-o ${<:.c=.o}

${NAME}:	${OBJ}
			${AR} ${NAME} ${OBJ}
			ranlib ${NAME}

bonus:		${OBJ_BONUS}
			${AR} ${NAME} ${OBJ_BONUS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJ} ${OBJ_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
