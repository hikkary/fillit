/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:32:30 by zkerkeb           #+#    #+#             */
/*   Updated: 2015/12/16 16:48:57 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int *ft_check_l(char **tab, int *size)
{
	int i;
	int v;
	
	i = 0;
	v = 0;
	while(tab[v])
	{
		while (tab[v][i] != '\n')
		{
			if (tab[v][i] == '#' && i > size[0])
				size[0] = i;
			else
				i++;	
		}
		v++;
		i = 0;
	}
	size[0] += 1;
	return (size); 
}

int *ft_check_h(char **tab, int *size)
{
	int i;
	int v;
	
	i = 0;
	v = 0;
	while(tab[v])
	{
		while (tab[v][i] != '\n')
		{
			if (tab[v][i] == '#')
				size[1] = v;
			i++;	
		}
		v++;
		i = 0;
	}
	size[1] += 1;
	return (size);
}

int ft_size_tab(char **tab)
{	
	int *size;
	int tc;
	
	tc = 0;
	size = (int *)malloc(sizeof(int) * 3);

	size = ft_check_l(tab, size);
	size = ft_check_h(tab, size);
	if(size[0] >= size[1])
		tc = size[0];
	else
		tc = size[1];

	return (tc);
}
