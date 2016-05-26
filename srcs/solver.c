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

static t_solution	*init_solution(int j)
{
	int				i;
	t_solution		*solution;

	solution = NULL;
	if (((solution = (t_solution *)ft_memalloc(sizeof(t_solution))) == NULL)
			|| ((solution->data = (char *)ft_strnew((j + 1) * j)) == NULL))
		return (NULL);
	solution->len = j + 1;
	i = 0;
	while (i < (j + 1) * j)
	{
		if ((i + 1) % (j + 1) == 0)
			solution->data[i] = '\n';
		else
			solution->data[i] = '.';
		++i;
	}
	return (solution);
}

static t_solution	*enlarge_solution(char **t, t_solution *s, int width)
{
	t_solution		*new_solution;

	free(s->data);
	free(s);
	new_solution = init_solution(width + 1);
	reset_all_tetriminos(t);
	return (new_solution);
}

static int			place_tetriminos(char *t, t_solution *s, int start, char letter)
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
	while (s->data[j])
	{
		if (s->data[j] == letter)
			s->data[j] = '.';
		++j;
	}
	return (0);
}

static int			fill_solution(char **tet, t_solution *sol, int index)
{
	int				i;
	char			*sol_cpy;

	i = 0;
	if (tet[index] == NULL)
		return (1);
	sol_cpy = ft_strdup(sol->data);
	while (sol->data[i])
	{
		if (!place_tetriminos(tet[index], sol, i, 'A' + index))
		{
			++i;
			continue ;
		}
		if (fill_solution(tet, sol, index + 1))
		{
			free(sol_cpy);
			return (1);
		}
		free(sol->data);
		sol->data = ft_strdup(sol_cpy);
	}
	free(sol_cpy);
	return (0);
}

t_solution			*solver(char **tetriminos)
{
	int				i;
	int				j;
	t_solution		*solution;

	i = 0;
	j = 0;
	while (tetriminos[i])
		++i;
	i *= 4;
	while (j * j < i)
		++j;
	solution = init_solution(j);
	while (!fill_solution(tetriminos, solution, 0))
	{
		if ((solution = enlarge_solution(tetriminos, solution, j)) == NULL)
			return (NULL);
		++j;
	}
	return (solution);
}
