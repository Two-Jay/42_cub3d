
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
MLXDIR = ./lib/minilibx_mms_20210621/
LIBFT_DIR = ./lib/libft/
PARSER_DIR = ./src/parser/
ENGINE_DIR = ./src/engine/
MAPDIR = ./map/
SANIT = -fsanitize=address

CCFLAG = -Wall -Wextra -Werror -g3
MLXFLAG = -lmlx -lm -L$(MLXDIR) -framework OpenGL -framework Appkit -lz
LIBFT_FLAG = -lft -L$(LIBFT_DIR)
LIBFLAG = $(MLXFLAG) $(LIBFT_FLAG) $(LIBVEC_FLAG)
INCLUDES = -I$(HEAD_DIR) -I$(LIBFT_DIR) -I$(MLXDIR)

LIBFT = $(LIBFT_DIR)libft.a
MINILIBX = $(MLXDIR)libmlx.dylib

SRCFILE =	cub3d.c	\
			test_function.c	\
			init.c \
			hooks.c

PARSER_FILE		=	mapparser.c \
					mapparser_img.c	\
					mapparser_mapdata.c \
					mapparser_mapdata_lst.c \
					mapparser_RGB.c \
					mapparser_util.c \
					mapparser_validator.c \
					mapparser_validator_space.c 

ENGINE_FILE		=	draw.c 


SRC_OBJ_FILE	=	$(SRCFILE:.c=.o)
SRC_OBJ	=	$(addprefix $(OBJDIR), $(SRC_OBJ_FILE))

PARSER_OBJ_FILE	=	$(PARSER_FILE:.c=.o)
PARSER_OBJ	=	$(addprefix $(OBJDIR), $(PARSER_OBJ_FILE))

ENGINR_OBJ_FILE	=	$(ENGINE_FILE:.c=.o)
ENGINE_OBJ	=	$(addprefix $(OBJDIR), $(ENGINR_OBJ_FILE))

all: $(NAME)

$(OBJDIR)%.o : $(SRCDIR)%.c
	@mkdir -p obj
	@$(CC) $(CCFLAG) $(INCLUDES) $< -c -o $@

$(OBJDIR)%.o : $(PARSER_DIR)%.c
	@$(CC) $(CCFLAG) $(INCLUDES) $< -c -o $@

$(OBJDIR)%.o : $(ENGINE_DIR)%.c
	@$(CC) $(CCFLAG) $(INCLUDES) $< -c -o $@

$(NAME)		:	$(SRC_OBJ) $(PARSER_OBJ) $(ENGINE_OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLXDIR)
	@$(CC) $(CCFLAG) $(SRC_OBJ) $(PARSER_OBJ) $(ENGINE_OBJ) $(LIBFLAG) $(SANIT) $(INCLUDES) -o $@
	@ln -s ./lib/minilibx_mms_20210621/libmlx.dylib ./libmlx.dylib
	@echo "\033[0;92m* $(NAME) program file was created *\033[0m"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLXDIR) clean
	@rm -rf $(OBJDIR)
	@rm -rf libmlx.dylib

fclean: clean
	@rm -f $(MINILIBX)
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all re clean fclean