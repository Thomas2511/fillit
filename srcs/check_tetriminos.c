/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:37:35 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/12/02 19:37:37 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				check_for_square(int *pos)
{
	return ((pos[2] - pos[0]) == 5 && (pos[3] - pos[1]) == 5
			&& pos[0] + 1 == pos[1] && pos[2] + 1 == pos[3]);
}

int				check_for_bar(int *pos)
{
	return ((pos[0] + pos[1] + pos[2] + pos[3] - 6) % 20 == 0
			|| (pos[0] + pos[1] + pos[2] + pos[3] - 30) % 4 == 0);
}

int				check_for_t(int *pos)
{
	return ((pos[1] - pos[0] == 4 && pos[2] - pos[1] == 1
				&& pos[3] - pos[2] == 5)
			|| (pos[1] - pos[0] == 1 && pos[2] - pos[1] == 1
				&& pos[3] - pos[2] == 4)
			|| (pos[1] - pos[0] == 5 && pos[2] - pos[1] == 1
				&& pos[3] - pos[2] == 4)
			|| (pos[1] - pos[0] == 4 && pos[2] - pos[1] == 1
				&& pos[3] - pos[2] == 1));
}

int				check_for_s(int *pos)
{
	return ((pos[1] - pos[0] == 1 && pos[2] - pos[1] == 3
				&& pos[3] - pos[2] == 1)
			|| (pos[1] - pos[0] == 5 && pos[2] - pos[1] == 1
				&& pos[3] - pos[2] == 5)
			|| (pos[1] - pos[0] == 1 && pos[2] - pos[1] == 5
				&& pos[3] - pos[2] == 1)
			|| (pos[1] - pos[0] == 4 && pos[2] - pos[1] == 1
				&& pos[3] - pos[2] == 4));
}

int				check_for_l(int *pos)
{
	return ((pos[1] - pos[0] == 1 && pos[2] - pos[1] == 4
				&& pos[3] - pos[2] == 5)
			|| (pos[1] - pos[0] == 1 && pos[2] - pos[1] == 5
				&& pos[3] - pos[2] == 5)
			|| (pos[1] - pos[0] == 5 && pos[2] - pos[1] == 1
				&& pos[3] - pos[2] == 1)
			|| (pos[1] - pos[0] == 1 && pos[2] - pos[1] == 1
				&& pos[3] - pos[2] == 5)
			|| (pos[1] - pos[0] == 5 && pos[2] - pos[1] == 5
				&& pos[3] - pos[2] == 1)
			|| (pos[1] - pos[0] == 5 && pos[2] - pos[1] == 4
				&& pos[3] - pos[2] == 1)
			|| (pos[1] - pos[0] == 1 && pos[2] - pos[1] == 1
				&& pos[3] - pos[2] == 3)
			|| (pos[1] - pos[0] == 3 && pos[2] - pos[1] == 1
				&& pos[3] - pos[2] == 1));
}
