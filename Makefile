CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)
INC = ./ft_printf.h
RM = rm -f
NAME = libftprintf.a

%.o : %.c
	cd ./libft; make
	$(CC) $(CFLAGS) -I $(INC) -c $^ -o $@

$(NAME) : $(OBJS)
	cp ./libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)

all : $(NAME) $(INC)

clean :
	cd ./libft; make clean
	$(RM) $(OBJS)

fclean : clean
	cd ./libft; make fclean
	$(RM) $(NAME)

re : 
	make fclean
	make all

.PHONY: all clean fclean re libft