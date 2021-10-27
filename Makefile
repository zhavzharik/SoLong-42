# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 16:45:44 by abridger          #+#    #+#              #
#    Updated: 2021/10/27 16:24:57 by abridger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

NAME_B			=	so_long

SRCS_DIR		=	./srcs/

OBJS_DIR		=	./objs/

SRCS_BONUS_DIR		=	./srcs_bonus/

OBJS_BONUS_DIR		=	./objs_bonus/

HEADERS_DIR		=	./includes/

LIBFT_DIR		=	./libft/

LIBMLX_DIR		=	./mlx/

SRCS			=	$(SRCS_DIR)	so_long.c		\
								get_map.c		\
								init.c			\
								draw_set.c		\
								draw_put.c		\
								draw_map.c		\
								clear.c			\
								game_utils.c	\
								actions.c		\
								actions_utils.c	\
								hook.c			\
								check_map_1.c	\
								check_map_2.c	\
								errors.c		\
								end_game.c		\
								animation.c		\
								enemy.c

SRCS_BONUS			=	$(SRCS_BONUS_DIR)	so_long_bonus.c			\
											get_map_bonus.c			\
											init_bonus.c			\
											draw_set_bonus.c		\
											draw_put_bonus.c		\
											draw_map_bonus.c		\
											clear_bonus.c			\
											game_utils_bonus.c		\
											actions_bonus.c			\
											actions_utils_bonus.c	\
											hook_bonus.c			\
											check_map_1_bonus.c		\
											check_map_2_bonus.c		\
											errors_bonus.c			\
											end_game_bonus.c		\
											animation_bonus.c		\
											enemy_bonus.c


HEADERS			=	./includes/so_long.h

HEADERS_B			=	./includes/so_long_bonus.h

OBJS			=	$(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))

OBJS_BONUS			=	$(addprefix $(OBJS_BONUS_DIR), $(notdir $(SRCS_BONUS:.c=.o)))

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

LDFLAGS			=	-L$(LIBMLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -framework OpenGL -framework Appkit -O3

RM				=	rm -f

LIBFT			=	$(addprefix $(LIBFT_DIR), libft.a)

LIBMLX			=	$(addprefix $(LIBMLX_DIR), libmlx.a)

all:	$(LIBFT) $(LIBMLX) $(NAME)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c $(HEADERS) $(LIBFT) $(LIBMLX) Makefile | $(OBJS_DIR)
	$(CC) $(CFLAGS) -O3 -I$(HEADERS_DIR) -Imlx -c $< -o $@

$(OBJS_BONUS_DIR)%.o:	$(SRCS_BONUS_DIR)%.c $(HEADERS_B) $(LIBFT) $(LIBMLX) Makefile | $(OBJS_BONUS_DIR)
	$(CC) $(CFLAGS) -O3 -I$(HEADERS_DIR) -Imlx -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBMLX):
	make -C $(LIBMLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(NAME_B): $(OBJS_BONUS) $(LIBFT) $(LIBMLX)
	$(CC) $(OBJS_BONUS) -o $@ $(LDFLAGS)

bonus:	$(LIBFT) $(LIBMLX) $(NAME_B)

clean:
		$(RM) -r $(OBJS_DIR) $(OBJS_BONUS_DIR)
		make clean -C $(LIBFT_DIR) fclean

fclean: clean
		$(RM) $(NAME) $(NAME_B)
		make clean -C $(LIBFT_DIR) fclean

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(OBJS_BONUS_DIR):
	mkdir $(OBJS_BONUS_DIR)

re:	fclean $(OBJS_DIR) all

.PHONY:	all clean fclean re bonus
