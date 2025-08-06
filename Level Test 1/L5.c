/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L5.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:26:54 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/07/16 11:18:03 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int	main(int argc, char **argv)
{
	char	word_onlychar[1000000] = {0};
	int		i;
	int		j;

	i = 0;
	if (argc != 2)
	{
		printf("only accept argc = 2");
		return (1);
	}
	while (i < strlen(argv[1]))
	{
		if ((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
		{
			strncat(word_onlychar, &argv[1][i], 1);
		}
		i++;
	}
	printf("word : %s\n", argv[1]);
	printf("noch : %s\n", word_onlychar);
	i = 0;
	j = strlen(word_onlychar) - 1;
	while (i < strlen(word_onlychar))
	{
		if (tolower(word_onlychar[i]) != tolower(word_onlychar[j]))
		{
			printf("Not Palindrome");
			return (0);
		}
		i++;
		j--;
	}
	printf("Palindrome");
	return (0);
}
// "Madam, I do get a mate. God, I’m Adam."