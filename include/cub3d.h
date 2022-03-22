/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshera <sshera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:32:25 by bcarlee           #+#    #+#             */
/*   Updated: 2022/02/28 16:02:46 by sshera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define N 1
# define S 2
# define W 3
# define E 4
# define PI 3.14159265

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>
# include "../lib/libft.h"
# include "../minilibx_opengl_20191021/mlx.h"

typedef struct s_ply{
	double	x;
	double 	y;
	int 	pos;
	double 	angle;
	double  move_k;
	double 	rotate_k;
}			t_ply;

typedef struct s_map{
    char    **map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int 	f[3];
	int 	c[3];
    int     count_line;
}           t_map;

typedef struct s_data{
    t_map   *map;
    void 	*mlx;
    void 	*win;
	char 	*active_key;
	t_ply	*ply;
}           t_data;

int ft_check_name(char *name);
void	run_game(t_data *data);

void    init_map(char *filename, t_data *data);
void    print_error(int i);
char	*ft_subst(char *str, int s, int l, int flag);
char	*get_next_line(int fd);
void	get_data(char *line, t_data *data, int flag);
void	clear_arr(char **arr);
int		ft_isdigit_char(char *str);
void	copy_map(char *file, int start, t_data *data, int end);
void	trim_space(t_data *data);
void	init_struct_map(t_data *data);
void	clear_and_exit(t_data *data);
void	valid_map(t_data *data);
int 	size_arr(char **arr);
void	check_close_wall_inside(t_data *data);
void	check_sym(t_data *data, int i, int j, int *err);
void	check_next_sym(t_data *data, int i, int j, int *err);
#endif