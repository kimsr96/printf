CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c 
OBJS = $(SRCS:.c=.o)
RM = rm -f
NAME = libftprintf.a

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

all : $(NAME)

clean :
	make -C ./libft clean
	$(RM) $(OBJS)
 
fclean : clean
	make -C ./libft fclean
	$(RM) $(NAME)

re : 
	make fclean
	make all

.PHONY: all clean fclean re