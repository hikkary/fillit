/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forme.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 19:04:30 by zkerkeb           #+#    #+#             */
/*   Updated: 2015/12/14 20:07:47 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int ft_first_diez(char *piece)
{
	int i;

	i = 0;
	while (piece[i] != '\0' && piece[i] != '#')
		i++;
	return (i);
}


int ft_test_form(char *piece)
{
	int count;
	int i;

	i = ft_first_diez(piece);
	count = 1;

	piece[i] = 'x';
	if (piece[i + 1] == '#')
		count = go_right(piece,i,count);
	if (piece[i + 5] == '#')
		count = go_down(piece,i,count);
	if (piece[i - 5] == '#')
		count = go_up(piece,i,count);
	if (piece[i - 1] == '#')
		count = go_left(piece,i,count);
	if (count == 4)
		return (0);
	else 
	{
		ft_putstr("error");
		return (1);
	}
}
