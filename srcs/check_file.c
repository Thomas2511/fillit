/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:26:38 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/12/02 16:53:52 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static void			bzero_tetriminos(char **tetriminos)
{
	int				i;

	i = 0;
	while (i < 26)
	{
		*tetriminos = NULL;
		++tetriminos;
		++i;
	}
}

static char			**read_file(int fd)
{
	char			**tetriminos;
	char			buf[546];
	int				i;
	int				j;

	i = 0;
	j = 0;
	if ((tetriminos = (char **)malloc(sizeof(char *) * 27)) == NULL)
		return (NULL);
	bzero_tetriminos(tetriminos);
	ft_bzero(buf, 546);
	if (read(fd, buf, 546) < 0)
		return (NULL);
	while (buf[j] != '\0')
	{
		if (ft_strlen(buf) >= 20)
			tetriminos[i] = ft_strsub(buf, 21 * i, 21);
		else
			return (NULL);
		j += ft_strlen(tetriminos[i]);
		tetriminos[i][ft_strlen(tetriminos[i])] = '\0';
		++i;
	}
	return (tetriminos);
}

static int			lex_tetriminos(char **tetriminos)
{
	int				i;

	while (*tetriminos != NULL)
	{
		i = 0;
		while ((*tetriminos)[i])
		{
			if ((*tetriminos)[i] != '.' && (*tetriminos)[i] != '#'
					&& (i + 1) % 5 != 0 && (i + 1) % 21 != 0)
				return (0);
			else
			{
				if ((*tetriminos)[i] != '\n'
						&& ((i + 1) % 5 == 0 || (i + 1) % 21 == 0))
					return (0);
			}
			++i;
		}
		++tetriminos;
	}
	return (1);
}

static int			parse_tetriminos(char **tetriminos)
{
	int			i;
	char		letter;

	letter = 'a';
	while (*tetriminos != NULL)
	{
		i = 0;
		while ((*tetriminos)[i] && (*tetriminos)[i] != '#')
			++i;
		if ((*tetriminos)[i] && is_tetriminos(*tetriminos, i, letter) != 4)
			return (0);
		++letter;
		++tetriminos;
	}
	return (1);
}

char				**check_file(int fd)
{
	char			**tetriminos;

	tetriminos = read_file(fd);
	if (!tetriminos)
		return (NULL);
	if (!lex_tetriminos(tetriminos))
	{
		ft_clear_tab(tetriminos);
		return (NULL);
	}
	if (!parse_tetriminos(tetriminos))
	{
		ft_clear_tab(tetriminos);
		return (NULL);
	}
	return (tetriminos);
}
