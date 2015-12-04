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

char			**check_file(int fd);
int				is_tetriminos(char *tetriminos, int i, char letter);
int				set_tetriminos(char *tetriminos, int i, char *solution, int j);
void			reset_tetriminos(char *tetriminos);
void			init_solution(char *solution, int j);
void			reset_solution(char *solution, char letter);
void			solver(char **tetriminos);

#endif
