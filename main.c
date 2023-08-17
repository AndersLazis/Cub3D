#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
#include <unistd.h>
#include "gnl/get_next_line.h"


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
    double  plane_x;
    double  plane_y;
    double  dir_y;
    double  dir_x;
    double  camera_x;
    double  pos_x;
    double  pos_y;
    double  deltaDistX;
    double  deltaDistY;
    int     hit;
    double ray_dir_x;
    double ray_dir_y;
    int     step_x;
    int     step_y;
    double  side_dist_x;
    double  side_dist_y;
    int     map_x;
    int     map_y;
    int     side;
    double  perp_wall_dist;
    int     line_height;
    int     draw_start;
    int     draw_end;
    int     texnum;
    double  wallx;
    int     texx;
    double  step;
    double  texpos;
    id_t    texy;
    uint32_t colr;



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
    char    player_direction;
    char    **temp_map;
    int     **imap;
    int     tex_width;
    int     tex_height;



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


    // POS X & POS Y
    data->raycasting->pos_x = 3;
    data->raycasting->pos_y = 2;

    

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

void	calc_draw(t_data *data)
{

	data->raycasting->line_height = (int)(data->screen_heigth / data->raycasting->perp_wall_dist);
	data->raycasting->draw_start = -data->raycasting->line_height / 2 + data->screen_heigth / 2;
	if (data->raycasting->draw_start < 0)
		data->raycasting->draw_start = 0;
	data->raycasting->draw_end = data->raycasting->line_height / 2 + data->screen_heigth / 2;
	if (data->raycasting->draw_end >= data->screen_heigth)
		data->raycasting->draw_end = data->screen_heigth - 1;
	data->raycasting->texnum = data->imap[data->raycasting->map_y][data->raycasting->map_x];
	if (data->raycasting->side % 2 == 0)
		data->raycasting->wallx = data->raycasting->pos_y + data->raycasting->perp_wall_dist * data->raycasting->ray_dir_y;
	else
		data->raycasting->wallx = data->raycasting->pos_x + data->raycasting->perp_wall_dist * data->raycasting->ray_dir_x;
	data->raycasting->wallx -= floor((data->raycasting->wallx));
	data->raycasting->texx = (int)(data->raycasting->wallx * (double)data->tex_width);
}







void	draw_walls(t_data *data, int i)
{
	int			j;

	if (data->raycasting->side % 2 == 0 && data->raycasting->ray_dir_x > 0)
		data->raycasting->texx = data->tex_width - data->raycasting->texx - 1;
	if (data->raycasting->side % 2 == 1 && data->raycasting->ray_dir_y < 0)
		data->raycasting->texx = data->tex_width - data->raycasting->texx - 1;
	data->raycasting->step = 1.0 * data->tex_height / data->raycasting->line_height;
	data->raycasting->texpos = (data->raycasting->draw_start - data->screen_heigth / 2 + data->raycasting->line_height / 2) * data->raycasting->step;
	j = data->raycasting->draw_start;
	while (j < data->raycasting->draw_end)
	{
		data->raycasting->texy = (int)data->raycasting->texpos & (data->tex_height - 1);
		data->raycasting->texpos += data->raycasting->step;
		data->raycasting->colr = 100;
		if (data->raycasting->side % 2 == 1)
			data->raycasting->colr = data->raycasting->colr / 2;
		my_mlx_pixel_put(data, i, j, data->raycasting->colr);
		j++;
	}
}









