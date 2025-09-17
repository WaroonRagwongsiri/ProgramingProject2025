/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L5_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:12:26 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/09/17 13:39:29 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	FILE	*fp;
	FILE	*fp2;
	char	buffer[1024];
	char	*word;
	char	*find;
	int		line;

	if (ac != 2)
		return (printf("ac != 2"), 1);
	fp = fopen("input.txt", "r");
	fp2 = fopen("output.txt", "w");
	if (!fp || !fp2)
		return (printf("fp error"), 1);
	word = av[1];
	line = 1;
	while (!feof(fp))
	{
		fgets(buffer, sizeof(buffer), fp);
		find = strstr(buffer, word);
		while (find)
		{
			fprintf(fp2, "Found %s at line %d, position %ld.\n", word, line, find - buffer);
			find = strstr(&find[strlen(word)], word);
		}
		line++;
	}
}
