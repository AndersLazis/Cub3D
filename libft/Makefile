# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 13:35:08 by tstrassb          #+#    #+#              #
#    Updated: 2023/03/06 09:22:37 by tstrassb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL			=		/bin/bash

#standard

NAME			=		libft.a
INCLUDE			=		include/
SRC_DIR			=		sources/
OBJ_DIR			=		object/
CC				=		cc
CFLAGS			=		-Wall -Werror -Wextra -I
RM				=		rm -f
AR				=		ar rcs
ECHO			=		echo -e

#colors

DEF_COLOR		=		\033[0;39m
ORANGE			=		\033[0;33m
GRAY			=		\033[0;90m
RED				=		\033[0;91m
GREEN			=		\033[1;92m
YELLOW			=		\033[1;93m
BLUE			=		\033[0;94m
MAGENTA			=		\033[0;95m
CYAN			=		\033[0;96m
WHITE			=		\033[0;97m

#sources

FTIS_DIR		=		ft_is/
FTIS			=		ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint

FTMEM_DIR		=		ft_mem/
FTMEM			=		ft_bzero ft_calloc ft_memchr ft_memcmp ft_memmove ft_memset

FTPUT_DIR		=		ft_put/
FTPUT			=		ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd tables

FTTO_DIR		=		ft_to/
FTTO			=		ft_atoi ft_itoa ft_tolower ft_toupper

FTSTR_DIR		=		ft_str/
FTSTR			=		ft_split ft_strchr ft_strdup ft_striteri ft_strjoin \
						ft_strlcat ft_strlcpy ft_strmapi ft_strncmp \
						ft_strnstr ft_strrchr ft_strtrim ft_substr ft_strlen

FTLST_DIR		=		ft_lst/
FTLST			=		ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone \
						ft_lstiter ft_lstlast ft_lstmap ft_lstnew ft_lstsize

FTPRINTF_DIR	=		ft_printf/
FTPRINTF		=		ft_choose_convers ft_convers_needed ft_convers_selection \
						ft_printf_needed ft_printf ft_put_needed

GNL_DIR			=		gnl/
GNL				=		get_next_line get_next_line_utils

SRC_FILES+=$(addprefix $(FTIS_DIR),$(FTIS))
SRC_FILES+=$(addprefix $(FTMEM_DIR),$(FTMEM))
SRC_FILES+=$(addprefix $(FTPUT_DIR),$(FTPUT))
SRC_FILES+=$(addprefix $(FTTO_DIR),$(FTTO))
SRC_FILES+=$(addprefix $(FTSTR_DIR),$(FTSTR))
SRC_FILES+=$(addprefix $(FTLST_DIR),$(FTLST))
SRC_FILES+=$(addprefix $(FTPRINTF_DIR),$(FTPRINTF))
SRC_FILES+=$(addprefix $(GNL_DIR),$(GNL))

SRC				=		$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ				=		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF			=		.cache_exists

start:
						@echo -e -n "$(ORANGE)[LIBFT]:$(DEF_COLOR)"
						@echo -e -n "$(BLUE)[$(DEF_COLOR)"
						@make all

all:			$(NAME)

$(NAME):		$(OBJ)
						@$(AR) $(NAME) $(OBJ)
						@echo -e -n "$(BLUE)]$(DEF_COLOR)"
						@$(ECHO) " ==> $(GREEN)100%$(DEF_COLOR)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
						@$(ECHO) -n "$(ORANGE)=$(DEF_COLOR)"
						@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
						@mkdir -p $(OBJ_DIR)
						@mkdir -p $(OBJ_DIR)$(FTIS_DIR)
						@mkdir -p $(OBJ_DIR)$(FTMEM_DIR)
						@mkdir -p $(OBJ_DIR)$(FTPUT_DIR)
						@mkdir -p $(OBJ_DIR)$(FTTO_DIR)
						@mkdir -p $(OBJ_DIR)$(FTSTR_DIR)
						@mkdir -p $(OBJ_DIR)$(FTLST_DIR)
						@mkdir -p $(OBJ_DIR)$(FTPRINTF_DIR)
						@mkdir -p $(OBJ_DIR)$(GNL_DIR)
						@touch $(OBJF)

clean:
						@$(RM) -r $(OBJ_DIR)
						@$(RM) $(OBJF)
						@$(ECHO) -n "$(BLUE)[LIBFT]:\t.o files$(DEF_COLOR) ==> $(RED)removed!$(DEF_COLOR)\n"

fclean:				clean
						@$(RM) $(NAME)
						@$(ECHO) -n "$(CYAN)[LIBFT]:\tprogram file$(DEF_COLOR) ==> $(RED)removed!$(DEF_COLOR)\n"

re:						fclean all
						@$(ECHO) -n "$(GRAY)[LIBFT] rebuilt!$(DEF_COLOR)\n"

.PHONY:				all clean fclean re