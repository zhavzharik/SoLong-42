/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:29:53 by abridger          #+#    #+#             */
/*   Updated: 2021/10/25 17:25:30 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_data *game)
{
	if (keycode == XK_W && game->step - game->prev_step == 1 && !game->end)
		printf("Step : %d\n", game->step);
	else if (keycode == XK_S && game->step - game->prev_step == 1
		&& !game->end)
		printf("Step : %d\n", game->step);
	else if (keycode == XK_A && game->step - game->prev_step == 1
		&& !game->end)
		printf("Step : %d\n", game->step);
	else if (keycode == XK_D && game->step - game->prev_step == 1
		&& !game->end)
		printf("Step : %d\n", game->step);
	return (0);
}

// void	print_step(t_data *game)
// {
// 	if (game->step - game->prev_step == 1)
// 		mlx_key_hook(game->win_ptr, key_hook, game);
// }

void	escape_game(int key, t_data **game)
{
	if (key == XK_ESCAPE)
	{
		mlx_clear_window((*game)->mlx_ptr, (*game)->win_ptr);
		mlx_destroy_window((*game)->mlx_ptr, (*game)->win_ptr);
		ft_all_clear(*game);
		exit (0);
	}
}

int	key_press(int key, t_data **game)
{
	if (key == XK_W && !(*game)->end)
		move_up(key, game);
	else if (key == XK_S && !(*game)->end)
		move_down(key, game);
	else if (key == XK_A && !(*game)->end)
		move_left(key, game);
	else if (key == XK_D && !(*game)->end)
		move_right(key, game);
	else if (key == XK_ESCAPE && !(*game)->end)
		escape_game(key, game);
	return (0);
}

void	setup_action(t_data **game)
{
	mlx_hook((*game)->win_ptr, 2, 0, key_press, game);
	mlx_hook((*game)->win_ptr, 17, 0, ft_close, game);
	mlx_key_hook((*game)->win_ptr, key_hook, *game);
	// mlx_loop_hook((*game)->mlx_ptr, put_game_won, game);
	mlx_loop_hook((*game)->mlx_ptr, put_game_end, game);
}
