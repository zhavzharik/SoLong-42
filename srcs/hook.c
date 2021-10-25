/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:29:53 by abridger          #+#    #+#             */
/*   Updated: 2021/10/26 00:04:37 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int key, t_data *game) // for mandatory
{
	if (key == XK_W && game->step - game->prev_step == 1 && !game->end && !game->out)
		printf("Step : %d\n", game->step);
	else if (key == XK_S && game->step - game->prev_step == 1
		&& !game->end && !game->out)
		printf("Step : %d\n", game->step);
	else if (key == XK_A && game->step - game->prev_step == 1
		&& !game->end && !game->out)
		printf("Step : %d\n", game->step);
	else if (key == XK_D && game->step - game->prev_step == 1
		&& !game->end && !game->out)
		printf("Step : %d\n", game->step);
	return (0);
}

// int	key_hook(int key, t_data *game) // for bonus
// {
// 	char	*str;

// 	str = ft_itoa(game->step);
// 	if ((key == XK_W || key == XK_A || key == XK_S || key == XK_D)
// 		&& !game->out && !game->end) // game->step - game->prev_step == 1
// 		mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 20, NAVY, str);
// 	if (str)
// 		free(str);
// 	return (0);
// }

void	escape_game(int key, t_data **game)
{
	if (key == XK_ESCAPE)
	{
		mlx_clear_window((*game)->mlx_ptr, (*game)->win_ptr);
		mlx_destroy_window((*game)->mlx_ptr, (*game)->win_ptr);
		// if (game)
		// {
		// 	printf("escape\n");
		// 	// ft_struct_clear(game);
		// }
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
	else if (key == XK_ESCAPE)
		escape_game(key, game);
	return (0);
}

void	setup_action(t_data **game)
{
	mlx_hook((*game)->win_ptr, 2, 0, key_press, game);
	mlx_key_hook((*game)->win_ptr, key_hook, *game);
	mlx_loop_hook((*game)->mlx_ptr, put_game_end, game);
	mlx_hook((*game)->win_ptr, 17, 0, ft_close, game);
}
