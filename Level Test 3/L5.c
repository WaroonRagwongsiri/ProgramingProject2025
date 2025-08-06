/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L5.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:18:52 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/08/06 14:18:00 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "string.h"

// ./a.out number +/- number
int	main(int argc, char **argv)
{
	int		len_num1;
	int		len_num2;
	char	tmp;

	if (argc != 4)
	{
		printf("argc must = 4");
		return 1;
	}
	len_num1 = strlen(argv[1]) - 1;
	len_num2 = strlen(argv[3]) - 1;
	if (len_num1 >= len_num2 && argv[2][0] == '+')
	{
		while (len_num1 >= 0)
		{
			if (len_num2 >= 0)
			{
				tmp = argv[1][len_num1] - '0' + argv[3][len_num2] - '0';
				if (tmp >= 10)
				{
					argv[1][len_num1 - 1] += 1;
					tmp -= 10;
				}
				tmp += '0';
				argv[1][len_num1] = tmp;
			}
			--len_num1;
			--len_num2;
		}
		printf("%s\n", argv[1]);
	}
	else if (len_num2 > len_num1 && argv[2][0] == '+')
	{
		while (len_num2 >= 0)
		{
			if (len_num1 >= 0)
			{
				tmp = argv[3][len_num2] - '0' + argv[1][len_num1] - '0';
				if (tmp >= 10)
				{
					argv[3][len_num2 - 1] += 1;
					tmp -= 10;
				}
				tmp += '0';
				argv[3][len_num2] = tmp;
			}
			--len_num1;
			--len_num2;
		}
		printf("%s\n", argv[3]);
	}
	else if (len_num1 >= len_num2 && argv[2][0] == '-')
	{
		while (len_num1 >= 0)
		{
			if (len_num2 >= 0)
			{
				tmp = argv[1][len_num1] - argv[3][len_num2];
				if (tmp < 0)
				{
					argv[1][len_num1 - 1] -= 1;
					tmp += 10;
				}
				tmp += '0';
				argv[1][len_num1] = tmp;
			}
			--len_num1;
			--len_num2;
		}
		printf("%s\n", argv[1]);
	}
	else if (len_num2 > len_num1 && argv[2][0] == '-')
	{
		while (len_num2 >= 0)
		{
			if (len_num1 >= 0)
			{
				tmp = argv[3][len_num2] - argv[1][len_num1];
				if (tmp < 0)
				{
					argv[3][len_num2 - 1] -= 1;
					tmp += 10;
				}
				tmp += '0';
				argv[3][len_num2] = tmp;
			}
			--len_num1;
			--len_num2;
		}
		printf("%s\n", argv[3]);
	}
}
