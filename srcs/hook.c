/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:29:53 by abridger          #+#    #+#             */
/*   Updated: 2021/10/21 14:55:17 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_data *game)
{
	(void)game;
	if (keycode == XK_W)
		printf("Hello from keyhook press W!\n");
	else if (keycode == XK_S)
		printf("Hello from keyhook press S!\n");
	else if (keycode == XK_A)
		printf("Hello from keyhook press A!\n");
	else if (keycode == XK_D)
		printf("Hello from keyhook press D!\n");
	return (0);
}

void	hook_test(t_data *game)
{
	mlx_key_hook(game->win_ptr, key_hook, game);
	// mlx_hook(game->win_ptr, 2, 1L << 0, close, game);
	// mlx_loop(game->mlx_ptr);
}

// int	close(void *param)
// {
// 	(void) param;
// 	exit (0);
// }

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
	// mlx_hook((*game)->win_ptr, 17, 0, close, game);
}
