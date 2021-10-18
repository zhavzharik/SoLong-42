/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:24:47 by abridger          #+#    #+#             */
/*   Updated: 2021/10/18 17:22:20 by abridger         ###   ########.fr       */
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
}			t_data;

typedef struct s_visual
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_visual;

typedef void	(*t_action)(t_visual **, t_data **, int, int);
enum	e_assets {s, w, c, p, e};

t_data		*init_game(t_data *game);
t_visual	*init_window(t_visual *window, t_data *game);
void		get_map_height(char *file, t_data **game);
int			ft_reading_file(char *file, t_data **game);
void		set_picture(t_visual **window, t_data **game);
void		draw_map(t_visual **window, t_data **game);
char		**create_array_assets(void);
t_action	*create_array_function(void);
void		put_empty(t_visual **window, t_data **game, int i, int j);
void		put_wall(t_visual **window, t_data **game, int i, int j);
void		put_cake(t_visual **window, t_data **game, int i, int j);
void		put_player(t_visual **window, t_data **game, int i, int j);
void		put_exit(t_visual **window, t_data **game, int i, int j);
void		print_map_data(t_data **game); // delete
void		draw_test1(t_visual **window, t_data **game); // delete
void		draw_test2(t_visual **window, t_data **game); // delete

#endif
