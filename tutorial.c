#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
 #include <string.h>

/*  Header file */
typedef struct s_raycast
{   
    void	*mlx;
    void    *win;
    void    *img;
    char    *img_address;
    int     bits_per_pixel;
    int     line_length;
    int     endian;



}   t_raycast;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    int     screen_heigth;
    int     screen_width;

    int     sky_color;
    int     floor_color;
    char    *win_title;

    t_raycast *raycasting;


}   t_data;



/*=======================================================================*/


int init_data(t_data	*data)
{
	data->raycasting = calloc(sizeof(t_raycast), 1);
	if (data->raycasting == NULL)
		return (-1);
	data->mlx = mlx_init();
	data->raycasting->mlx = data->mlx;
	data->screen_width = 800;
	data->screen_heigth = 600;
    data->sky_color = 127;
    data->floor_color = 65;
    data->win_title = strdup("cub3d");

	data->win = mlx_new_window(data->mlx, data->screen_width, data->screen_heigth, "Game");
	data->raycasting->win = data->win;

	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->raycasting->img_address + (y * data->raycasting->line_length + x * (data->raycasting->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void	draw_floor_n_sky(t_data *data)
{
	int		y;
	int		x;

	y = -1;
    printf("data->sky:%d\n", data->sky_color);
    
	while (++y < data->screen_heigth/2)
	{
		x = -1;
		while (++x < data->screen_width)
            my_mlx_pixel_put(data, x++, y, 0x0000ffff);
			//mlx_pixel_put(data->mlx, data->win, x++, y, data->sky_color);
	}
	while (++y < data->screen_heigth)
	{
		x = -1;
		while (++x < data->screen_width)
            my_mlx_pixel_put(data, x++, y, 0x0000ff40);
			//mlx_pixel_put(data->mlx, data->win, x++, y, data->floor_color);
	}
}






int loop_function(t_data *data)
{
    t_raycast	*raycasting;

    mlx_clear_window(data->mlx, data->win);
    raycasting = data->raycasting;
    //printf("var%d\n", (int)data->raycasting->img);
    
    raycasting->img = mlx_new_image(data->mlx, data->screen_width, data->screen_heigth);
    raycasting->img_address = mlx_get_data_addr(raycasting->img, &raycasting->bits_per_pixel, &raycasting->line_length, &raycasting->endian);
    draw_floor_n_sky(data);
    /*ft_raycasting(data);*/
    mlx_put_image_to_window(data->mlx, data->win, data->raycasting->img, 0, 0);
    mlx_destroy_image(data->mlx, raycasting->img);
    /*if (data->minimap_on)
        print_bonus_minimap(data);*/
    return (0);
}







int main()
{

    t_data	*data;

    data = malloc (sizeof(t_data));
    if(data == NULL)
        return (-1);
    init_data(data);
 
    mlx_loop_hook(data->mlx, loop_function, data);
	mlx_loop(data->mlx);

    return (0);
}
