/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L5.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 13:21:06 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/07/23 13:43:31 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// ./a.out 9abc6a7 dcccdcd
int	main(int argc, char **argv)
{
	size_t	i;
	size_t	j;
	size_t	len_str;
	size_t	len_pat;

	if (argc != 3)
	{
		printf("argc != \n");
		return (1);
	}
	i = 0;
	len_str = strlen(argv[1]);
	len_pat = strlen(argv[2]);
	// printf("av1 : %d\n", len_str);
	// printf("av2 : %d\n", len_pat);
	if (len_str < len_pat)
	{
		printf("None\n");
		return (0);
	}
	while (i <= len_str - len_pat)
	{
		if (isalpha(argv[1][i]) || isdigit(argv[1][i]))
		{
			j = 0;
			while (argv[2][j])
			{
				if (argv[2][j] == 'c' && !isalpha(argv[1][i + j]))
				{
					break ;
				}
				else if (argv[2][j] == 'd' && !isdigit(argv[1][i + j]))
				{
					break ;
				}
				j++;
			}
			if (j == len_pat)
			{
				write(1, &argv[1][i], len_pat);
				return (0);
			}
		}
		i++;
	}
	printf("None\n");
	return (0);
}
