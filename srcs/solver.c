/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 12:56:56 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/12/04 12:56:58 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"
#include "libft.h"

static int			place_tetriminos(char *t, char *solution, char letter)
{
	int				i;
	int				j;

	i = 0;
	while (solution[i])
	{
		j = 0;
		if (solution[i] == '.' && t[j])
		{
		printf("loup\n");
			while (t[j] && t[j] != '#')
				j++;
			if (set_tetriminos(t, j, solution, i) == 4)
				return (1);
			reset_tetriminos(t);
			reset_solution(solution, letter);
		}
		i++;
	}
	return (0);
}

static void			fill_solution(char **tetriminos, char **solution, int nb)
{
	int				i;

	i = 0;
	while (tetriminos[i])
	{
		if (place_tetriminos(tetriminos[i], *solution, 'a' + i))
			++i;
		else
		{
			free(*solution);
			*solution = (char *)malloc(sizeof(char) * ((nb + 1) * (nb + 1)) + 1);
			if (!(*solution))
				exit(EXIT_FAILURE);
			fill_solution(tetriminos, solution, nb + 1);
			break ;
		}
	}
}

void				solver(char **tetriminos)
{
	int				i;
	int				j;
	char			*solution;

	i = 0;
	j = 0;
	while (tetriminos[i])
		++i;
	i *= 4;
	while (j * j < i)
		++j;
	if ((solution = (char *)malloc(sizeof(char) * ((j * j) + 1))) == NULL)
		exit(EXIT_FAILURE);
	init_solution(solution, j);
	i = -1;
	while (++i < j * j)
		if (i % j == 0 && i != 0)
			solution[i] = '\n';
	fill_solution(tetriminos, &solution, j);
	ft_putstr(solution);
	free(solution);
}
