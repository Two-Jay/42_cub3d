
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 22:44:32 by jekim             #+#    #+#              #
#    Updated: 2021/06/03 17:26:49 by jekim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc

INCDIR = ./includes/
OBJDIR = ./obj/
SRCDIR = ./src/
LIBDIR = ./lib/libft/
MLXDIR = ./lib/minilibx_opengl_20191021/
LIBFT_DIR = ./lib/libft/
MAPDIR = ./map/

CCFLAG = -Wall -Wextra -Werror -g3
LIBFLAG = -lmlx -lm -lft -L$(LIBFT_DIR) -L$(MLXDIR) -framework OpenGL -framework AppKit
INCLUDES = -I$(HEAD_DIR) -I$(LIBFT_DIR) -I$(MLXDIR)

LIBFT = $(LIBFT_DIR)libft.a
MINILIBX = $(MLXDIR)libmlx.dylib

SRCFILE = cub3d.c

SRCFILE_OBJ	=	$(SRCFILE:.c=.o)
OBJECTS		=	$(addprefix $(OBJDIR), $(SRCFILE_OBJ))


.PHONY: all re clean fclean

all: $(NAME)

$(OBJDIR)%.o : $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAG) $(INCLUDES) $< -c -o $@

$(NAME)		:	$(OBJECTS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLXDIR)
	@$(CC) $(CCFLAG) $(OBJECTS) $(LIBFLAG) $(INCLUDES) -o $@
	@echo "\033[0;92m* $(NAME) program file was created *\033[0m"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLXDIR) clean
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(MINILIBX)
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

