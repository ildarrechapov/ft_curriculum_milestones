/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: name <name@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:42:11 by name              #+#    #+#             */
/*   Updated: 2021/10/03 15:42:26 by name             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_win	*mlx_create( int width, int height )
{
	t_win	*win;

	win = malloc(sizeof(t_win));
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, width, height, "cube3d!");
	return (win);
}

char	**ft_lstToChar(t_dlist *lst)
{
	t_dlist	*tmp;
	char	**ret;
	int		lenfix;
	int		len;

	tmp = lst;
	if (!lst || !lst->content)
		return (NULL);
	lenfix = (len = ft_lstsizeD(lst)) - 1;
	ret = (char **)malloc(sizeof(char *) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len] = NULL;
	while (len--)
	{
		if (!tmp->content)
			return (NULL);
		ret[lenfix - len] = tmp->content;
		tmp = tmp->next;
	}
	return (ret);
}



bool	game(t_all *all, int width, int height)
{
	t_point	s_img;

	all->win = mlx_create(width, height);
	all->win->img = mlx_xpm_file_to_image(all->win->mlx, all->textures[0], &s_img.x, &s_img.y);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, width / 2, height / 2);
	all->win->img = mlx_xpm_file_to_image(all->win->mlx, all->textures[1], &s_img.x, &s_img.y);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, width / 2 + s_img.x, height / 2);
	return (false);
}