/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 09:05:45 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/13 10:57:25 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <printf.h>

void	rotate_player(t_data *data, double i)
{
	t_player	*p;
	double		old_dir_x;
	double		old_plane_x;

	p = &data->pl;
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(ROT_SPEED * i) - p->dir_y * sin(ROT_SPEED * i);
	p->dir_y = old_dir_x * sin(ROT_SPEED * i) + p->dir_y * cos(ROT_SPEED * i);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(ROT_SPEED * i) - \
	p->plane_y * sin(ROT_SPEED * i);
	p->plane_y = old_plane_x * sin(ROT_SPEED * i) + \
	p->plane_y * cos(ROT_SPEED * i);
}

void	move_player(t_data *data, double x, double y)
{
	t_player	*p;
	double		tmp_x;
	double		tmp_y;

	p = &data->pl;
	tmp_x = p->pos_x + p->dir_x * x * MOVE_SPEED;
	tmp_y = p->pos_y + p->dir_y * y * MOVE_SPEED;
	if (data->map[(int)tmp_y][(int)tmp_x] == '0')
	{
		p->pos_x = tmp_x;
		p->pos_y = tmp_y;
	}
}