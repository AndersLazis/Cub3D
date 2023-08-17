NAME = main

SOURCES = main.c gnl/get_next_line.c gnl/get_next_line_utils.c 

OBJECTS = $(subst .c,.o,$(SOURCES))

FLAGS = #-Wall -Wextra #-Werror

LINKS = -I libft -L libft \
    -I /usr/local/include -L /usr/local/lib \
    -l mlx -l ft -framework OpenGL -framework Appkit

$(NAME): $(OBJECTS)
	gcc $(SOURCES) -o $(NAME) $(FLAGS) $(LINKS)
