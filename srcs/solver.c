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
	int			i;

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

static char			**enlarge_solution(char **t, char **s, int nb)
{
	free(*s);
	if ((*s = ft_strnew((nb + 2) * (nb + 1))) == NULL)
		return (NULL);
	init_solution(*s, nb + 1);
	reset_all_tetriminos(t);
	if (!fill_solution(t, s, nb + 1))
		return (NULL);
	return (s);
}

static int			place_tetriminos(char *t, char *s, int start, char letter)
{
	int				i;
	int				j;

	while (s[start])
	{
		i = 0;
		if (s[start] == '.' && t[i])
		{
			while (t[i] && !ft_isalpha(t[i]))
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
		}
		++start;
	}
	return (0);
}

int					fill_solution(char **tetriminos, char **solution, int nb)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (tetriminos[i])
	{
		if (place_tetriminos(tetriminos[i], *solution, 0, 'A' + i))
			++i;
		else if (j < (int)ft_strlen(*solution))
		{
			i = 0;
			init_solution(*solution, nb);
			reset_all_tetriminos(tetriminos);
			if (place_tetriminos(tetriminos[i], *solution, ++j, 'A' + i))
				++i;
		}
		else
		{
			if ((solution = enlarge_solution(tetriminos, solution, nb)) == NULL)
				return (0);
			break ;
		}
	}
	return (1);
}

char				*solver(char **tetriminos)
{
	int				i;
	int				j;
	char			*solution;

	i = 0;
	j = 0;
	while (tetriminos[i])
		i++;
	i = i * 4 < 16 ? 16 : i * 4;
	while (j * j < i)
		++j;
	if ((solution = ft_strnew((j + 1) * j)) == NULL)
		return (NULL);
	init_solution(solution, j);
	if (!fill_solution(tetriminos, &solution, j))
		return (NULL);
	return (solution);
}
