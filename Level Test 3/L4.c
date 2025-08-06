/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:25:28 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/08/06 13:35:52 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int	main(void)
{
	int	i;
	int	j;
	int	max;
	int	sum;
	int	arr[4][4] = {{-1, -1, -1, -1},
					{-1, -1, -1, -1},
					{-1, -1, -1, -1},
					{-1, -1, -1, 100}};
	int	sol[2][2] = {{0, 0}, {0, 0}};

	i = 0;
	max = -__INT_MAX__ - 1;
	sum = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1];
			if (sum > max)
			{
				sol[0][0] = arr[i][j];
				sol[0][1] = arr[i][j + 1];
				sol[1][0] = arr[i + 1][j];
				sol[1][1] = arr[i + 1][j + 1];
				max = sum;
			}
			j++;
		}
		i++;
	}
	printf("%d %d\n", sol[0][0], sol[0][1]);
	printf("%d %d\n", sol[1][0], sol[1][1]);
	printf("sum = %d", max);
}
