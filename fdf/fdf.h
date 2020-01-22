/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:15:10 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/22 18:11:11 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"

# include <stdio.h>

typedef struct	s_data
{
	char				*refs[20];
	int					(*functs[19])(char ***, t_point, char);
	int					pieces[26];
	int					positions[26];
	unsigned int		piececount;
	unsigned int		side;
	unsigned int		pos;
	char				**board;
}				t_data;

/*
** macros
*/
# define I1 "#...#...#...#"
# define I2 "####"
# define J1 "#...#..##"
# define J2 "#...###"
# define J3 "##..#...#"
# define J4 "###...#"
# define L1 "#...#...##"
# define L2 "###.#"
# define L3 "##...#...#"
# define L4 "#.###"
# define O1 "##..##"
# define S1 "##.##"
# define S2 "#...##...#"
# define T1 "###..#"
# define T2 "#..##...#"
# define T3 "#..###"
# define T4 "#...##..#"
# define Z1 "##...##"
# define Z2 "#..##..#"
# define NO_PIECE -2

/*
** board.c
*/
char			**build_board(int side);
void			clear_board(char **board, int side);
void			refill_board(t_data *data, int end);
void			expand_board(t_data *data);

/*
** del.c
*/
void			del_refs(t_data *data);
void			del_board(t_data *data);
void			del_data(t_data *data);

/*
** fillit.c
*/
int				next(t_data *data);
int				solve(t_data *data);
int				fillit(char *input);

/*
** init1.c
*/
int				init_refs(t_data *data);
int				check_refs(t_data *data);
int				is_valid_piece(char **ref, int y, char **piece, char *found);
int				sort_piece(char **ref, char **piece);
int				init_pieces(t_data *data, char *input);

/*
** init2.c
*/
void			init_functs(t_data *data);
void			init_pos(t_data *data);
void			init_piececount(t_data *data);
void			init_side(t_data *data);
int				init_data(t_data *data, char *input);

/*
** main.c
*/
int				handle_error();
int				valid_arguments(int ac);
int				get_input(int fd, char **input);

/*
** place_*.c
*/
int				place_i1(char ***board, t_point p, char letter);
int				place_i2(char ***board, t_point p, char letter);
int				place_j1(char ***board, t_point p, char letter);
int				place_j2(char ***board, t_point p, char letter);
int				place_j3(char ***board, t_point p, char letter);
int				place_j4(char ***board, t_point p, char letter);
int				place_l1(char ***board, t_point p, char letter);
int				place_l2(char ***board, t_point p, char letter);
int				place_l3(char ***board, t_point p, char letter);
int				place_l4(char ***board, t_point p, char letter);
int				place_o1(char ***board, t_point p, char letter);
int				place_s1(char ***board, t_point p, char letter);
int				place_s2(char ***board, t_point p, char letter);
int				place_t1(char ***board, t_point p, char letter);
int				place_t2(char ***board, t_point p, char letter);
int				place_t3(char ***board, t_point p, char letter);
int				place_t4(char ***board, t_point p, char letter);
int				place_z1(char ***board, t_point p, char letter);
int				place_z2(char ***board, t_point p, char letter);

/*
** place.c
*/
int				place_piece(int type, char ***board, t_point p, char letter);

#endif
