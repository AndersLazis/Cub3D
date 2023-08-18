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
    int     colr;



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

#define MEMORY_ERROR    1
#define INVALID_MAP     2
#define WRONG_MAP_PATH  3
#define WRONG_QTY_ARGS  4