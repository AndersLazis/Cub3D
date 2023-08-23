
#include "cub3d.h"

////////////////	ERROR HANDLING	///////////////////
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





////////////////	INIT DATA	///////////////////
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
	data->screen_width = 1200;
	data->screen_heigth = 900;
    data->sky_color = 127;
    data->floor_color = 65;	
	data->tex_width = 64;
	data->tex_height = 64;
    // ----temp POS X & POS Y------
    data->raycasting->pos_x = 5;
    data->raycasting->pos_y = 5;
	//-----------------------------

    data->win = mlx_new_window(data->mlx, data->screen_width, data->screen_heigth, "cub_3d");
	data->raycasting->win = data->win;
	data->texture = (uint32_t **) calloc(sizeof(uint32_t *), 4);//<-replace calloc funct.
	if(data->texture == NULL)
		ft_error(MEMORY_ERROR);
	return (data);
}

void	init_facing_direction(t_data *data)
{  
	if (data->player_direction == 'E')
	{
		data->raycasting->dir_x = -1;
		data->raycasting->plane_y = 0.66;
	}
	if (data->player_direction == 'N')
	{
		data->raycasting->dir_y = -1;
		data->raycasting->plane_x = -0.66;
	}
	if (data->player_direction == 'W')
	{
		data->raycasting->dir_x = 1;
		data->raycasting->plane_y = -0.66;
	}
	if (data->player_direction == 'S')
	{
		data->raycasting->dir_y = 1;
		data->raycasting->plane_x = 0.66;
	}
}




////////////////	INIT MAP	///////////////////
int init_map_data(t_data *data, char *map_adress)
{
    
    int fd;
    char    **map_in_char;
    char    *line;
    int     i;

    fd = open(map_adress, O_RDONLY);
	if(fd == -1)
		ft_error(WRONG_MAP_PATH);
	/*----- ++add map lines counter ---*/
    int lines = 8;
	//-----------------------------------
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
	//-------test print -----------------
	// i = 0;
	// while (i < 8)
	// {
	// 	printf("line =%s", map_in_char[i]);
	// 	i++;
	// }
	//-----------------------------------	
	close(fd);
    return(0);
}

