NAME 		=	Cub3D

NAME_LIB 	=	Cub3D.a

OS			=	$(shell uname)

INCLUDE		=	-I/includes

INCLUDELBFT	=	-I/libft
LIBMLIBFT	=	./libft/libft.a

SRCS_NAME = 	main \
		parsing/dst/check_depth_search \
		parsing/dst/check_depth_search_tools \
		parsing/init_cub_file \
		parsing/init_cub_file_tools \
		parsing/errors \
		parsing/errors2 \
		parsing/read_map \
		parsing/read_tex \
		parsing/read_tex_tools \
		parsing/init_cub3d \
		engine/movment/moving_engine \
		engine/movment/moving_engine_directions \
		engine/casting_engine \
		engine/casting_engine_tools \
		engine/casting_floor \
		engine/casting_wall \
		engine/casting_sprite \
		engine/casting_sprite_tools \
		engine/keyboard/keyboard_input \
		engine/keyboard/keyboard_keys \
		engine/cub3d_tools \
		tools/close_cub3d \
		tools/make_screenshot \

ifeq ($(OS), Linux)
	LIBFILE		= ./minilibx_linux
	INCLUDEMLX	= -I/minilibx_linux/mlx.h
	LIBMLX		= ./minilibx_linux/libmlx.a
	FLAG		= -Wall -Werror -Wextra -lm -lXext -lX11
	SRCS_NAME	+= parsing/read_res_linux
	SRCS_NAME	+= parsing/init_textures_linux


else
	LIBFILE		= ./minilibx_macos
	INCLUDEMLX	= -I/minilibx_macos/mlx.h
	LIBMLX		= ./minilibx_macos/libmlx.a
	FLAG		= -Wall -Werror -Wextra -lz -framework OpenGL -framework AppKit
	SRCS_NAME	+= parsing/read_res_osx
	SRCS_NAME	+= parsing/init_textures_osx

endif

CC			=	clang

SRCS_DIR	=	./src/
SRCS		=	$(addsuffix .c, $(addprefix $(SRCS_DIR), $(SRCS_NAME)))
OBJS		=	$(SRCS:.c=.o)
SRCS_B_DIR	= 	./src_bonus/
SRCS_B		=	$(addsuffix _bonus.c, $(addprefix $(SRCS_B_DIR), $(SRCS_NAME)))
OBJS_B		=	$(SRCS_B:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		@make -C libft
		@make -C $(LIBFILE)
		@ar rcs $(NAME_LIB) $(OBJS)
		@$(CC) -o $(NAME) $(INCLUDE) $(INCLUDEMLX) $(INCLUDELBFT) $(OBJS) $(LIBMLX) $(LIBMLIBFT) $(FLAG)

clean:
		@make clean -C libft
		@make clean -C $(LIBFILE)
		@rm -rf $(OBJS) $(OBJS_B)

fclean:	clean
		@make fclean -C libft
		@make clean -C $(LIBFILE)
		@rm -rf $(NAME)
		@rm -rf $(NAME_LIB)

re:		fclean all

bonus: fclean $(OBJS_B)
		@echo "\n\033[0;32mCompiling bonus..."
		@make -C libft
		@make -C $(LIBFILE)
		@ar rcs $(NAME_LIB) $(OBJS_B)
		@$(CC) -o $(NAME) $(INCLUDE) $(INCLUDEMLX) $(INCLUDELBFT) $(OBJS_B) $(LIBMLX) $(LIBMLIBFT) $(FLAG) $(KEY)
		@echo "\033[0m"

.PHONY : all clean fclean re
