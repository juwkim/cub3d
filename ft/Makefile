# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 05:18:16 by juwkim            #+#    #+#              #
#    Updated: 2023/08/08 19:47:17 by juwkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
#    Define the compiler and flags                                             #
# ---------------------------------------------------------------------------- #

CC                  :=	cc
CFLAGS              :=	-Wall -Wextra -Werror -pipe
CPPFLAGS            :=	-Iinclude
ARFLAGS             :=	-rcs

ifdef	DEBUG
    CFLAGS          +=	-g -O0 -DDEBUG -march=native -fsanitize=address,undefined
else
    CFLAGS          +=	-O2 -DNDEBUG
endif

# ---------------------------------------------------------------------------- #
#   Define the directories                                                     #
# ---------------------------------------------------------------------------- #

SRC_DIR             :=	ft_ctype ft_math ft_stdio ft_stdlib ft_string ft_strings
OBJ_DIR             :=	object

# ---------------------------------------------------------------------------- #
#   Define the source files                                                    #
# ---------------------------------------------------------------------------- #

SRCS                :=	$(wildcard */*.c)
OBJS                :=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# ---------------------------------------------------------------------------- #
#   Define the variables for progress bar                                      #
# ---------------------------------------------------------------------------- #

TOTAL_FILES         :=	$(shell echo $(SRCS) | wc -w)
COMPILED_FILES      :=	0
STEP                :=	100

# ---------------------------------------------------------------------------- #
#   Define the name                                                            #
# ---------------------------------------------------------------------------- #

NAME                :=	libft.a

# ---------------------------------------------------------------------------- #
#   Define the rules                                                           #
# ---------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^
	@printf "\n$(MAGENTA)[LIBFT] Linking Success\n$(DEF_COLOR)"

$(OBJ_DIR)/%.o: %.c | dir_guard
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	$(eval COMPILED_FILES = $(shell expr $(COMPILED_FILES) + 1))
	$(eval PROGRESS = $(shell expr $(COMPILED_FILES) "*" $(STEP) / $(TOTAL_FILES)))
	@printf "                                                                                                   \r"
	@printf "$(YELLOW)[LIBFT] [%02d/%02d] ( %3d %%) Compiling $<\r$(DEF_COLOR)" $(COMPILED_FILES) $(TOTAL_FILES) $(PROGRESS)

clean:
	@$(RM) -r $(OBJ_DIR)
	@printf "$(BLUE)[LIBFT] obj. files$(DEF_COLOR)$(GREEN)	=> Cleaned!\n$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(CYAN)[LIBFT] exec. files$(DEF_COLOR)$(GREEN)	=> Cleaned!\n$(DEF_COLOR)"

re: fclean
	@$(MAKE) all
	@printf "$(GREEN)Cleaned and Rebuilt everything for libft!\n$(DEF_COLOR)"

dir_guard:
	@mkdir -p $(addprefix $(OBJ_DIR)/, $(SRC_DIR))

norm:
	@(norminette | grep Error) || (printf "$(GREEN)[LIBFT] Norminette Success\n$(DEF_COLOR)")

debug:
	@$(MAKE) fclean
	@$(MAKE) DEBUG=1 all
	
.PHONY:	all clean fclean re dir_guard norm debug

# ---------------------------------------------------------------------------- #
#   Define the colors                                                          #
# ---------------------------------------------------------------------------- #

DEF_COLOR           =	\033[1;39m
GRAY                =	\033[1;90m
RED                 =	\033[1;91m
GREEN               =	\033[1;92m
YELLOW              =	\033[1;93m
BLUE                =	\033[1;94m
MAGENTA             =	\033[1;95m
CYAN                =	\033[1;96m
WHITE               =	\033[1;97m