void    fill_map(t_data *data, int i)
{
    int j = 0;
    while ((data->temp_map[i][j] != '\0' && data->temp_map[i][j] != '\n'))
    {
        data->imap[i][j] = data->temp_map[i][j] - '0';
        printf("%d", data->imap[i][j]);
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
	printf("i = %d ", i);
	////////////////////////////////////
    data->imap = malloc(sizeof(int *) * i);
    i = 0;
    j = 0;
    while(data->temp_map[i] != NULL)
    {   
        data->imap[i] = malloc(sizeof(int) * strlen(data->temp_map[i]));
		printf("str %d len: %lu\n", i, strlen(data->temp_map[i]));
        fill_map(data, i);

        i++;
    }
    // //////test int map printing:
    // i = 0;
    // j = 0;
	// while(data->imap[i] != NULL)
	// {
    //     j = 0;
	// 	while(j <  (int)ft_strlen(data->temp_map[i]))
    //     {
    //         printf("%d", data->imap[i][j]);
    //         j++;
    //     }
    //     printf("\n");
	// 	i++;
	// }
    // ///////////////////////
    return (0);
}












////////////////	RAYCASTING	///////////////////
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
            my_mlx_pixel_put(data, x, y, 0x0000ffff);

	}
	while (++y < data->screen_heigth)
	{
		x = -1;
		while (++x < data->screen_width)
            my_mlx_pixel_put(data, x, y, 0x808000);
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
        //printf("i=%d, j=%d, data->raycasting->colr = %d\n", i, j, data->raycasting->colr);
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
        data->raycasting->camera_x = 2 * i / (double)(data->screen_width) - 1; //x-coordinate in camera space
        data->raycasting->ray_dir_x = data->raycasting->dir_x + data->raycasting->plane_x * data->raycasting->camera_x;
        data->raycasting->ray_dir_y = data->raycasting->dir_y + data->raycasting->plane_y * data->raycasting->camera_x;
        data->raycasting->map_x = (int)data->raycasting->pos_x;
        data->raycasting->map_y = (int)data->raycasting->pos_y;
        data->raycasting->deltaDistX = fabs(1 / data->raycasting->ray_dir_x);
        data->raycasting->deltaDistY = fabs(1 / data->raycasting->ray_dir_y);
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








////////////////	MOVEMENTS	///////////////////
static void	move_forward(t_data *data)
{
	t_raycast	*rays;

	rays = data->raycasting;
	if (data->imap[(int)rays->pos_y][(int)(rays->pos_x + rays->dir_x * rays->move_speed)] == 0)
		rays->pos_x += rays->dir_x * rays->move_speed;
	if (data->imap[(int)(rays->pos_y + rays->dir_y * rays->move_speed)][(int)rays->pos_x] == 0)
		rays->pos_y += rays->dir_y * rays->move_speed;
}

static void	move_backward(t_data *data)
{
	t_raycast	*rays;

	rays = data->raycasting;
	if (data->imap[(int)rays->pos_y][(int)(rays->pos_x - rays->dir_x * rays->move_speed)] == 0)
		rays->pos_x -= rays->dir_x * rays->move_speed;
	if (data->imap[(int)(rays->pos_y - rays->dir_y * rays->move_speed)][(int)rays->pos_x] == 0)
		rays->pos_y -= rays->dir_y * rays->move_speed;
}

static void	move_left(t_data *data)
{
	t_raycast	*rays;

	rays = data->raycasting;
	if (data->imap[(int)rays->pos_y][(int)(rays->pos_x - rays->dir_y * rays->move_speed)] == 0)
	rays->pos_x -= rays->dir_y * rays->move_speed;
	if (data->imap[(int)(rays->pos_y + rays->dir_x * rays->move_speed)][(int)rays->pos_x] == 0)
	rays->pos_y += rays->dir_x * rays->move_speed;
}

static void	move_right(t_data *data)
{
	t_raycast	*rays;

	rays = data->raycasting;
	if (data->imap[(int)rays->pos_y][(int)(rays->pos_x + rays->dir_y * rays->move_speed)] == 0)
	rays->pos_x += rays->dir_y * rays->move_speed;
	if (data->imap[(int)(rays->pos_y - rays->dir_x * rays->move_speed)][(int)rays->pos_x] == 0)
	rays->pos_y -= rays->dir_x * rays->move_speed;
}






////////////////	EXIT GAME	///////////////////

int	exit_game(t_data *data)
{
    (void)data;
	//+add free_game(data);
	exit (0);
}




////////////////	UTILS	///////////////////
unsigned int ft_get_time(void)
{
    struct timespec now;

	clock_gettime(CLOCK_MONOTONIC, &now);
	return ((now.tv_sec * 1000) + (now.tv_nsec / 1000000));    
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}





////////////////	KEY HOOKS	///////////////////
void	key_left(t_data *data)
{
	t_raycast	*rays;

	rays = data->raycasting;
	rays->old_dir_x = rays->dir_x;
	rays->dir_x = rays->dir_x * cos(rays->rot_speed) - rays->dir_y * sin(rays->rot_speed);
	rays->dir_y = rays->old_dir_x * sin(rays->rot_speed) + rays->dir_y * cos(rays->rot_speed);
	rays->old_plane_x = rays->plane_x;
	rays->plane_x = rays->plane_x * cos(rays->rot_speed) - rays->plane_y * sin(rays->rot_speed);
	rays->plane_y = rays->old_plane_x * sin(rays->rot_speed) + rays->plane_y * cos(rays->rot_speed);
}

void	key_right(t_data *data)
{
	t_raycast	*rays;

	rays = data->raycasting;
	rays->old_dir_x = rays->dir_x;
	rays->dir_x = rays->dir_x * cos(-rays->rot_speed) - rays->dir_y * sin(-rays->rot_speed);
	rays->dir_y = rays->old_dir_x * sin(-rays->rot_speed) + rays->dir_y * cos(-rays->rot_speed);
	rays->old_plane_x = rays->plane_x;
	rays->plane_x = rays->plane_x * cos(-rays->rot_speed) - rays->plane_y * sin(-rays->rot_speed);
	rays->plane_y = rays->old_plane_x * sin(-rays->rot_speed) + rays->plane_y * cos(-rays->rot_speed);
}

int	keys(int keycode, t_data *data)
{
	t_raycast	*rays;

	rays = data->raycasting;
	rays->oldtime = rays->time;
	rays->time = ft_get_time();
	rays->frametime = (rays->time - rays->oldtime) / 1000.0;
	rays->move_speed = rays->frametime * 20.0;
	rays->rot_speed = rays->frametime * 10.0;
	if (keycode == 13)
		move_forward(data);
	if (keycode == 1)
		move_backward(data);
	if (keycode == 0)
		move_left(data);
	if (keycode == 2)
		move_right(data);
	if (keycode == 124)
		key_right(data);
	if (keycode == 123)
		key_left(data);
	if (keycode == 53)
		exit_game(data);
	return (0);
}





////////////////	MAIN LOOP FUNCTION	///////////////////
int loop_function(t_data *data)
{
    t_raycast	*raycasting;
    
    mlx_clear_window(data->mlx, data->win);
    raycasting = data->raycasting;
    data->raycasting->time = ft_get_time();

    raycasting->img = mlx_new_image(data->mlx, data->screen_width, data->screen_heigth);
    raycasting->img_address = mlx_get_data_addr(raycasting->img, &raycasting->bits_per_pixel, &raycasting->line_length, &raycasting->endian);
    mlx_hook(data->win, 2, 1L << 0, keys, data); 
    draw_floor_n_sky(data);
    render_walls(data);
    mlx_put_image_to_window(data->mlx, data->win, data->raycasting->img, 0, 0);
    mlx_destroy_image(data->mlx, raycasting->img);

    return (0);
}







////////////////	INIT TEXTURES	///////////////////
int	open_textures_and_colors(t_data *data)
{
	/* +add check function for availability of texture file by path from map file */	
	/* +add check function for wrong color code check */
	//--------------for test----------------
	char *NO = "NO";
	char *NO_path = "resources/Wall_01.xpm";
	char *SO = "SO";
	char *SO_path = "resources/Wall_02.xpm";
	char *WE = "WE";
	char *WE_path = "resources/Wall_03.xpm";
	char *EA = "EA";
	char *EA_path = "resources/Wall_04.xpm";
	char *F = "F";
	char *F_color = "220,100,0";
	char *C = "C";
	char *C_color = "225,30,0";
	//--------------------------------------

	if (ft_strncmp(NO, "NO", 3) == 0)
		open_wall_texture(data, &data->northern_wall, NO_path);
	if (ft_strncmp(SO, "SO", 3) == 0)
		open_wall_texture(data, &data->southern_wall, SO_path);
	if (ft_strncmp(WE, "WE", 3) == 0)
		open_wall_texture(data, &data->western_wall, WE_path);
	if (ft_strncmp(EA, "EA", 3) == 0)
		open_wall_texture(data, &data->eastern_wall, EA_path);
	if (ft_strncmp(EA, "EA", 3) == 0)
		open_wall_texture(data, &data->eastern_wall, EA_path);
	if (ft_strncmp(F, "F", 2) == 0)
		convert_color(&data->floor_color, F_color);
	if (ft_strncmp(C, "C", 2) == 0)
		convert_color(&data->sky_color, C_color);	
	return (0);
}

void open_wall_texture(t_data *data, t_image *image, char*	path)
{
	t_image	texture;

	texture.xpm_ptr = mlx_xpm_file_to_image(data->mlx, path, &texture.width, &texture.heigth);
	if (texture.xpm_ptr == NULL)
		ft_error(MEMORY_ERROR);
	*image = texture;
}

void	convert_color(int *color, char	*rgb_code)
{
	char	**colors;
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	colors = ft_split(rgb_code, ',');
	/* free colors */
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);	
	*color = (0 << 24 | r << 16 | g << 8 | b);
	//printf("color:|%x|\n", *color);
}

