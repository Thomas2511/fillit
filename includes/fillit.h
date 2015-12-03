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

char				**check_file(int fd);
int					check_for_square(int *pos);
int					check_for_bar(int *pos);
int					check_for_t(int *pos);
int					check_for_s(int *pos);
int					check_for_l(int *pos);
void				solver(char **tetriminos);

#endif
