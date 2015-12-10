/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 20:41:57 by zkerkeb           #+#    #+#             */
/*   Updated: 2015/12/09 15:11:31 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//#include <stdio.h>

int ft_try(char *str, int i, int l)
{
	int t;

	t = 0;
	while ((str[i] != '\n' && str[i] != '\0') && (str[i] == '.' || str[i] == '#'))
	{
		t++;
		i++;
	}
//	printf("%d",t);
//	printf("\n");
	if (t != 4)
	{
	//	printf("error");
		return (0);
	}
	l++;
	i++;
	if (str[i + 1] == '\0')
	   return (0);	
	if (l == 4)
	{
		l = 0;
		i++ ;
	}	
	ft_try(str, i, l);
	
	return(0);
}
