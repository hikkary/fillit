/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 21:06:20 by zkerkeb           #+#    #+#             */
/*   Updated: 2015/12/10 22:05:57 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char ***l_malloc(char ***tab, int nt)
{
	int i;
	int s;
	int h;

	i = 0;
	s = 0;
	h = 0;
	while(i <= nt)
	{
		tab[s] = (char **)malloc(sizeof(char *) * 4);
		i++;
		s++;
	}
	return (tab);
}

char ***cara_malloc(char ***tab, int nt)
{
	int i;
	int s;
	int h;

	i = 0;
	s = 0;
	h = 0;
	while(i <= (nt * 4))
	{
		tab[s][h] = (char *)malloc(sizeof(char) * 5);
		printf("%d/%d/%d  ", s,h, i);
		i++;
		h++;
		if (i % 4 == 0)
		{
			s++;
			h = 0;
		}
	}
	return(tab);
}

char ***ft_split(char *str, char ***tab, int nt)
{
	int h;
	int v;
	int s;
	int i;

	i = 0;
	s = 0;
	h = 0;
	v = 0;
	

	tab = l_malloc(tab, nt);
	tab = cara_malloc(tab, nt);
	
	while (str[i] != '\0')
	{
		tab[s][h][v] = str[i];
		v++;
		i++;
	//	printf("c", *tab[h][v]);
		if (v == 3)
		{
			v = 0;
		}
		if (h == 3)
		{
			h = 0;
		}
	}
  // tab[h] = NULL;
	return (tab);
}
