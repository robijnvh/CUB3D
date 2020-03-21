/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-hou <rvan-hou@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 16:04:08 by rvan-hou       #+#    #+#                */
/*   Updated: 2020/03/20 17:57:55 by robijnvanho   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include <stddef.h>
# include <math.h>
# define BUFFER_SIZE 128
# define MOVE_LEFT_KEY 0
# define MOVE_RIGHT_KEY 2
# define MOVE_UP_KEY 13
# define MOVE_DOWN_KEY 1
# define ROTATE_LEFT_KEY 123
# define ROTATE_RIGHT_KEY 124
# define ESC 53

typedef struct		s_map
{
	char			startpoint;
	char			*str;
	int				rows;
	char			**array;
	int				columns;
	unsigned long	td_map_wall;
	unsigned long	td_map_floor;
}					t_map;

typedef struct		s_list
{
	int				img_height_no;
	int				img_width_no;
	void			*mlx_no;
	void			*img_no;
	int				bits_per_pixel_no;
	int				line_length_no;
	int				endian_no;
	char			*addr_no;
	int				img_height_so;
	int				img_width_so;
	void			*mlx_so;
	void			*img_so;
	int				bits_per_pixel_so;
	int				line_length_so;
	int				endian_so;
	char			*addr_so;
	int				img_height_we;
	int				img_width_we;
	void			*mlx_we;
	void			*img_we;
	int				bits_per_pixel_we;
	int				line_length_we;
	int				endian_we;
	char			*addr_we;
	int				img_height_ea;
	int				img_width_ea;
	void			*mlx_ea;
	void			*img_ea;
	int				bits_per_pixel_ea;
	int				line_length_ea;
	int				endian_ea;
	char			*addr_ea;
	int				img_height_sp;
	int				img_width_sp;
	void			*mlx_sp;
	void			*img_sp;
	int				bits_per_pixel_sp;
	int				line_length_sp;
	int				endian_sp;
	char			*addr_sp;
}					t_list;

typedef struct		s_data
{
	int				max_columns;
	int				save;
	char			*input;
	int				rw;
	int				rh;
	int				png;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	unsigned long	floor;
	unsigned long	ceiling;
	int				fred;
	int				fgreen;
	int				fblue;
	int				cred;
	int				cgreen;
	int				cblue;
	int				valid;
	int				columns_cut;
	char			orientation;
	double			sqr_h;
	double			sqr_w;

	double			start_x;
	double			start_y;
	double			dist_x;
	double			dist_y;
	double			del_x;
	double			del_y;
	double			step_x;
	double			step_y;
	double			hit_x;
	double			hit_y;
	double			ray_length;
	int				side;
	double			mid;
	double			perp_wall_dist;

	double			tex_hit;
	double			tex_x;
	double			tex_y;
	double			tex_size;

	float			step;
	float			sp_angle_l;
	float			sp_angle_r;
	int				sprite;
	float			x;
	float			y;
	float			spritehit[10];
	float			on_wall_sprite[10];
	int				i;
	int				first;
	int				end;
}					t_data;

typedef struct		s_move
{
	double			move_l;
	double			move_r;
	double			move_u;
	double			move_d;
	double			rotate_l;
	double			rotate_r;
	int				reverse;
}					t_move;

typedef struct		s_vars
{
	int				og_rh;
	int				og_rw;
	float			on_wall;
	double			angle_tmp;
	void			*mlx;
	void			*mlx2;
	void			*mlx3;
	void			*win;
	void			*win2;
	int				x;
	int				y;
	float			radiant;
	void			*img;
	void			*img2;
	void			*img3;
	char			*addr;
	char			*addr2;
	char			*addr3;
	int				bits_per_pixel;
	int				bits_per_pixel2;
	int				bits_per_pixel3;
	int				line_length;
	int				line_length2;
	int				line_length3;
	int				endian;
	int				endian2;
	int				endian3;
	int				rgb;
	double			angle;
	int				window_mid;
	t_data			*data;
	t_map			*map;
	t_list			t;
	t_move			m;
}					t_vars;

int					main(int argc, char **argv);

char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *src);
char				*ft_strdup2(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strlen(const char *str);
int					ft_strlen2(const char *str, int i);
char				*ft_strchr(const char *str, int c);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_putchar(char c);
int					ft_atoi(const char *str);
void				ft_putstr(char *s);
void				ft_putnbr(int n);

char				*ft_strjoin_gnl(char const *s1, char const *s2);
int					get_next_line(int fd, char **line);

int					check_map(t_map *map, t_data *data);
int					check_all_lines(char *s, int end);
void				find_max_columns(t_map *map, t_data *data, int i);
int					scan_map(t_data *data, t_vars *win);
int					init_arguments(int argc, char **argv, t_data *data);
int					check_file(char *str);
int					check_char(char c, t_map *map);
int					check_char_middle(char c);
int					makearray(t_data *data, t_map *map);
int					store_arguments(char *buf, t_data *data);
void				check_arguments(t_map *map, t_data *data);
char				**free_array(char **str, int i);
void				free_full_array(t_map *map);
void				clear_data_map(t_data *data, t_map *map);
int					arguments_complete(t_data *data);
int					check_file_type(char *str);
int					check_double(t_data *data, char c);
void				fill_spaces(t_map *map, t_data *data);
int					get_color_data(char *buf, t_data *data);
int					get_color_data2(char *buf, t_data *data);

void				init_three_d_map(t_vars *win);
int					display_map_window(t_data *data, t_map *map);
void				set_orientation(char c, t_vars *win, int x, int y);
void				my_mlx_pixel_put2(t_vars *win, int x, int y, int color);
int					set_textures(t_vars *win);
int					set_sprite(t_vars *win);
void				put_texture(t_vars *win, double x1, double size, double size_search);
void				print_texture(t_vars *win, double x1, int size);
void				print_tex_no(t_vars *win, double x1, double size, double size_search);
void				print_tex_so(t_vars *win, double x1, double size, double size_search);
void				print_tex_ea(t_vars *win, double x1, double size, double size_search);
void				print_tex_we(t_vars *win, double x1, double size, double size_search);
void				set_ceiling(t_vars *win, int i, double x1);
void				set_floor(t_vars *win, int i, double x1);
void				move_player(t_vars *win, double move, double rotate,
					int reverse);

void				find_all_hits(t_vars *win, double tmp);
void				create_three_d_map(t_vars *win, double x, double tmp);
void				clear_all_data(t_vars *win);

void				create_bmp(char *name, char *addr, int width, int height);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					return_error(char *s, int i);

void				make_sprite(t_vars *win, float distance, float on_wall,
					int x);
void				hit_sprite_x(t_vars *win);
void				find_intersect_x(t_vars *win, float sign, int sign2,
					float step);
void				hit_sprite_y(t_vars *win);
void				find_intersect_y(t_vars *win, int sign, int sign2,
					float step);
#endif
