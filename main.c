
#include "cub3d.h"

int ft_error(int error_code)
{
    /*free_data_function*/
    if(error_code == MEMORY_ERROR)
        printf("Error. Program can't allocate memory.");
    else if (error_code == INVALID_MAP)
		 printf("Error. Map is invalid.");
	else if (error_code == WRONG_MAP_PATH)
		 printf("Error. Can't find map.");
	else if (error_code == WRONG_QTY_ARGS)
		 printf("Error. Wrong qty of args.");
    exit(1);
}


#define WRONG_QTY_ARGS  4

t_data *init_data()
{
    t_data *data;
    data = malloc(sizeof(t_data));
	if(data == NULL)
		ft_error(MEMORY_ERROR);
	data->raycasting = calloc(sizeof(t_raycast), 1);
	if (data->raycasting == NULL)
		ft_error(MEMORY_ERROR);
	data->mlx = mlx_init();
	data->raycasting->mlx = data->mlx;
	data->screen_width = 1024;
	data->screen_heigth = 768;
    data->sky_color = 127;
    data->floor_color = 65;
	/*
	data->tex_width = 64;
	data->tex_height = 64;
	//initialize textures
	*/

    // POS X & POS Y
    data->raycasting->pos_x = 1;
    data->raycasting->pos_y = 4;

    data->win = mlx_new_window(data->mlx, data->screen_width, data->screen_heigth, "cub_3d");
	data->raycasting->win = data->win;

	return (data);
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
		data->raycasting->colr = 0x0000ff40;
		if (data->raycasting->side % 2 == 1)
			data->raycasting->colr = data->raycasting->colr / 2;
        printf("i=%d, j=%d, data->raycasting->colr = %d\n", i, j, data->raycasting->colr);
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
        i++;
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
    char    **map_in_char;
    char    *line;
    int     i;
	/* reading_map */
    fd = open(map_adress, O_RDONLY);
	if(fd == -1)
		ft_error(WRONG_MAP_PATH);
	/* ++add map lines counter */
    int lines = 8;
    map_in_char = malloc(sizeof(char *) * (lines + 1));
	if (map_in_char == NULL)
		ft_error(MEMORY_ERROR);

    line = get_next_line(fd);
    map_in_char[0] = line;
   	i = 1;
    while(line)    
    {        
        line = get_next_line(fd);
        map_in_char[i] = line;
        i++;
    }
	map_in_char[i] = NULL;
    data->temp_map= map_in_char; 
	close(fd);
    return(0);
}


void    fill_map(t_data *data, int i)
{
    int j = 0;
    while ((data->temp_map[i][j] != '\0' && data->temp_map[i][j] != '\n'))
    {
        data->imap[i][j] = data->temp_map[i][j] - '0';
        //printf("%d", data->imap[i][j]);
        j++;
    }
}

/* convert map from char to int*/
int convert_map(t_data *data)
{
   int	i, j;

	i = 0;
	/////////TEMPORARY FUNCTION ////////
	/* + add function that will calculate max legth of non-rectangular map */
	/* + add function that will conver non-rectangular map to a rectangular map */
	while (data->temp_map[i])
		i++;
	////////////////////////////////////
    data->imap = malloc(sizeof(int *) * i);
    i = 0;
    j = 0;
    while(data->temp_map[i] != NULL)
    {   
        data->imap[i] = malloc(sizeof(int) * strlen(data->temp_map[i]));
        fill_map(data, i);

        i++;
    }
    //////test map printing:

    i = 0;
    j = 0;
	while(data->temp_map[i] != NULL)
	{
        j = 0;
		while(j < 6)
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
{  
    /* Here should be the full algorithm */
    data->raycasting->dir_x = 1;
    data->raycasting->dir_y = 0;
    data->raycasting->plane_y = 0;
	data->raycasting->plane_x = -0.66;
}


int main(int ac, char **argv)
{
    t_data	*data;

    (void)ac;  
    data = init_data();
	/* + add check args */
	/* + add check map */
    init_map_data(data, argv[1]);
    convert_map(data);
    /*init_map*/   
    
    init_facing_direction(data);   
    /*mlx_hooks*/
    mlx_loop_hook(data->mlx, loop_function, data);
	mlx_loop(data->mlx);

    return (0);
}
