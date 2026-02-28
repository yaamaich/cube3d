NAME = cub3D

NAME_BONUS = cub3D_bonus

LIBFT_DIR = libft

PARSING_DIR = mandatory/parsing
EXEC_DIR = mandatory/execution

PARSING_DIR_BNS = bonus/parsing
EXEC_DIR_BNS = bonus/execution

MLX_DIR = /Users/jhamdaou/Desktop/MLX42

SRCS = mandatory/main.c \
       $(PARSING_DIR)/parse_config.c \
       $(PARSING_DIR)/store_handle.c \
       $(PARSING_DIR)/pconfig_tools.c \
       $(PARSING_DIR)/validate_map.c \
       $(PARSING_DIR)/load_texture.c \
       $(PARSING_DIR)/vmap_tools.c \
       $(PARSING_DIR)/vmap_tools2.c \
       $(PARSING_DIR)/vmap_tools3.c \
       $(EXEC_DIR)/texture.c \
       $(EXEC_DIR)/store_pixels.c \
       $(EXEC_DIR)/raycast.c \
       $(EXEC_DIR)/exec_utils.c \
       $(EXEC_DIR)/handle_movement.c \
       $(EXEC_DIR)/handle_rotation.c \
       $(EXEC_DIR)/if_walkable.c

SRCS_BNS = bonus/main_bonus.c \
       $(PARSING_DIR_BNS)/parse_config_bonus.c \
       $(PARSING_DIR_BNS)/store_handle_bonus.c \
       $(PARSING_DIR_BNS)/pconfig_tools_bonus.c \
       $(PARSING_DIR_BNS)/validate_map_bonus.c \
       $(PARSING_DIR_BNS)/load_texture_bonus.c \
       $(PARSING_DIR_BNS)/vmap_tools_bonus.c \
       $(PARSING_DIR_BNS)/vmap_tools2_bonus.c \
       $(PARSING_DIR_BNS)/vmap_tools3_bonus.c \
       $(EXEC_DIR_BNS)/texture_bonus.c \
       $(EXEC_DIR_BNS)/store_pixels_bonus.c \
       $(EXEC_DIR_BNS)/raycast_bonus.c \
       $(EXEC_DIR_BNS)/exec_utils_bonus.c \
       $(EXEC_DIR_BNS)/handle_movement_bonus.c \
       $(EXEC_DIR_BNS)/handle_rotation_bonus.c \
       $(EXEC_DIR_BNS)/if_walkable_bonus.c


OBJS = $(SRCS:.c=.o)

OBJS_BNS = $(SRCS_BNS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

MLX = $(MLX_DIR)/libmlx42.a


CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I$(LIBFT_DIR) -I$(PARSING_DIR) -I$(MLX_DIR)/include
LDFLAGS = -L$(MLX_DIR) -lmlx42 -L$(LIBFT_DIR) -lft -L/goinfre/jhamdaou/homebrew/Cellar/glfw/3.4/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit

all: $(NAME)
$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

bonus: $(NAME_BONUS)
$(NAME_BONUS): $(OBJS_BNS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS_BNS) $(LDFLAGS) -o $(NAME_BONUS)

%.o: %.c mandatory/includes/cub.h libft/libft.h $(MLX_DIR)/include/MLX42/MLX42.h $(MLX_DIR)/include/MLX42/MLX42_Int
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %_bonus.c bonus/includes/cub_bonus.h libft/libft.h $(MLX_DIR)/include/MLX42/MLX42.h $(MLX_DIR)/include/MLX42/MLX42_Int
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX) :
	@cmake -B $(MLX_DIR)/build -S $(MLX_DIR)
	@cmake --build $(MLX_DIR)/build -j4
	@cp $(MLX_DIR)/build/libmlx42.a $(MLX_DIR)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BNS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@rm -rf $(MLX_DIR)/build
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

libft-re:
	@$(MAKE) -C $(LIBFT_DIR) re

.PHONY: all clean bonus fclean re libft-re
