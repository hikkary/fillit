/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcour.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:42:56 by avella            #+#    #+#             */
/*   Updated: 2015/12/19 13:43:43 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int *go_right(char *chaine, char *piece, int chainei, int piecei, int *count_length)
{
	count_length[0]++;
	piece[piecei] = 'x'; 
	piecei = piecei + 1;
	chainei = chainei + 1;
	chaine[chainei] = 'x';
	if (piece[piecei + 1] == '#' && chaine[chainei + 1] == '.')
	{
		count_length = go_right(chaine, piece, chainei, piecei, count_length);
	}
	if (piece[piecei + 5] == '#' && chaine[chainei + count_length[1]] == '.')
	{
		count_length = go_down(chaine, piece, chainei, piecei, count_length);
	}
	if (piece[piecei - 5] == '#' && chaine[chainei - count_length[1]] == '.')
	{
		count_length = go_up(chaine, piece, chainei, piecei, count_length);
	}
	if (piece[piecei - 1] == '#' && chaine[chainei - 1] == '.')
	{
		count_length = go_left(chaine, piece, chainei, piecei, count_length);
	}
	return (count_length);
}

int *go_down(char *chaine, char *piece, int chainei, int piecei, int *count_length)
{
	count_length[0]++;
	piece[piecei] = 'x';
	piecei = piecei + 5;
	chainei = chainei + count_length[1];
	chaine[chainei] = 'x';   
	if (piece[piecei + 1] == '#' && chaine[chainei + 1] == '.')
	{
		count_length = go_right(chaine, piece, chainei, piecei, count_length);
	}
	if (piece[piecei + 5] == '#' && chaine[chainei + count_length[1]] == '.')
	{
		count_length = go_down(chaine, piece, chainei, piecei, count_length);
	}
	if (piece[piecei - 5] == '#' && chaine[chainei - count_length[1]] == '.')
	{
		count_length = go_up(chaine, piece, chainei, piecei, count_length);
	}
	if (piece[piecei - 1] == '#' && chaine[chainei - 1] == '.')
	{
		count_length = go_left(chaine, piece, chainei, piecei, count_length);
	}
	return (count_length);
}

int *go_up(char *chaine, char *piece, int chainei, int piecei, int *count_length)
{
	count_length[0]++;
	piece[piecei] = 'x';
	piecei = piecei - 5;
	chainei = chainei - count_length[1];
	chaine[chainei] = 'x';
	if (piece[piecei + 1] == '#' && chaine[chainei + 1] == '.')
	{
		count_length = go_right(chaine, piece, chainei, piecei, count_length);
	}
	if (piece[piecei + 5] == '#' && chaine[chainei + count_length[1]] == '.')
	{
		count_length = go_down(chaine, piece, chainei, piecei, count_length);
	}
	if (piece[piecei - 5] == '#' && chaine[chainei - count_length[1]] == '.')
	{
		count_length = go_up(chaine, piece, chainei, piecei, count_length);
	}
	if (piece[piecei - 1] == '#' && chaine[chainei - 1] == '.')
	{
		count_length = go_left(chaine, piece, chainei, piecei, count_length);
	}
	return (count_length);
}

int *go_left(char *chaine, char *piece, int chainei, int piecei, int *count_length)
{
	count_length[0]++;
	piece[piecei] = 'x';

	piecei = piecei - 1;
	chainei = chainei - 1;
	chaine[chainei] = 'x';  
	if (piece[piecei + 1] == '#' && chaine[chainei + 1] == '.')
	{
		count_length = go_right(chaine, piece, chainei, piecei, count_length);
	}
	if (piece[piecei + 5] == '#' && chaine[chainei + count_length[1]] == '.')
	{
		count_length = go_down(chaine, piece, chainei, piecei, count_length);
	}
	if (piece[piecei - 5] == '#' && chaine[chainei - count_length[1]] == '.')
	{
		count_length = go_up(chaine, piece, chainei, piecei, count_length);
	}
	if (piece[piecei - 1] == '#' && chaine[chainei - 1] == '.')
	{
		count_length = go_left(chaine, piece, chainei, piecei, count_length);
	}
	return (count_length);
}
