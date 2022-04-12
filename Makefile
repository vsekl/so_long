SRCS	=		./gnl/get_next_line.c\
				./gnl/get_next_line_utils.c\
				./srcs/errors_1.c\
				./srcs/errors_2.c\
				./srcs/find_map_size.c\
				./srcs/init_game.c\
				./srcs/main.c\
				./srcs/map_allocation.c\
				./srcs/map_check.c\
				./srcs/player_operations.c\
				./srcs/win_operations.c\

SRCS_BONUS	=	./gnl/get_next_line.c\
				./gnl/get_next_line_utils.c\
				./bonus_srcs/counter_bonus.c\
				./bonus_srcs/errors_1_bonus.c\
				./bonus_srcs/errors_2_bonus.c\
				./bonus_srcs/find_map_size_bonus.c\
				./bonus_srcs/ft_lstadd_front_bonus.c\
				./bonus_srcs/ft_lstnew_bonus.c\
				./bonus_srcs/init_game_bonus.c\
				./bonus_srcs/init_textures_bonus.c\
				./bonus_srcs/main_bonus.c\
				./bonus_srcs/map_allocation_bonus.c\
				./bonus_srcs/map_check_bonus.c\
				./bonus_srcs/move_enemy_bonus.c\
				./bonus_srcs/move_player_bonus.c\
				./bonus_srcs/player_operations_bonus.c\
				./bonus_srcs/win_operations_bonus.c\

NAME	= so_long

NAME_BONUS	= so_long_bonus

OBJS	= $(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

OBJS_D	=	$(patsubst %.c,%.d,$(SRCS))

OBJS_BONUS_D	=	$(patsubst %.c,%.d,$(SRCS_BONUS))

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM	=	rm -f

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
		$(CC) $(OBJS_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

%.o: %.c 
	$(CC) $(CFLAGS) -Ignl -Isrcs -Ibonus_srcs -D BUFFER_SIZE=100 -c $< -o $@ -MD

bonus: $(NAME_BONUS)

include $(wildcard $(OBJS_D))

include $(wildcard $(OBJS_BONUS_D))

clean:
	$(RM) $(OBJS) $(OBJS_D) $(OBJS_BONUS) $(OBJS_BONUS_D)

fclean:	clean
	$(RM) $(NAME) $(NAME_BONUS)

re: 	fclean all
	
.PHONY: all clean fclean re bonus