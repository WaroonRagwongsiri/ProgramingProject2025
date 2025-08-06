/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:01:57 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/07/30 15:27:52 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double	*find_middle(double x1, double y1, double x2, double y2);

int main(void)
{
	double	x1, y1, x2, y2, h1;
	double	x3, y3, x4, y4, h2;
	double	sol;

	scanf("%lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &h1);
	scanf("%lf %lf %lf %lf %lf", &x3, &y3, &x4, &y4, &h2);

	double	*middle_1 = find_middle(x1, y1, x2, y2);
	double	*middle_2 = find_middle(x3, y3, x4, y4);
	printf("%.0lf %.0lf\n", middle_1[0], middle_1[1]);
	printf("%.0lf %.0lf\n", middle_2[0], middle_2[1]);
	sol = sqrt(pow(middle_1[0] - middle_2[0], 2) + pow(middle_1[1] - middle_2[1], 2) + pow(h2 - h1, 2));
	printf("%.0lf\n", sol);
	free(middle_1);
	free(middle_2);
}
// 9 18 34 26 42

double	*find_middle(double x1, double y1, double x2, double y2)
{
	double vx1, vy1, vx2, vy2, L, x5, y5;
	double *middle;
	vx1 = x2 - x1;
	vy1 = y2 - y1;

	L = sqrt(vx1 * vx1 + vy1 * vy1);

	vx2 = -vy1;
	vy2 = vx1;

	x5 = x1 + vx2;
	y5 = y1 + vy2;

	double middle_x = (x5 + x2) / 2;
	double middle_y = (y5 + y2) / 2;
	middle = calloc(2, sizeof(double));
	middle[0] = middle_x;
	middle[1] = middle_y;
	return middle;
}