/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:56:23 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/15 07:21:15 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_free_2d_array(char **arr_2d)
{
	int	i;

	i = 0;
	while (arr_2d[i])
	{
		free(arr_2d[i]);
		i++;
	}
	free(arr_2d);
}
