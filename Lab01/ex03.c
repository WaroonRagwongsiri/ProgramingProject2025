/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:40:11 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/07/16 13:51:11 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	max;
	int	i;
	int	j;

	max = 0;
	if (argc != 2)
	{
		printf("argc != 2");
		return (0);
	}
	printf("%s\n", argv[1]);
	i = 0;
	while (argv[1][i])
	{
		if ((argv[1][i] - '0') > max)
		{
			max = (int) argv[1][i] - '0';
		}
		i++;
	}
	i = 0;
	while (i < max)
	{
		j = 0;
		while (argv[1][j])
		{
			if ((argv[1][j] - '0') > i)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
