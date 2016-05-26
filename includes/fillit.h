/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:29:56 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/12/02 19:30:00 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct	s_solution
{
	char		*data;
	int			len;
}				t_solution;

char			**check_file(int fd);
void			reset_tetriminos(char *tetriminos);
void			reset_all_tetriminos(char **tetriminos);
int				is_tetriminos(char *tetriminos, int i, char letter);
int				set_tetriminos(char *tetriminos, int i,
		t_solution *solution, int j);
t_solution		*solver(char **tetriminos);
#endif
