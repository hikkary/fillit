/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 21:06:20 by zkerkeb           #+#    #+#             */
/*   Updated: 2015/12/09 23:10:12 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char ***ft_split(char *str, char ***tab, int nt)
{
	int h;
	int v;
	int i;
	int s;

	s = 0;
	h = 0;
	i = 0;
	v = 0;
	tab = (char ***)malloc(sizeof(char **) * (nt + 1));
	
	while(i <= nt)
	{
		tab[s][h] = (char **)malloc(sizeof(char *) * 4);
		i++;
		s++;
	}
	i = 0;
	s = 0;
	while(i <= nt)
	{
		tab[s][h][v] = (char *)malloc(sizeof(char) * 4);
		i++;
		h++;
	}

	while (str[i])
	{
		if(i % 22 == 0)i
		{	
			tab[h][v] = '\0';
			h++;
			i = 0;
		}
		tab[h][v] = str[i];
		v++;
		i++;
	}
   tab[h] = NULL;
	return (tab);
}
