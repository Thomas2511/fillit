/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_handling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 12:56:47 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/12/04 12:56:50 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			reset_tetriminos(char *tetriminos)
{
	int			i;

	i = 0;
	while (tetriminos[i])
	{
		if (tetriminos[i] <= 'Z' && tetriminos[i] >= 'A')
			tetriminos[i] += 32;
		++i;
	}
}

void			reset_all_tetriminos(char **tetriminos)
{
	int			i;

	i = 0;
	while (tetriminos[i])
	{
		reset_tetriminos(tetriminos[i]);
		++i;
	}
}

int				is_tetriminos(char *tetriminos, int i, char letter)
{
	int			hashnb;

	hashnb = 0;
	if (i >= 0 && i < 20 && tetriminos[i] && tetriminos[i] == '#')
	{
		tetriminos[i] = letter;
		++hashnb;
		hashnb += is_tetriminos(tetriminos, i + 1, letter);
		hashnb += is_tetriminos(tetriminos, i + 5, letter);
		hashnb += is_tetriminos(tetriminos, i - 1, letter);
		hashnb += is_tetriminos(tetriminos, i - 5, letter);
	}
	return (hashnb);
}

int				set_tetriminos(char *tetriminos, int i, t_solution *sol, int j)
{
	int			hashnb;

	hashnb = 0;
	if (i >= 0 && i < 20 && j >= 0 && j < (sol->len * (sol->len - 1))
			&& tetriminos[i] >= 'a' && sol->data[j] == '.')
	{
		tetriminos[i] -= 32;
		sol->data[j] = tetriminos[i];
		++hashnb;
		hashnb += set_tetriminos(tetriminos, i + 1, sol, j + 1);
		hashnb += set_tetriminos(tetriminos, i + 5, sol, j + sol->len);
		hashnb += set_tetriminos(tetriminos, i - 1, sol, j - 1);
	}
	return (hashnb);
}
