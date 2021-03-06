/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:57:56 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/12/02 16:29:48 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"
#include "libft.h"

static void			error(void)
{
	ft_putendl_fd("error", 2);
	exit(EXIT_FAILURE);
}

int					main(int ac, char **av)
{
	int				fd;
	char			**tetriminos;
	t_solution		*solution;

	if (ac != 2)
		error();
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error();
	tetriminos = check_file(fd);
	close(fd);
	if (!tetriminos)
		error();
	if ((solution = solver(tetriminos)) == NULL)
		error();
	ft_putstr(solution->data);
	ft_clear_tab(tetriminos);
	free(solution->data);
	free(solution);
	return (0);
}
