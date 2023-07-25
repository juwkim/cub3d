# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 10:26:53 by yeongo            #+#    #+#              #
#    Updated: 2023/07/25 22:09:37 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
#    Define the compiler and flags                                             #
# ---------------------------------------------------------------------------- #

CC              :=	cc
CFLAGS          =	-Wall -Wextra -Werror -pipe
CPPFLAGS        =	-I$(PROJECT_DIR)/include -I$(LIBFT)/include -I$(LIBMLX)
DEPFLAGS        =	-MMD -MP -MF $(DEP_DIR)/$*.d
LDFLAGS         =	-L$(LIBFT) -L$(LIBMLX)
LDLIBS          =	-l$(LIBFT) -l$(LIBMLX)

ifeq ($(shell uname), Linux)
	LDLIBS      +=	-lXext -lX11 -lm -lz
else
	LDLIBS      +=	-framework OpenGL -framework Appkit
endif

ifdef DEBUG
	CFLAGS      +=	-g -O0 -DDEBUG -march=native -fsanitize=address,leak,undefined
else
	CFLAGS      +=	-O2 -DNDEBUG
endif

# ---------------------------------------------------------------------------- #
#    Define the libraries                                                      #
# ---------------------------------------------------------------------------- #

LIBFT           :=	ft
ifeq ($(shell uname -s), Linux)
	LIBMLX      :=	mlx_Linux
else
	LIBMLX      :=	mlx
endif

# ---------------------------------------------------------------------------- #
#    Define the directories                                                    #
# ---------------------------------------------------------------------------- #

ifdef BONUS
	PROJECT_DIR :=	bonus
else
	PROJECT_DIR :=	mandatory
endif

SRC_DIR         :=	$(PROJECT_DIR)/source
BUILD_DIR       :=	$(PROJECT_DIR)/build
OBJ_DIR         :=	$(BUILD_DIR)/object
DEP_DIR         :=	$(BUILD_DIR)/dependency

# ---------------------------------------------------------------------------- #
#    Define the source files                                                   #
# ---------------------------------------------------------------------------- #

SRCS            :=	$(shell find $(SRC_DIR) -name *.c)
OBJS            :=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
DEPS            :=	$(patsubst $(SRC_DIR)/%.c, $(DEP_DIR)/%.d, $(SRCS))

# ---------------------------------------------------------------------------- #
#    Define the variables for progress bar                                     #
# ---------------------------------------------------------------------------- #

TOTAL_FILES     :=	$(shell echo $(SRCS) | wc -w)
COMPILED_FILES  :=	0

# ---------------------------------------------------------------------------- #
#    Define the target                                                         #
# ---------------------------------------------------------------------------- #

NAME            :=	cub3D

# ---------------------------------------------------------------------------- #
#    Define the rules                                                          #
# ---------------------------------------------------------------------------- #

all: $(LIBFT) $(LIBMLX)
	@$(MAKE) -j $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)
	@printf "\n$(MAGENTA)[$(NAME)] Linking Success\n$(DEF_COLOR)"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | dir_guard
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c $< -o $@
	@$(eval COMPILED_FILES = $(shell expr $(COMPILED_FILES) + 1))
	@$(eval PROGRESS = $(shell expr 100 "*" $(COMPILED_FILES) / $(TOTAL_FILES)))
	@printf "                                                                                                         \r"
	@printf "$(YELLOW)[$(NAME)] [%02d/%02d] ( %3d %%) Compiling $<\r$(DEF_COLOR)" $(COMPILED_FILES) $(TOTAL_FILES) $(PROGRESS)

$(LIBFT):
	@$(MAKE) -j -C $(LIBFT)

$(LIBMLX):
	@$(MAKE) -j -C $(LIBMLX)

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
	@$(MAKE) all BONUS=1

re: fclean
	@$(MAKE) all
	@printf "$(GREEN)[$(NAME)] Cleaned and rebuilt everything!\n$(DEF_COLOR)"

dir_guard:
	@mkdir -p $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(shell find $(SRC_DIR) -type d))
	@mkdir -p $(patsubst $(SRC_DIR)/%, $(DEP_DIR)/%, $(shell find $(SRC_DIR) -type d))

norm:
	@(norminette $(LIBFT) mandatory bonus | grep Error) || (printf "$(GREEN)[$(NAME)] Norminette Success\n$(DEF_COLOR)")

debug: fclean
	@$(MAKE) all DEBUG=1

.PHONY: all clean fclean bonus re dir_guard norm debug $(LIBFT) $(LIBMLX)

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
