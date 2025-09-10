/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:58:48 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/09/10 13:09:06 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: เขียนฟังก์ชั่น swap (ใช้จากตอนที่ 1)
void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// TODO: เขียนฟังก์ชั่น bubble_sort
void	bubble_sort(int arr[], int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - i - 2)
		{
			if (arr[j] >  arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

// TODO: เขียนฟังก์ชั่นแสดง array
void	print_array(int arr[], int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	int numbers[20];
	int count;
	int	i;

	memset(numbers, 0, sizeof(numbers));
	// TODO: รับจำนวนตัวเลข
	if (argc < 2 || argc > 21)
		return (1);
	// TODO: ตรวจสอบว่าจำนวนไม่เกิน 20

	// TODO: รับตัวเลขแต่ละตัว
	i = 1;
	while (i < argc)
	{
		numbers[i - 1] = atoi(argv[i]);
		i++;
	}
	// TODO: แสดง array ก่อนเรียงลำดับ
	print_array(numbers, argc - 1);
	// TODO: เรียกฟังก์ชั่น bubble_sort
	bubble_sort(numbers, argc);
	// TODO: แสดง array หลังเรียงลำดับ
	print_array(numbers, argc - 1);
	return 0;
}
