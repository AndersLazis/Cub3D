# Cub3D

<p align="center">
  <img src="https://github.com/AndersLazis/AndersLazis/blob/main/assets/covers/cover-cub3d-bonus.png" alt="Cub3D 42 project cover"/>
</p>

Cub3D is a 42 school team project to create a dynamic view inside a 3D maze. Using the [MiniLibX library](https://github.com/42Paris/minilibx-linux), we must implement raycasting in the style of the famous [Wolfenstein 3D](http://users.atw.hu/wolf3d/) game, the first true FPS in videogame history.
## Status

Validated 31 Aug 2023. Grade: 125%.
<p align="center">
  <img src="https://github.com/AndersLazis/Cub3D/blob/master/resources/screen1.png" alt="Cub3D 42 project screenshot 1" width="50%"/>
  <img src="https://github.com/AndersLazis/Cub3D/blob/master/resources/screen2.png" alt="Cub3D 42 project screenshot 2" width="50%"/>
</p>

## Usage
MiniLibX library must be preinstalled.
Clone the repository:

```shell
git clone https://github.com/AndersLazis/Cub3D.git
```
## Compile and Run

There are two versions of the program, the mandatory part and the bonus part. The bonus part adds wall collision, a minimap, and the ability to rotate the view by moving the mouse.

To compile the mandatory part, `cd` into the cloned directory and:

```shell
make
```

To compile the bonus part, `cd` into the cloned directory and:

```shell
make bonus
```
Note: you may need to `make fclean` to switch between the mandatory and bonus compilations (working on a fix for this!).


To run the program:

```shell
./cub3d <path/to/map.cub>
```

The program takes a map file as an argument. Maps are available in the `maps` directory. There are good maps which the program should run smoothly with, and bad maps which the program should reject.
For example:

- `./cub3d maps/map_1.cub` should run.

## Controls

Controls for movement and rotation are:

- `W`: move forward
- `S`: move backward
- `A`: strafe left
- `D`: strafe right
- `left arrow`: rotate left
- `right arrow`: rotate right
- `mouse`: rotate by moving the mouse (bonus only)

## Useful Resources

Useful resources for this project are:

- Minilibx: [hsmits MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- Minilibx: [gontjarow's MiniLibX tutorial](https://gontjarow.github.io/MiniLibX/)
- Xlib (for MLX events): [The Xlib Manual](https://tronche.com/gui/x/xlib/)
- Raycasting: [Lode's Computer Graphics Tutorial - Raycasting](https://lodev.org/cgtutor/raycasting.html)
- Raycasting: [Permadi's Raycasting tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
- Movement: [Calculating heading in 2d games: Using trigonometric functions part 1](http://gamecodeschool.com/essentials/calculating-heading-in-2d-games-using-trigonometric-functions-part-1/)
