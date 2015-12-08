/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 20:17:16 by zkerkeb           #+#    #+#             */
/*   Updated: 2015/12/08 16:23:20 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

int ft_first_link(char *str)
{
	t_list	*list;
	t_list	*tmp;
	int 	i;
	int 	v;
	int		p;

	p = 0;
	v = 0;
	i = 0;
//	printf("ntm");
	list = ft_lstnew((const char *)&str[i], 1);
	list->position = 0;
	tmp = list;
	//printf("s");
	//printf("%s", list->content);
	while(str[i] && v <= 3)
	{
		//p++;
		i++;
		printf("%s", list->content);
		list->right = ft_lstnew((const char *)&str[i], 1);
		if(list->right != NULL)
			list = list->right;
		list->left = tmp;
		tmp = list->right;
		v++;
	}
		list = list->left;
		printf("%s", list->content);
	//	printf("%s", list->content);	
	

	/*	while(list->right != NULL)
	{
		printf("%s",list->content);
		list = list->right;
	}*/
	return(0);
}

int main()
{
	char s[10] = "PAPE";

	ft_first_link(s);
	return(0);
}
