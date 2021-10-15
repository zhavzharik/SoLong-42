/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:24:47 by abridger          #+#    #+#             */
/*   Updated: 2021/10/15 22:33:24 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define WALL "../assets/tree2.xpm"
# define ROWAN "../assets/rowan.xpm"
# define PUMP1 "../assets/pumpkin1.xpm"
# define PUMP2 "../assets/pumpkin2.xpm"
# define GROUND "../assets/ground1.xpm"
# define HOUSE "../assets/house1.xpm"
# define MOON "../assets/moon1.xpm"

# define ORANGE 0xFE6500

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

t_data		*init_game(t_data *game);
int			ft_reading_file(char *file, t_data **game);

#endif
