/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 20:16:37 by zkerkeb           #+#    #+#             */
/*   Updated: 2015/12/16 21:10:20 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
/*
int ft_strlen(char *str)
{
	int i;
	i = 0;

	while (str[i])
		i++;
	return (i);
}
*/
char **ft_b(char **tab)
{
	int l;
	int c;

	l = 0;
	c = 0;

	printf("a");
	while (tab[l][c] != '\n')
	{
		tab[l][c] = 'B';
		c++;
	}
	c = 0;
/*	while (tab[l][c] )
	{
		tab[l][0] = 'B';
//		tab[l][ft_strlen(tab[l] - 1)] = 'B';
		l++;
		if (tab[l + 1][c] == '\0')
		{
			while (tab[l][c])
			{
				tab[0][c] = 'B';
				c++;
			}
		}
	}*/
	return (tab);
}

int main()
{
	char *tab[6];

	tab[0] = "....\n";
	tab[1] = "....\n";
	tab[2] = "....\n";
	tab[3] = "....\n";
	tab[4] = NULL;

	printf("a");

	ft_b(tab);
	return(0);
}
