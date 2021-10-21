/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:24:47 by abridger          #+#    #+#             */
/*   Updated: 2021/10/21 22:25:32 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define WALL "./assets/pumpkin.xpm"
# define GROUND "./assets/ground.xpm"
# define CAKE "./assets/cake.xpm"
# define GHOST_L "./assets/ghost_left.xpm"
# define GHOST_R "./assets/ghost_right.xpm"
# define PORT_C "./assets/portal_closed.xpm"
# define PORT_O "./assets/portal_opened.xpm"

# define ORANGE 0xFE6500
# define PIC_SIDE 80
# define XK_ESCAPE 17 // check
# define XK_A 0
# define XK_D 2
# define XK_S 1
# define XK_W 13

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			map_h;
	int			map_l;
	char		**file_data;
	void		*wall;
	void		*player_l;
	void		*player_r;
	void		*cake;
	void		*space;
	void		*exit_c;
	void		*exit_o;
	int			x_pos_player;
	int			y_pos_player;
	int			flag_player;
	int			nb_cake;
	int			game_score;
	char		*assets;
	int			step;
}				t_data;

size_t		get_line_length(char *file);
void		check_map_length(char *file);
void		put_err_str(char *str);
void		put_error_message(int nb_error);
t_data		*init_game(t_data *game);
void		init_window(t_data **game);
void		init_array(char *file, t_data **game);
void		get_map_height(char *file, t_data **game);
void		get_map_length(char *file, t_data **game);
int			ft_reading_file(char *file, t_data **game);
void		set_picture(t_data **game);
int			get_index(char *assets, char ch);
void		draw_map(t_data **game);
void		put_empty(t_data **game, int i, int j);
void		put_wall(t_data **game, int i, int j);
void		put_cake(t_data **game, int i, int j);
void		put_player(t_data **game, int i, int j);
void		put_exit(t_data **game, int i, int j);
void		execute_func(t_data **game, int indx, int i, int j);
void		ft_array_clear(char **array, int row);
// void		ft_clear_window(t_data **game);
void		ft_struct_clear(t_data *game);
void		count_present(t_data **game);
void		get_player_pos(t_data **game);
void		game_proceed(t_data **game);
char		get_component(t_data **game, int x, int y);
int			whether_can_move(t_data **game, int x, int y);
void		change_map(t_data **game, char ch, int x, int y);
void		check_game_score(t_data **game, int x, int y);
void		move_up(int key, t_data **game);
void		move_down(int key, t_data **game);
void		move_left(int key, t_data **game);
void		move_right(int key, t_data **game);
int			key_press(int key, t_data **game);
void		setup_action(t_data **game);
int			key_hook(int keycode, t_data *game); // rewrite
void		print_step(t_data *game); // rewrite
void		print_map_data(t_data **game); // delete

#endif
