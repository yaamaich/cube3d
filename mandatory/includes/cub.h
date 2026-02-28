/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:10:50 by aamddah           #+#    #+#             */
/*   Updated: 2025/10/03 12:10:50 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include "/Users/jhamdaou/Desktop/MLX42/include/MLX42/MLX42.h"
#include "../../libft/libft.h"

#define WIN_W 1024
#define WIN_H 600

#define PI 3.14159265359

#define MOVE_SPEED 0.05
#define ROT_SPEED 0.05

typedef struct s_pixel 
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
}	t_pixel;

typedef struct s_config
{
	char	*north_texture_path;
	char	*south_texture_path;
	char	*west_texture_path;
	char	*east_texture_path;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		ceiling_r;
	int		ceiling_g;
	int		ceiling_b;
	int		config_count;
}	t_config;

typedef struct s_texture
{
	uint32_t	**arr;
	int			width;
	int			height;
}	t_texture;

typedef struct s_data
{
	int				x;
	int				y;
	char			**map;
	char			*map_path;
	int				line_count;
	int				fd;
	t_config		*config;
	mlx_texture_t	*texs[4];
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				screenwidth;
	int				screenheight;
	t_texture		walls_textures[4];
	double			playerx;
	double			playery;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	float			pos_x;
	float			pos_y;
	float			angle;
	float			fov;
	float			ray_angle;
	float			ray_rad;
	float			ray_dir_x;
	float			ray_dir_y;
	float			perp_wall_dist;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				side;
	float			delta_x;
	float			delta_y;
	float			side_dist_x;
	float			side_dist_y;
	float			angle_step;
	float			start_angle;
	float			wall_distance;
	bool			hit;
	int				texx;
	float			wall_height;
	int				texnum;
	int				draw_start;
	int				draw_end;
	double			move_speed;
	double			angle_rad;
	double			rotation_speed;
	double			dx;
	double			dy;
	int32_t			prev_mouse_x;
	int32_t			prev_mouse_y;
	double			mouse_sensitivity;
	int32_t			window;
	mlx_image_t		*image;
}	t_data;

void	ft_free(char **ptr);
int		is_valid_elem(char c);
int		is_config(char *line);
int		empty_line(char *line);
int		check_color(char *line);
int		is_map_line(char *line);
int		longest_line(char **map);
void	init_array(int array[4][2]);
int		ft_init_image(t_data *game);
int		check_border_line(char *line);
void	free_config(t_config *config);
int		is_spawning_orientation(char c);
void	free_map(char **map, int lines);
char	**map_to_array(t_data *data_prs);
int		is_config_complete(t_config *config);
void	check_name(char *str, t_data *data_prs);
int		validate_map(char **map, int max_lines);
char	*get_trimmed(char *line, char **trimmed);
int		parse_config(char *line, t_config *config);
int		handle_map(char *trimmed, t_data *data_prs);
int		count_spawn_points(char **map, int max_lines);
int		check_config_done(t_data *data_prs, int *done);
int		check_around(char **map, int x, int y, int max_lines);
int		init_struct(char *str, t_data *data, t_config *config);
int		is_valid_position(char **map, int x, int y, int max_lines);
int		store_map(t_data *data_prs, char *line, char **trimmed, int *done);
void	render_frame(t_data *data, int x, int y);
void	init_textures(t_data *game);
void	free_textures_arr(void *gam);
void	delete_textures(void *gam);
void	handle_es(mlx_key_data_t keydata, void *param);
float	deg_to_rad(float degree);
void	set_delta(t_data *data);
void	set_side_dist(t_data *d);
void	finding_hit(t_data *data);
int		is_wall(t_data *data, float x, float y);
void	rotate_left(t_data *data);
void	rotate_right(t_data *data);
void	init_player_pos(t_data *d, char **map);
void	raycast(t_data	*data, int x);
void	handle_movement(t_data	*data);
void	init_player_pos(t_data *d, char **map);
void	set_texture(t_data *data);
float	cast_single_ray(t_data *data, float ray_angle);
int		check_single_point(t_data *data, float x, float y);
int		is_walkable(t_data *data, float x, float y);