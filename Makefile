# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 01:13:13 by juwkim            #+#    #+#              #
#    Updated: 2023/08/23 22:10:45 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
#    Define the compiler and flags                                             #
# ---------------------------------------------------------------------------- #

CC              :=	cc
CFLAGS          =	-Wall -Wextra -Werror -pipe
CPPFLAGS        =	-I$(PROJECT_DIR)/include -I$(LIBFT)/include -I$(LIBDS)/include -I$(LIBMLX)
DEPFLAGS        =	-MMD -MP -MF $(DEP_DIR)/$*.d
LDFLAGS         =	-L$(LIBFT) -L$(LIBDS) -L$(LIBMLX)
LDLIBS          =	-l$(LIBFT) -l$(LIBDS) -l$(LIBMLX)

ifeq ($(shell uname), Linux)
    LDLIBS      +=	-lXext -lX11 -lm -lz
else
    LDLIBS      +=	-framework OpenGL -framework Appkit
endif

ifdef DEBUG
    CFLAGS      +=	-g -O0 -DDEBUG -march=native -fsanitize=address,undefined
	LDFLAGS     +=	-fsanitize=address,undefined
else
    CFLAGS      +=	-O2 -DNDEBUG
endif

# ---------------------------------------------------------------------------- #
#    Define the libraries                                                      #
# ---------------------------------------------------------------------------- #

LIBFT           :=	ft
LIBDS           :=	ds
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

all: $(LIBFT) $(LIBDS) $(LIBMLX)
	@ $(MAKE) -j $(NAME)

$(NAME): $(OBJS)
	@ $(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)
	@ printf "\n$(MAGENTA)[$(NAME)] Linking Success\n$(WHITE)"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | dir_guard
	@ $(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c $< -o $@
	@ $(eval COMPILED_FILES = $(shell expr $(COMPILED_FILES) + 1))
	@ $(eval PROGRESS = $(shell expr 100 "*" $(COMPILED_FILES) / $(TOTAL_FILES)))
	@ printf "                                                                                                         \r"
	@ printf "$(YELLOW)[$(NAME)] [%02d/%02d] ( %3d %%) Compiling $<\r$(WHITE)" $(COMPILED_FILES) $(TOTAL_FILES) $(PROGRESS)

$(LIBFT):
	@ $(MAKE) -j -C $(LIBFT)

$(LIBDS):
	@ $(MAKE) -j -C $(LIBDS)

$(LIBMLX):
	@ $(MAKE) -j -C $(LIBMLX) 2> /dev/null

clean:
	@ $(MAKE) -C $(LIBFT) clean
	@ $(MAKE) -C $(LIBDS) clean
	@ $(MAKE) -C $(LIBMLX) clean
	@ $(RM) -r mandatory/build bonus/build
	@ printf "$(BLUE)[$(NAME)] obj. dep. files$(WHITE)$(GREEN)	=> Cleaned!\n$(WHITE)"

fclean:
	@ $(MAKE) -C $(LIBFT) fclean
	@ $(MAKE) -C $(LIBDS) fclean
	@ $(MAKE) -C $(LIBMLX) fclean
	@ $(RM) -r mandatory/build bonus/build $(NAME)
	@ printf "$(BLUE)[$(NAME)] obj. dep. files$(WHITE)$(GREEN)	=> Cleaned!\n$(WHITE)"
	@ printf "$(CYAN)[$(NAME)] exec. files$(WHITE)$(GREEN)	=> Cleaned!\n$(WHITE)"

bonus:
	@ $(MAKE) all BONUS=1

re: fclean
	@ $(MAKE) all
	@ printf "$(GREEN)[$(NAME)] Cleaned and rebuilt everything!\n$(WHITE)"

dir_guard:
	@ mkdir -p $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(shell find $(SRC_DIR) -type d))
	@ mkdir -p $(patsubst $(SRC_DIR)/%, $(DEP_DIR)/%, $(shell find $(SRC_DIR) -type d))

norm:
	@ ((norminette $(LIBFT) $(LIBDS) mandatory bonus | grep Error) || (printf "$(GREEN)[$(NAME)] Norminette Success\n$(WHITE)"))

debug: fclean
	@ $(MAKE) all DEBUG=1

test:
	@ ./cub3D asset/test/default.cub

.PHONY: all clean fclean bonus re dir_guard norm debug $(LIBFT) $(LIBDS) $(LIBMLX)

# ---------------------------------------------------------------------------- #
#    Define the colors                                                         #
# ---------------------------------------------------------------------------- #

GRAY            =	\033[1;90m
RED             =	\033[1;91m
GREEN           =	\033[1;92m
YELLOW          =	\033[1;93m
BLUE            =	\033[1;94m
MAGENTA         =	\033[1;95m
CYAN            =	\033[1;96m
WHITE           =	\033[1;97m

-include $(DEPS)
