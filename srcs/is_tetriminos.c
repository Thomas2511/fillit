/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tetriminos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 12:56:47 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/12/04 12:56:50 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				is_tetriminos(char *tetriminos, int i, char letter)
{
	int			hashNb;

	hashNb = 0;
	if (i >= 0 && i < 20 && tetriminos[i] == '#')
	{
		tetriminos[i] = letter;
		++hashNb;
		hashNb += is_tetriminos(tetriminos, i + 1, letter);
		hashNb += is_tetriminos(tetriminos, i + 5, letter);
		hashNb += is_tetriminos(tetriminos, i - 1, letter);
		hashNb += is_tetriminos(tetriminos, i - 5, letter);
	}
	return (hashNb);
}

void			reset_tetriminos(char *tetriminos)
{
	int			i;

	i = 0;
	while (tetriminos[i])
	{
		if (tetriminos[i] <= 'Z' && tetriminos[i] >= 'A')
			tetriminos[i] += 32;
		i++;
	}
}

void			init_solution(char *solution, int j)
{
	int			i;

	i = 0;
	while (i < j * j)
	{
		solution[i] = '.';
		if ((i + 1) % j == 0)
			solution[i] = '\n';
		++i;
	}
}

void			reset_solution(char *solution, char letter)
{
	int			i;

	i = 0;
	while (solution[i])
	{
		if (solution[i] == letter)
			solution[i] = '.';
		++i;
	}
}

int				set_tetriminos(char *tetriminos, int i, char *solution, int j)
{
	int			hashNb;
	int			len;

	hashNb = 0;
	len = 0;
	while (solution[len] != '\n')
		len++;
	len++;
	if (i >= 0 && i < 20 && j >= 0 && j < 20
			&& tetriminos[i] >= 'a' && solution[j] == '.')
	{
		tetriminos[i] -= 32;
		solution[j] = tetriminos[i];
		++hashNb;
		hashNb += set_tetriminos(tetriminos, i + 1, solution, j + 1);
		hashNb += set_tetriminos(tetriminos, i + len, solution, j + len);
		hashNb += set_tetriminos(tetriminos, i - 1, solution, j - 1);
	}
	return (hashNb);
}
