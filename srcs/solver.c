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

#include "fillit.h"
#include "libft.h"

static void			init_solution(char *solution, int j)
{
	int				i;

	i = 0;
	while (i < (j + 1) * j)
	{
		if ((i + 1) % (j + 1) == 0)
			solution[i] = '\n';
		else
			solution[i] = '.';
		++i;
	}
}

static char			*enlarge_solution(char **t, char *s, int width)
{
	free(s);
	if ((s = ft_strnew((width + 2) * (width + 1))) == NULL)
		return (NULL);
	init_solution(s, width + 1);
	reset_all_tetriminos(t);
	return (s);
}

static int			place_tetriminos(char *t, char *s, int start, char letter)
{
	int				i;
	int				j;

	i = 0;
	while (!ft_isalpha(t[i]))
		++i;
	if (set_tetriminos(t, i, s, start) == 4)
		return (1);
	reset_tetriminos(t);
	j = 0;
	while (s[j])
	{
		if (s[j] == letter)
			s[j] = '.';
		++j;
	}
	return (0);
}

static int			fill_solution(char **tet, char **sol, int index)
{
	int				i;
	char			*sol_cpy;

	i = 0;
	if (tet[index] == NULL)
		return (1);
	sol_cpy = ft_strdup(*sol);
	while ((*sol)[i])
	{
		if (!place_tetriminos(tet[index], *sol, i, 'A' + index))
		{
			++i;
			continue ;
		}
		if (fill_solution(tet, sol, index + 1))
		{
			free(sol_cpy);
			return (1);
		}
		free(*sol);
		*sol = ft_strdup(sol_cpy);
	}
	free(sol_cpy);
	return (0);
}

char				*solver(char **tetriminos)
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
	if ((solution = ft_strnew((j + 1) * j)) == NULL)
		return (NULL);
	init_solution(solution, j);
	while (!fill_solution(tetriminos, &solution, 0))
	{
		if ((solution = enlarge_solution(tetriminos, solution, j)) == NULL)
			return (NULL);
		++j;
	}
	return (solution);
}