int	init_textures(t_data *data)
{
	unsigned char	*img_data;
	int bpp;

	img_data = (unsigned char *)mlx_get_data_addr(data->northern_wall.xpm_ptr, &bpp, &data->size_line, &data->raycasting->endian);
	data->texture[0] = (uint32_t *)convert(img_data, data->tex_width, data->tex_height);
	img_data = (unsigned char *)mlx_get_data_addr(data->southern_wall.xpm_ptr, &bpp, &data->size_line, &data->raycasting->endian);
	data->texture[1] = (uint32_t *)convert(img_data, data->tex_width, data->tex_height);
	img_data = (unsigned char *)mlx_get_data_addr(data->western_wall.xpm_ptr, &bpp, &data->size_line, &data->raycasting->endian);
	data->texture[2] = (uint32_t *)convert(img_data, data->tex_width, data->tex_height);
	img_data = (unsigned char *)mlx_get_data_addr(data->eastern_wall.xpm_ptr, &bpp, &data->size_line, &data->raycasting->endian);
	data->texture[3] = (uint32_t *)convert(img_data, data->tex_width, data->tex_height);
	return(0);
}

int	*convert(unsigned char *img_data, int tex_width, int tex_heigth)
{
	int	*int_array;
	int	i;
	int	j;
	int	k;

	i = -1;
	int_array = (int *)malloc(tex_width * tex_heigth * (sizeof(int)));
	if (int_array == NULL)
		ft_error(MEMORY_ERROR);
	while(++i < tex_heigth)
	{
		j = -1;
		while (++j < tex_width)
		{
			k = (i * tex_width + j) * 4;
			int_array[i * tex_width + j] = (img_data[k + 3] << 24) | (img_data[k + 2] << 16) | (img_data[k + 1] << 8) | img_data[k];
		}
	}
	return(int_array);
}










////////////////	MAIN	///////////////////
int main(int ac, char **argv)
{
    t_data	*data;

    (void)ac;  
    data = init_data();
	/* + add check args */
	/* + add check map */
    init_map_data(data, argv[1]);

	//--------temp declaration:---------
	data->player_direction = 'N';
	//----------------------------------

    init_facing_direction(data);  
	//printf("segfault is here - 2\n");
    convert_map(data);
	//printf("segfault is here - 3\n");
	open_textures_and_colors(data);
	init_textures(data);

	mlx_hook(data->win, 17, 1L << 0, exit_game, data);
    mlx_key_hook(data->win, keys, data);
    mlx_loop_hook(data->mlx, loop_function, data);
	mlx_loop(data->mlx);

    return (0);
}
