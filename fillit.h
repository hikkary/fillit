/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:49:20 by avella            #+#    #+#             */
/*   Updated: 2015/12/19 13:49:23 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 1
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

char	*ft_strdup(const char *s1);
int		*go_right(char *chaine, char *piece, int chainei, int piecei, int *count_length);
int		*go_down(char *chaine, char *piece, int chainei, int piecei, int *count_length);
int		*go_up(char *chaine, char *piece, int chainei, int piecei, int *count_length);
int		*go_left(char *chaine, char *piece, int chainei, int piecei, int *count_length);
void	ft_all(char *piece);
#endif
