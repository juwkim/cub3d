# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 10:26:53 by yeongo            #+#    #+#              #
#    Updated: 2023/07/25 02:45:13 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
#    Define the compiler and flags                                             #
# ---------------------------------------------------------------------------- #

CC					:=	cc
CFLAGS				:=	-Wall -Wextra -Werror
CPPFLAGS			=	-I$(PROJECT_DIR)/include -I$(LIBFT)/include -I$(LIBMLX)
DEPFLAGS			=	-MMD -MP -MF $(DEP_DIR)/$*.d
LDFLAGS				=	-L$(LIBFT) -L$(LIBMLX)
LDLIBS				=	-l$(LIBFT) -l$(LIBMLX)

ifeq ($(shell uname -s), Linux)
	CFLAGS			+=	-Wno-unused-result
	LDLIBS			+= -lXext -lX11 -lm -lz
else
	LDLIBS			+= -framework OpenGL -framework Appkit
endif

ifdef	DEBUG
	CFLAGS			+=	-g -DDEBUG
else
	CFLAGS			+=	-O2 -pipe
endif

# ---------------------------------------------------------------------------- #
#    Define the libraries                                                      #
# ---------------------------------------------------------------------------- #

LIBFT				:=	ft
ifeq ($(shell uname -s), Linux)
	LIBMLX				:=	mlx_Linux
else
	LIBMLX				:=	mlx
endif

# ---------------------------------------------------------------------------- #
#    Define the directories                                                    #
# ---------------------------------------------------------------------------- #

ifdef BONUS
	PROJECT_DIR		:=	bonus
else
	PROJECT_DIR		:=	mandatory
endif

SRC_DIR				:=	$(PROJECT_DIR)/source
BUILD_DIR			:=	$(PROJECT_DIR)/build
OBJ_DIR				:=	$(BUILD_DIR)/object
DEP_DIR				:=	$(BUILD_DIR)/dependency

SRC_CUB_DIR			:=	cub
SRC_MAP_DIR			:=	$(SRC_CUB_DIR)/map
SRC_TSC_DIR			:=	$(SRC_CUB_DIR)/texture_sprite_color
SRC_KEY_DIR			:=	key
SRC_RAYCASTING_DIR	:=	raycasting
SRC_RENDER_DIR		:=	render
SRC_UPDATE_DIR		:=	update
SRC_UTILS_DIR		:=	utils
SRC_WINDOW_DIR		:=	window

# ---------------------------------------------------------------------------- #
#    Define the source files                                                   #
# ---------------------------------------------------------------------------- #

SRCS_ROOT			:= main.c
SRCS_CUB			:= $(addprefix $(SRC_CUB_DIR)/, parse_cub.c)
SRCS_MAP			:= $(addprefix $(SRC_MAP_DIR)/, parse_map.c read_map.c traverse_map.c \
							set_camera.c set_map.c fill.c fill_door.c fill_wall.c trim_map.c)
SRCS_TEX_COLOR		:= $(addprefix $(SRC_TSC_DIR)/, parse_texture_sprite_color.c texture.c sprite.c color.c)
SRCS_KEY			:= $(addprefix $(SRC_KEY_DIR)/, key.c)
SRCS_RAYCASTING		:= $(addprefix $(SRC_RAYCASTING_DIR)/, raycasting.c)
SRCS_RENDER			:= $(addprefix $(SRC_RENDER_DIR)/, render.c)
SRCS_UPDATE			:= $(addprefix $(SRC_UPDATE_DIR)/, update.c move.c rotate.c)
SRCS_UTILS			:= $(addprefix $(SRC_UTILS_DIR)/, _assert.c _atoi.c is_extension.c)
SRCS_WINDOW			:= $(addprefix $(SRC_WINDOW_DIR)/, init_window.c)

SRCS_FILES			= $(SRCS_ROOT) $(SRCS_CUB) $(SRCS_MAP) $(SRCS_TEX_COLOR) \
						$(SRCS_KEY) $(SRCS_RAYCASTING) $(SRCS_RENDER) \
						$(SRCS_UPDATE) $(SRCS_UTILS) $(SRCS_WINDOW)
