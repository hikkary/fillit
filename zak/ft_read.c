/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:05:16 by zkerkeb           #+#    #+#             */
/*   Updated: 2015/12/14 20:06:28 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_read(int fd, char *buf)
{
	int ret;
	int len;

	len = 0;	
	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
	{
		len += ret;
	}
	return (len); 
}

char *ft_write(int fd, char *buf, char *str)
{
	int	i;
	int ret;
	
	i = 0;
	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
	{
		str[i] = *buf;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int ft_check_open(int fd)
{
	if (fd == -1)
	{
		ft_putstr("error");
		return(1);		
	}
	return (0);
}
/*
void ft_tab3(char ***piece)
{
	while(piece)
	{
		printf("%c", piece[s][h][i]);
		i++;
		if(i == 5)
		{
			i = 0;
			h++;
		}
		if (h == 4 && s <= nt)
		{
			h = 0;
			s++;
		}
}
*/
int main(int argc, char **argv)
{
	int fd;
	char buf[BUF_SIZE + 1];
	char *tetris;
	char ***piece;
	int nt;
	int i;
	int h;
	int s;

	s = 0;
	h = 0;
	i = 0;

	if (argc > 2 || argc == 1)
	{
		ft_putstr("error");
		return(0);
	}
	piece = NULL;
	fd = open(argv[1], O_RDONLY); 
	ft_check_open(fd);
	nt = ft_read(fd, buf);
	tetris = (char *)malloc(sizeof(char *) * (nt + 1));
	fd = open(argv[1], O_RDONLY); 
	tetris = ft_write(fd, buf, tetris);
	ft_try(tetris,0,0);
	ft_test_form(tetris); 
	nt = nt / 21;
	piece = (char ***)malloc(sizeof(char **) * (nt + 1));
	piece = ft_split(tetris, piece, nt);

	return(0);
}
