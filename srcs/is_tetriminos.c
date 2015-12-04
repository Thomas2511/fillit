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

int					is_tetriminos(char *tetriminos, int i, char letter)
{
	int				hashNb;

	hashNb = 0;
	if (i >= 0 && i < 20 && tetriminos[i] == '#')
	{
		tetriminos[i] = letter;
		hashNb++;
		hashNb += is_tetriminos(tetriminos, i + 1, letter);
		hashNb += is_tetriminos(tetriminos, i + 5, letter);
		hashNb += is_tetriminos(tetriminos, i - 1, letter);
		hashNb += is_tetriminos(tetriminos, i - 5, letter);
	}
	return (hashNb);
}
