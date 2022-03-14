/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 08:20:34 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/14 09:54:25 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_delta_dist(t_math *m)
{
	if (m->raydir_x == 0)
		m->delta_dist_x = 1e30;
	else
		m->delta_dist_x = fabs(1 / m->raydir_x);
	if (m->raydir_y == 0)
		m->delta_dist_y = 1e30;
	else
		m->delta_dist_y = fabs(1 / m->raydir_y);
}

void	put_in_image(t_data *data, int i, int j, int color)
{
	char		*tmp;
	t_texture	*img_t;

	img_t = &data->b_img;
	tmp = img_t->info + (img_t->line_len * i + j * (img_t->bits / 8));
	*(unsigned int *)tmp = color;
}
