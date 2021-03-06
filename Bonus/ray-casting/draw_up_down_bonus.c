/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_up_down_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:35:57 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/27 17:10:28 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	put_cell(t_data *data, t_math *math, int y, int x)
{
	int	*color;
	int	tx;
	int	ty;

	tx = (int)(math->current_floor_x * data->ce_t.width) % \
	data->ce_t.width;
	ty = (int)(math->current_floor_y * data->ce_t.hight) % \
	data->ce_t.hight;
	color = (int *)(data->ce_t.info + ((data->ce_t.line_len * ty) + \
	(tx * (data->ce_t.bits / 8))));
	put_in_image(data, WINDOW_HIEGHT - y, x, \
	add_darck(*color, math->current_dist));
}

void	put_floor(t_data *data, t_math *math, int y, int x)
{
	int	*color;
	int	tx;
	int	ty;

	tx = (int)(math->current_floor_x * data->fl_t.width) % \
	data->fl_t.width;
	ty = (int)(math->current_floor_y * data->fl_t.hight) % \
	data->fl_t.hight;
	color = (int *)(data->fl_t.info + ((data->fl_t.line_len * ty) + \
	(tx * (data->fl_t.bits / 8))));
	put_in_image(data, y, x, \
	add_darck(*color, math->current_dist));
}

void	start_drawing_up_down(t_data *data, t_math *math, int x)
{
	float	weight;
	int		y;

	y = math->draw_end + 1;
	while (++y < WINDOW_HIEGHT)
	{
		math->current_dist = WINDOW_HIEGHT / (2.0 * y - WINDOW_HIEGHT);
		weight = (math->current_dist - math->dist_player) / \
		(math->dist_wall - math->dist_player);
		math->current_floor_x = weight * math->floor_x_wall + \
		(1.0 - weight) * data->pl.pos_x;
		math->current_floor_y = weight * math->floor_y_wall + \
		(1.0 - weight) * data->pl.pos_y;
		put_floor(data, math, y, x);
		put_cell(data, math, y, x);
	}
}

void	draw_up_down(t_data *data, t_math *math, int x)
{
	if (math->side == 0 && math->raydir_x > 0)
	{
		math->floor_x_wall = math->map_x;
		math->floor_y_wall = math->map_y + math->wall_x;
	}
	else if (math->side == 0 && math->raydir_x < 0)
	{
		math->floor_x_wall = math->map_x + 1.0;
		math->floor_y_wall = math->map_y + math->wall_x;
	}
	else if (math->side == 1 && math->raydir_y > 0)
	{
		math->floor_x_wall = math->map_x + math->wall_x;
		math->floor_y_wall = math->map_y;
	}
	else
	{
		math->floor_x_wall = math->map_x + math->wall_x;
		math->floor_y_wall = math->map_y + 1.0;
	}
	math->dist_wall = math->perp_wall_dist;
	math->dist_player = 0.0;
	start_drawing_up_down(data, math, x);
}
