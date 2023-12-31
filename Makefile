NAME			=	cub3D

CC				=	gcc

CFLAGS			=	-g -Wall -Wextra -Werror #-fsanitize=address

RM				=	rm -rf

HEADER			=	incl/cub3d.h

LIBFT			=	-L libft -lft

INCLUDE			=	-I minilibx -L mlx -lmlx -framework OpenGL -framework AppKit #-fsanitize=address

#colors
DEF_COLOR		=	\033[0;39m
ORANGE			=	\033[0;33m
GREY			=	\033[0;90m
RED				=	\033[0;91m
GREEN			=	\033[1;92m
YELLOW			=	\033[1;93m
BLUE			=	\033[0;94m
MAGENTA			=	\033[0;95m
CYAN			=	\033[0;96m
WHITE			=	\033[0;97m

MAIN			=	doublelst free_utils init_data main split01 util01 util02 \
					handle_keys update_param ft_raycaster ft_raycaster_02 ft_render

CHECK_MAP		=	check_cub convert_colors element_map parsing_map \
					read_cub read_cub_util01 read_cub_util02 take_cub

MAIN_BONUS		=	doublelst_bonus free_utils_bonus init_data_bonus main_bonus split01_bonus util01_bonus util02_bonus \
					handle_keys_bonus update_param_bonus ft_raycaster_bonus ft_raycaster_02_bonus ft_render_bonus \
					render_sprites_bonus render_sprites_02_bonus ft_minimap_bonus ft_minimap_02_bonus

CHECK_MAP_BONUS	=	check_cub_bonus convert_colors_bonus element_map_bonus parsing_map_bonus \
					read_cub_bonus read_cub_util01_bonus read_cub_util02_bonus take_cub_bonus 

SRCS			=	$(addsuffix .c, $(addprefix srcs/, $(MAIN))) \
					$(addsuffix .c, $(addprefix srcs/check_map/, $(CHECK_MAP))) \

SCRS_BONUS		=	$(addsuffix .c, $(addprefix srcs_bonus/, $(MAIN_BONUS))) \
					$(addsuffix .c, $(addprefix srcs_bonus/check_map/, $(CHECK_MAP_BONUS)))

OBJS			=	$(SRCS:c=o)

OBJS_BONUS		=	$(SCRS_BONUS:c=o)

all:			$(NAME)

$(NAME):		$(OBJS)
				@echo "\n"
				@make all -C mlx
				@make -C libft/
				@echo "$(YELLOW)compiling cub3d...$(DEF_COLOR)"
				@$(CC)  $(OBJS) -o $(NAME) $(INCLUDE) $(LIBFT)
				@echo "$(GREEN)cub3d - ready to play$(DEF_COLOR)"

bonus:			$(OBJS_BONUS)
				@echo "\n"
				@make all -C mlx
				@make -C libft/
				@echo "$(YELLOW)compiling cub3d bonus...$(DEF_COLOR)"
				@$(CC)  $(OBJS_BONUS) -o $(NAME) $(INCLUDE) $(LIBFT)
				@echo "$(GREEN)cub3d - ready to play$(DEF_COLOR)"

%.o:			%.c
					@printf "$(BLUE)creating objects for cub3d... %-33.33s\r" $@
					@$(CC) $(CFLAGS) -c $< -o $@

norm:
				@echo "$(CYAN)Checking the Norm..."
				@sleep 1
				@norminette srcs/ srcs_bonus/ incl/
				@echo "$(DEF_COLOR)"

fclean:
					@echo "$(GREY)cleaning all...$(DEF_COLOR)"
					@make fclean -C libft/
					@make clean -C mlx/
					@$(RM) $(OBJS)
					@$(RM) $(OBJS_BONUS)
					@$(RM) $(NAME)
					@$(RM) cub3d.dSYM
					@echo "$(GREY)Done!$(DEF_COLOR)"

re:				fclean all