ifdef BONUS
	SRCS_FILES		:=	$(patsubst %.c, %_bonus.c, $(SRCS_FILES))
endif

SRCS				:=	$(addprefix $(SRC_DIR)/, $(SRCS_FILES))
OBJS				:=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS_FILES))
DEPS				:=	$(patsubst %.c, $(DEP_DIR)/%.d, $(SRCS_FILES))

# ---------------------------------------------------------------------------- #
#    Define the variables for progress bar                                     #
# ---------------------------------------------------------------------------- #

TOTAL_FILES			:=	$(shell echo $(SRCS) | wc -w)
COMPILED_FILES		:=	0
STEP				:=	100

# ---------------------------------------------------------------------------- #
#    Define the target                                                         #
# ---------------------------------------------------------------------------- #

NAME				:=	cub3D

# ---------------------------------------------------------------------------- #
#    Define the rules                                                          #
# ---------------------------------------------------------------------------- #

all:
	@$(MAKE) -C $(LIBMLX)
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -j $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)
	@printf "\n$(MAGENTA)[$(NAME)] Linking Success\n$(DEF_COLOR)"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | dir_guard
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c $< -o $@
	@$(eval COMPILED_FILES = $(shell expr $(COMPILED_FILES) + 1))
	@$(eval PROGRESS = $(shell expr $(COMPILED_FILES) "*" $(STEP) / $(TOTAL_FILES)))
	@printf "                                                                                                         \r"
	@printf "$(YELLOW)[$(NAME)] [%02d/%02d] ( %3d %%) Compiling $<\r$(DEF_COLOR)" $(COMPILED_FILES) $(TOTAL_FILES) $(PROGRESS)

clean:
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBMLX) clean
	@$(RM) -r mandatory/build bonus/build
	@printf "$(BLUE)[$(NAME)] obj. dep. files$(DEF_COLOR)$(GREEN)	=> Cleaned!\n$(DEF_COLOR)"

fclean:
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) fclean
	@$(RM) -r mandatory/build bonus/build $(NAME)
	@printf "$(BLUE)[$(NAME)] obj. dep. files$(DEF_COLOR)$(GREEN)	=> Cleaned!\n$(DEF_COLOR)"
	@printf "$(CYAN)[$(NAME)] exec. files$(DEF_COLOR)$(GREEN)	=> Cleaned!\n$(DEF_COLOR)"

bonus:
	@$(MAKE) BONUS=1 all

re: fclean
	@$(MAKE) all
	@printf "$(GREEN)[$(NAME)] Cleaned and rebuilt everything!\n$(DEF_COLOR)"

dir_guard:
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)
	@mkdir -p $(addprefix $(OBJ_DIR)/, $(SRC_CUB_DIR) $(SRC_MAP_DIR) \
				$(SRC_TSC_DIR) $(SRC_KEY_DIR) $(SRC_RAYCASTING_DIR) \
				$(SRC_RENDER_DIR) $(SRC_UPDATE_DIR) $(SRC_UTILS_DIR) \
				$(SRC_WINDOW_DIR))
	@mkdir -p $(addprefix $(DEP_DIR)/, $(SRC_CUB_DIR) $(SRC_MAP_DIR) \
				$(SRC_TSC_DIR) $(SRC_KEY_DIR) $(SRC_RAYCASTING_DIR) \
				$(SRC_RENDER_DIR) $(SRC_UPDATE_DIR) $(SRC_UTILS_DIR) \
				$(SRC_WINDOW_DIR))

norm:
	@(norminette $(LIBFT) mandatory bonus | grep Error) || (printf "$(GREEN)[$(NAME)] Norminette Success\n$(DEF_COLOR)")

debug:
	@$(MAKE) DEBUG=1 all

.PHONY: all clean fclean bonus re dir_guard norm debug

# ---------------------------------------------------------------------------- #
#    Define the colors                                                         #
# ---------------------------------------------------------------------------- #

DEF_COLOR	=	\033[1;39m
GRAY		=	\033[1;90m
RED			=	\033[1;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[1;94m
MAGENTA		=	\033[1;95m
CYAN		=	\033[1;96m
WHITE		=	\033[1;97m

-include $(DEPS)
