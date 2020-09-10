# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/04 22:48:44 by jremarqu          #+#    #+#              #
#    Updated: 2020/09/10 16:11:40 by jremarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re, lib_refresh

# =========== #
# PUSH_SWAP	  #
# =========== #

PUSH_SWAP_NAME = corewar

PUSH_SWAP_OBJ_DIR = ./objects/

PUSH_SWAP_SRC = $(addprefix $(SRC), $(PUSH_SWAP_SRC_NAME))
PUSH_SWAP_OBJ = $(addprefix $(PUSH_SWAP_OBJ_DIR), $(PUSH_SWAP_OBJ_NAME))

# =========== #
#   OTHER	  #
# =========== #

SRC = ./src/

OBJ_DIR = ./objects/

# =========== #
#	INCLUDES  #
# =========== #

INCLUDES_FILES_LIST =					\
				corewar.h				\
				const.h					\
				op.h					\

INCLUDES_DIR = 	./includes/

INCLUDES_FILES = $(addprefix $(INCLUDES_DIR), $(INCLUDES_FILES_LIST))

# =========== #
# 	LIBFT	  #
# =========== #

LIBFT_DIR =						\
	./libft/includes/			\

LIBFT_MAIN_DIR =				\
	./libft						\

PUSH_SWAP_SRC_NAME = 			\
	corewar_main.c				\
	initialization.c 			\
	parsing.c					\
	adding_player.c				

FLAGS = 	-Wall -Werror -Wextra

PUSH_SWAP_OBJ_NAME = $(PUSH_SWAP_SRC_NAME:.c=.o)

all: $(PUSH_SWAP_NAME)

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJ) $(INCLUDES_FILES)
	@make lib_refresh
	@mkdir -p $(PUSH_SWAP_OBJ_DIR)
	gcc $(FLAGS) -o $(PUSH_SWAP_NAME) $(PUSH_SWAP_OBJ) -lft -L $(LIBFT_MAIN_DIR)

$(PUSH_SWAP_OBJ_DIR)%.o: $(SRC)%.c $(INCLUDES_FILES)
	@mkdir -p $(PUSH_SWAP_OBJ_DIR)
	gcc $(FLAGS) -I$(INCLUDES_DIR) -I$(LIBFT_DIR) -o $@ -c $<

lib_refresh:
	@make -C $(LIBFT_MAIN_DIR)

clean:
	@find . -name ".DS_Store" -delete
	rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_MAIN_DIR)
	# @make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(PUSH_SWAP_NAME)
	@make fclean -C $(LIBFT_MAIN_DIR)
	# @make fclean -C $(LIBFT_DIR)

re: fclean all



# COREWAR_NAME = corewar

# CC = gcc
# FLAGS = -Wall -Wextra -Werror

# COREWAR_LIBRARIES = -lncurses
# COREWAR_INCLUDES = \
# 	-I$(HEADERS_DIR) \
# 	-I$(LIBFT_HED)

# HEADERS_DIR = ./includes/

# COREWAR_INCLUDES = \
# 	-I$(HEADERS_DIR) \
# 	-I$(LIBFT_HED) \

# LIBFT = $(LIBFT_DIR)libft.a
# LIBFT_DIR = ./libft/
# LIBFT_HED = ./libft/includes/

# COREWAR_ALL_HEADERS = \
# 	const.h\
# 	corewar.h \

# COREWAR_HEADERS = $(addprefix $(HEADERS_DIR), $(COREWAR_ALL_HEADERS))

# COREWAR_SOURCES_DIR = ./src/

# COREWAR_ALL_SRCS = \
# 	corewar_main.c \
# 	initialization.c

# COREWAR_SOURCES = $(addprefix $(COREWAR_SOURCES_DIR), $(COREWAR_ALL_SRCS))

# OBJECT_DIRECTORY = ./objects/

# COREWAR_OBJECTS_DIRECTORY = $(OBJECTS_DIRECTORY)corewar/
# COREWAR_OBJECTS_LISTS = $(patsubst %.c, %.o, $(COREWAR_ALL_SOURCES))
# COREWAR_OBJECTS	= $(addprefix $(COREWAR_OBJECTS_DIRECTORY), $(COREWAR_OBJECTS_LISTS))

# .PHONY: all re

# all: $(COREWAR_NAME)

# $(COREWAR_NAME): $(COREWAR_OBJECTS_DIRECTORY) $(COREWAR_OBJECTS)
# 	@$(CC) $(FLAGS) $(COREWAR_LIBRARIES) $(COREWAR_INCLUDES) $(COREWAR_OBJECTS) -o $(COREWAR_NAME)
# 	@echo "\n$(COREWAR_NAME): object files were created"

# re:
# 	@$(MAKE) all
	
