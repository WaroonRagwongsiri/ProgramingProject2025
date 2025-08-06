/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:32:09 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/07/16 13:39:35 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	ascii[256] = {0};
	int		i;

	if (argc != 2)
	{
		printf("argc != 2");
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		ascii[(int) argv[1][i]]++;
		i++;
	}
	i = 0;
	while (i < 256)
	{
		if (ascii[i] != 0)
		{
			printf("%c = %d\n",i , ascii[i]);
		}
		i++;
	}
	return (0);
}
