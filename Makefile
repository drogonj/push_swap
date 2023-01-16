
NAME		=	push_swap

SRCS		=	main.c			     \
				init_tabs.c		     \
				ft_split_ps.c	     \
				ft_atoi_ps.c	     \
				instructions.c	   	 \
				simple_sorting.c  	 \
				complex_sorting.c 	 \
				instructions_utils.c \
				sorting_utils.c	     \
				general_utils.c

OBJS		=	$(SRCS:.c=.o)

FT_PRINTF	=	ft_printf/libftprintf.a
LIBFT		=	libft/libft.a

FLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address

RM			=	rm -rf

.c.o:
				gcc $(FLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(MAKE) -C libft
				$(MAKE) -C ft_printf
				gcc $(FLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

clean:
				$(RM) $(OBJS)
				$(MAKE) -C libft clean
				$(MAKE) -C ft_printf clean

fclean:			clean
				$(RM) $(NAME)
				$(MAKE) -C libft fclean
				$(MAKE) -C ft_printf fclean

re:				fclean all

.PHONY:			all clean fclean re
