/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:51:18 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/09/10 12:55:58 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// TODO: เขียนฟังก์ชั่น swap
void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	main(int argc, char **argv)
{
	int num1;
	int	num2;

	// TODO: รับ input จากผู้ใช้
	if (argc != 3)
		return (1);
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	// TODO: แสดงค่าก่อนสลับ
	printf("n1: %d , n2: %d\n", num1, num2);
	// TODO: เรียกฟังก์ชั่น swap
	swap(&num1, &num2);
	// TODO: แสดงค่าหลังสลับ
	printf("n1: %d , n2: %d\n", num1, num2);
	return (0);
}
