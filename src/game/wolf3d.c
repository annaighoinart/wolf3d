#include "wolf3d.h"

 int closewin(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

int			key_press(int key, void *param)
{
	t_pr	*w;

	w = (t_pr *)param;
	if (key == 53)
		exit(0);
	if (key == 123 || key == 126 || key == 124 || key == 125 ||
		key == 0 || key == 13 || key == 2 || key == 1)
		move(key, w);
	if (key == 257 || key == 258)
		w->movespeed = 0.3;
	if (key == 17)
		textured(w);
	return (0);
}

int			key_release(int key, void *param)
{
	t_pr	*w;

	w = (t_pr *)param;
	if (key == 257 || key == 258)
		w->movespeed = 0.1;
	return (0);
}

void		setup_controls(t_pr *w)
{
	mlx_hook(w->win_ptr, 2, 0, key_press, w);
	mlx_hook(w->win_ptr, 3, 0, key_release, w);
	mlx_hook(w->win_ptr, 6, 0, mouse_move, w);
	mlx_hook(w->win_ptr, 17, 0, closewin, w);
}

int main(int argc, char **argv)
{
	t_pr	w;
	int 	wid = 64;
	int 	hei = 64;	

	w.win_width = 1024;
	w.win_height = 576;

	w.mlx_ptr = mlx_init();
	w.win_ptr = mlx_new_window(w.mlx_ptr, w.win_width, w.win_height, "wolf3d");
	w.argv = argv[1];
	w.prevxmouse = w.win_width / 2;
	w.movespeed = 0.1;
	w.rotspeed = 0.1;
	w.posx = 3;
	w.posy = 2;
	w.dirx = -1;
	w.diry = 0;
	w.planex = 0;
	w.planey = 0.66;
	w.prevp = 1;
	w.x_text = 0;
	w.textured = 1;
	setup_controls(&w);
	readmap(&w);
	img(&w);
	settextures(&w);
	draw(&w);
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr,
		w.img_ptr, 0, 0);

	mlx_loop(w.mlx_ptr);
}
