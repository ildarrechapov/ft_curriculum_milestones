#include "cub3d.h"

// считаю габариты карты x & y
t_point		map_len(char **maps)
{
	t_point	point;

	point = pnt_s(0);
	while (maps[point.y][point.x])
		point.x++;
	while (maps[point.y])
		point.y++;
	return (point);
}

t_win	*mlx_create( int width, int height )
{
	t_win	*win;

	win = malloc(sizeof(t_win));
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, width, height, "default");
	return (win);
}

void	init_texture(t_all *all)
{
	int i;

	i = -1;
	if (all->textures)
		while (all->textures[++i] && i < 4)
			all->whalls[i] = xpm_to_new_image(all, all->textures[i]);
	while (i < 4)
	{
		all->whalls[i] = new_image(all->win->mlx, pnt_s(100));
		fill_rect_to_img(all->whalls[i], NULL, NULL, create_rgb(all->colors[i]));
		i++;
	}
}

void    init(t_all *all)
{

    all->map_size = map_len(all->map);
	all->win = mlx_create(all->screen_size.x, all->screen_size.y);
	set_background(all);
// Создаю изображение для миниарты
	all->img_map = new_image(all->win->mlx,
		pnt_multiple(all->map_size, pnt_s(SCALE >> 3)));
// Задаю стартовые позиции игрока
	set_plrpos(all);
	set_plr(all, all->plrpos.x - 0.2f, all->plrpos.y - 0.1f, degToRad(0));
// Стены
	init_texture(all);
}