CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_write_printf.c ft_flag.c ft_printf_utils.c \
		ft_flag_info.c ft_len_info.c ft_init_free.c ft_padding.c
OBJS = $(SRCS:.c=.o)
SRCS_B = ./bonus/ft_printf_bonus.c ./bonus/ft_write_printf_bonus.c \
		./bonus/ft_flag_bonus.c ./bonus/ft_printf_utils_bonus.c \
		./bonus/ft_flag_info_bonus.c ./bonus/ft_len_info_bonus.c \
		./bonus/ft_init_free_bonus.c ./bonus/ft_padding_bonus.c
OBJS_B = $(SRCS_B:.c=.o)
INC = ./ft_printf.h
INC_B = ./bonus/ft_printf_bonus.h
RM = rm -f
NAME = libftprintf.a

ifdef WITH_BONUS
	OBJECTS = $(OBJS_B)
else
	OBJECTS = $(OBJS)
endif

%.o : %.c $(INC)
	$(CC) $(CFLAGS) -I -$(INC) -c $< -o $@

all :
	@$(RM) $(OBJS_B)
	@make $(NAME);

$(NAME) : 
	ar rc $(NAME) $(OBJECTS)

bonus :
	@$(RM) $(OBJS)
	@make WITH_BONUS=1 $(NAME)

clean :
	cd ./libft; make clean
	$(RM) $(OBJS) $(OBJS_B)
 
fclean : clean
	cd ./libft; make fclean
	$(RM) $(NAME)

re : 
	make fclean
	make all

.PHONY: all clean fclean re bonus