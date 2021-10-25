NAME = libft.a

LIST =			ft_atoi.c			\
				ft_isdigit.c		\
				ft_lstadd_front.c	\
				ft_lstclear.c		\
				ft_lstlast.c		\
				ft_lstsize.c		\
				ft_putchar.c		\
				ft_puterror.c		\
				ft_putnbr.c			\
				ft_putstr.c			\
				ft_strcmp.c			\
				ft_strdup.c			\
				ft_strlen.c			\
				ft_strchr.c			\
				ft_strcpy.c 		\
				ft_strjoin.c		\
				ft_strncmp.c		\
				ft_itoa.c			\
				get_next_line.c


OBJ = $(LIST:.c=.o)

CC = gcc

RM = rm -f

LIBH = libft.h

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c $(LIBH)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
