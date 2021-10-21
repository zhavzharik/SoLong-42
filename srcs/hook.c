/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:29:53 by abridger          #+#    #+#             */
/*   Updated: 2021/10/21 21:09:38 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_data *game)
{
	(void)game;
	if (keycode == XK_W) // && game->step_check != game->step) //whether_can_move(&game, game->x_pos_player, game->y_pos_player))
		printf("Player moves up!\tStep number : %d\n", game->step);
	else if (keycode == XK_S && whether_can_move(&game, game->x_pos_player,
			game->y_pos_player))
		printf("Player moves down!\tStep number : %d\n", game->step);
	else if (keycode == XK_A && whether_can_move(&game, game->x_pos_player,
			game->y_pos_player))
		printf("Player moves left!\tStep number : %d\n", game->step);
	else if (keycode == XK_D && whether_can_move(&game, game->x_pos_player,
			game->y_pos_player))
		printf("Player moves right!\tStep number : %d\n", game->step);
	return (0);
}

void	print_step(t_data *game)
{
	mlx_key_hook(game->win_ptr, key_hook, game);
}

int	key_press(int key, t_data **game)
{
	if (key == XK_W)
		move_up(key, game);
	else if (key == XK_S)
		move_down(key, game);
	else if (key == XK_A)
		move_left(key, game);
	else if (key == XK_D)
		move_right(key, game);
	return (0);
}

void	setup_action(t_data **game)
{
	mlx_hook((*game)->win_ptr, 2, 0, key_press, game);
	mlx_hook((*game)->win_ptr, 17, 0, close, game);
}
