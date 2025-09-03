/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L5.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:10:43 by waroonwork@       #+#    #+#             */
/*   Updated: 2025/09/03 13:55:51 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int		is_palindrome(char *str);

int	main(int ac, char **av)
{
	char	word_onlychar[100000] = {0};
	int		word_len;
	int		left;
	int		right;
	char	palindrome[100000] = {0};
	char	max_palindrome[100000] = {0};

	if (ac != 2)
		return (1);
	left = 0;
	while (left < strlen(av[1]))
	{
		if ((av[1][left] >= 'a' && av[1][left] <= 'z') || (av[1][left] >= 'A' && av[1][left] <= 'Z'))
			strncat(word_onlychar, &av[1][left], 1);
		left++;
	}
	left = 0;
	right = left;
	word_len = strlen(word_onlychar);
	while (left < word_len)
	{
		right = 0;
		while (right < word_len)
		{
			memset(palindrome, 0, strlen(palindrome));
			strncpy(palindrome, &word_onlychar[left], right - left + 1);
			if (is_palindrome(palindrome))
			{
				if (strlen(palindrome) > strlen(max_palindrome))
				{
					memset(max_palindrome, 0, strlen(max_palindrome));
					strncpy(max_palindrome, &word_onlychar[left], right - left + 1);
				}
			}
			right++;
		}
		left++;
	}
	printf("%s", max_palindrome);
	return (0);	
}

int	is_palindrome(char *str)
{
	int	i;
	int	j;

	if (!str)
		return (1);
	i = 0;
	j = strlen(str) - 1;
	while (i < strlen(str))
	{
		if (tolower(str[i]) != tolower(str[j]))
			return (0);
		i++;
		j--;
	}
	return (1);
}
