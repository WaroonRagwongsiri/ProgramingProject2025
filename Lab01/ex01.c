/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   วรุณรักษ์วงศ์สิริ68011008โจทย์1.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:26:57 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/07/16 13:31:19 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	x;
	int	sum;

	scanf("%d", &x);
	sum = 0;
	while (x != -1)
	{
		if (x % 2 == 0)
		{
			sum += x;
		}
		scanf("%d", &x);
	}
	printf("Sum of Even Number = %d", sum);
	return (0);	
}