void    render_walls(t_data *data)
{
    int i = 0;

    while(i < data->screen_width)
    {   
        /*init*/
        double cameraX = 2 * i / (double)(data->screen_width) - 1; //x-coordinate in camera space
        double ray_dir_x = data->raycasting->dir_x + data->raycasting->plane_x * cameraX;
        double ray_dir_y = data->raycasting->dir_y + data->raycasting->plane_y * cameraX;
        data->raycasting->map_x = (int)data->raycasting->pos_x;
        data->raycasting->map_y = (int)data->raycasting->pos_y;
        data->raycasting->deltaDistX = fabs(1 / ray_dir_x);
        data->raycasting->deltaDistY = fabs(1 / ray_dir_y);
        data->raycasting->hit = 0;
        /* side_dist x */
        if(data->raycasting->ray_dir_x < 0)
        {
            data->raycasting->step_x = -1;
            data->raycasting->side_dist_x = (data->raycasting->pos_x - data->raycasting->map_x) * data->raycasting->deltaDistX;
        }
        else
        {
            data->raycasting->step_x = 1;
            data->raycasting->side_dist_x = (data->raycasting->map_x + 1.0 - data->raycasting->pos_x) * data->raycasting->deltaDistX;
        }
        /* side_dist y */
        if(data->raycasting->ray_dir_y < 0)
        {
            data->raycasting->step_y = -1;
            data->raycasting->side_dist_y = (data->raycasting->pos_y - data->raycasting->map_y) * data->raycasting->deltaDistY;
        }
        else
        {
            data->raycasting->step_y = 1;
            data->raycasting->side_dist_y = (data->raycasting->map_y + 1.0 - data->raycasting->pos_y) * data->raycasting->deltaDistY;
        }
        /* caclulation of hit */
        while (data->raycasting->hit == 0)
        {   /* check where to go  and side  0 - RH , 2 - LH, 1 - UP, 3 - DWN */
            if(data->raycasting->side_dist_x < data->raycasting->side_dist_y)
            {
                data->raycasting->side_dist_x += data->raycasting->deltaDistX;
                data->raycasting->map_x += data->raycasting->step_x;
                data->raycasting->side = 0;

            }
            else
            {
                data->raycasting->side_dist_y += data->raycasting->deltaDistY;
                data->raycasting->map_y += data->raycasting->step_y;
                data->raycasting->side = 1;
            }
            if(data->imap[data->raycasting->map_y][data->raycasting->map_x] > 0)
                data->raycasting->hit = 1;
        }
        /* check side */
        if(data->raycasting->side == 0)
        {
            if(data->raycasting->map_x > data->raycasting->pos_x)
                data->raycasting->side = 2;
            data->raycasting->perp_wall_dist = (data->raycasting->side_dist_x - data->raycasting->deltaDistX);
        }
        else
        {
            if(data->raycasting->map_y > data->raycasting->pos_y)
                data->raycasting->side = 3;
            data->raycasting->perp_wall_dist = (data->raycasting->side_dist_y - data->raycasting->deltaDistY);
        }
        calc_draw(data);
        draw_walls(data, i);
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
    render_walls(data);
    mlx_put_image_to_window(data->mlx, data->win, data->raycasting->img, 0, 0);
    mlx_destroy_image(data->mlx, raycasting->img);
    /*if (data->minimap_on)
        print_bonus_minimap(data);*/
    return (0);
}




int init_map_data(t_data *data, char *map_adress)
{
    
    int fd;
    char    **res;
    char    *line;
    int     i;

    fd = open(map_adress, O_RDONLY);
    int lines = 10;
    res = malloc(sizeof(char *) * (lines + 1));
    line = get_next_line(fd);
    res[0] = line;
   i = 1;
    while(line)    
    {        
        line = get_next_line(fd);
        res[i] = line;
        i++;
    }
	res[i] = NULL;
	i =0;
    data->temp_map= res;
 
	close(fd);
    return(0);
}

int convert_map(t_data *data)
{
   int	i, j;

	i = 0;
	while (data->temp_map[i])
		i++;
    data->imap = malloc(sizeof(int *) * i);
    i = 0;
    j = 0;
    while(data->temp_map)
    {    
        data->imap[i] = malloc(sizeof(int) * strlen(data->temp_map[i]));
        i = 0;
        j = 0;
        while ((data->temp_map[i][j] != '\0' && data->temp_map[i][j] != '\n'))
        {
        data->imap[i][j] = data->temp_map[i][j] - 0;
        j++;
        }
        i++;
    }
    //////test map printing:
	while(data->imap[i])
	{
		while((data->imap[i][j] != '\0' && data->imap[i][j] != '\n'))
        {
            printf("%d", data->imap[i][j]);
            j++;
        }
        printf("\n");
		i++;
	}
    ///////////////////////
    return (0);
}


void	init_facing_direction(t_data *data)
{   printf("============1===========\n");
    /* Here should be full algorithm */
    data->raycasting->dir_x = 0;
    data->raycasting->dir_y = -1;
    data->raycasting->plane_y = 0;
	data->raycasting->plane_x = -0.66;
    
}


int main(int ac, char **argv)
{

    t_data	*data;
    (void)ac;

    data = malloc(sizeof(t_data));
    init_data(data);
    init_map_data(data, argv[1]);
    convert_map(data);
    /*init_map*/   
    init_facing_direction(data);   
    /*mlx_hooks*/
    mlx_loop_hook(data->mlx, loop_function, data);
	mlx_loop(data->mlx);

    return (0);
}
