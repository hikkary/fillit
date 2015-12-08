/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 20:41:57 by zkerkeb           #+#    #+#             */
/*   Updated: 2015/12/08 21:07:07 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int ft_try(char *str, int i, int l)
{
	while ((str[i] != '\n') && (str[i] == '.' || str[i] == '#'))
		i++;
	if (i != 4)
	{
		printf("error");
		return (1);
	}
	l++;
	if (l == 4)
		i = i + 2;
	while (str[i] != '\0')
	{
		ft_try(str, i, l);		
	}
	return (0); 
}
