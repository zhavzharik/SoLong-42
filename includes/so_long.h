/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:24:47 by abridger          #+#    #+#             */
/*   Updated: 2021/10/19 19:15:48 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define WALL "./assets/tree2.xpm"
# define ROWAN "./assets/rowan.xpm"
# define PUMP1 "./assets/pumpkin1.xpm"
# define PUMP2 "./assets/pumpkin2.xpm"
# define GROUND "./assets/ground1.xpm"
# define HOUSE "./assets/house1.xpm"
# define MOON "./assets/moon1.xpm"
# define CAKE "./assets/cake1.xpm"
# define GHOST1 "./assets/ghost1.xpm"
# define GHOST2 "./assets/ghost2.xpm"
# define BATS "./assets/bats.xpm"

# define ORANGE 0xFE6500
# define PIC_SIDE 80

typedef struct s_data
{
	int		map_h;
	int		map_l;
	char	**file_data;
	void	*wall;
	void	*player;
	void	*cake;
	void	*space;
	void	*exit;
	int		x_pos_player;
	int		y_pos_player;
	int		nb_cake;
}			t_data;

typedef struct s_visual
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_visual;

typedef void	(*t_action)(t_visual **, t_data **, int, int);

t_data		*init_game(t_data *game);
t_visual	*init_window(t_visual *window, t_data *game);
void		init_array(char *file, t_data **game);
void		get_map_height(char *file, t_data **game);
void		get_map_length(char *file, t_data **game);
int			ft_reading_file(char *file, t_data **game);
void		set_picture(t_visual **window, t_data **game);
int			get_index(char *assets, char ch);
void		draw_map(t_visual **window, t_data **game);
char		*create_str_assets(void);
t_action	*create_array_function(void);
void		put_empty(t_visual **window, t_data **game, int i, int j);
void		put_wall(t_visual **window, t_data **game, int i, int j);
void		put_cake(t_visual **window, t_data **game, int i, int j);
void		put_player(t_visual **window, t_data **game, int i, int j);
void		put_exit(t_visual **window, t_data **game, int i, int j);
void		ft_array_clear(char **array, int row);
void		ft_ptr_clear(char *assets, t_action *func);
void		ft_clear_window(t_visual **window);
void		ft_struct_clear(t_data *game);
void		count_present(t_data **game);
void		get_player_pos(t_data **game);
int			key_hook(int keycode, t_visual *window);
void		hook_test(t_visual **window);
// int			close(int keycode, t_visual *window);
void		print_map_data(t_data **game); // delete
void		draw_test1(t_visual **window, t_data **game); // delete
void		draw_test2(t_visual **window, t_data **game); // delete

#endif
