#include "fillit.h"

int first_di(char *piece)
{
  int i;

  i = 0;
  while(piece[i] != '\0' && piece[i] != '#')
    i++;
  return (i);
}

int try(char *chaine, char *piece, int chainei, int piecei, int length)
{
  int *count_length;

  count_length = (int *)malloc(sizeof(int) * 3);
  count_length[0] = 0;
  count_length[1] = length;
  if(chaine[chainei] == '.' && piece[piecei] == '#')
    count_length[0]++;
  else
    return (0);
  chaine[chainei] = 'x';
  piece[piecei] = 'x';
  if(piece[piecei + 1] == '#' && chaine[chainei + 1] == '.')
    {
      count_length = go_right(chaine, piece, chainei, piecei, count_length);
    }
  if(piece[piecei + 5] == '#' && chaine[chainei + count_length[1]] == '.')
    {
      count_length = go_down(chaine, piece, chainei, piecei, count_length);
    }
  if(piece[piecei - 5] == '#' && chaine[chainei - count_length[1]] == '.')
    {
      count_length = go_up(chaine, piece, chainei, piecei, count_length);
    }
  if(piece[piecei - 1] == '#' && chaine[chainei - 1] == '.')
    {
      count_length = go_left(chaine, piece, chainei, piecei, count_length);
    }
   if(count_length[0] == 4)
    return (1);
  return (0);
}

int nb_tetri(char *chaine)
{
  int count;
  int time;
  int i;

  i = 0;
  time = 0;
  count = 0;
  while(chaine[i] != '\0')
    {
      while(time < 4)
	{
	  while(chaine[i] != '\n')
	    {
	      i++;
	    }
	  i++;
	  time++;
	}
      count++;
      time = 0;
      if(chaine[i] == '\0')
	return (count);
      i++;
    }
  return (count);
}

char **all_tetri(char *chaine, int i, int i2, int nb)
{
  char **tab;
  int index;
  
  index = 0;
  tab = (char **)malloc(sizeof(char *) * nb + 1);
  while(i < nb + 1)
    {
      tab[i] = (char *)malloc(sizeof(char) * 20);
      i++;
    }
  i = 0;
  while(i < nb)
    {
      while(i2 < 20 && chaine[index] != '\0')
	{
      	  tab[i][i2] = chaine[index];
      	  i2++;
	  index++;
	}
      tab[i][i2] = '\0';
      i2 = 0;
      index++;
      i++;
    }
  return (tab);
}

char *trans_di(char *chaine, char c)
{
  int i;

  i = 0;
  while(chaine[i] != '\0')
    {
      if(chaine[i] == 'x')
	chaine[i] = c;
      i++;
    }
  return (chaine);
}

char *malloc_chaine(char *chaine, int length)
{
  int i;
  int j;
  int index;
  
  index = 0;
  i = 0;
  j = 0;
  chaine = (char*)malloc(sizeof(char) * (length * (length + 1)) + 1);
  while(i < length)
    {
      while(j < length)
	{
	  chaine[index] = '.';
	  j++;
	  index++;
	}
       chaine[index] = '\n';
       index++;
      j = 0;
      i++;
    } 
    chaine[index] = '\0';
    return (chaine);
}

char *backtrack(int *iactuel, char *chaine, int tetri, char carac, int length, int chainei, char **tab, int nbt)
{
  int piecei;
  int i;


   while(carac != 'A' + nbt)
    {
      i = 0;
      piecei = first_di(tab[tetri]);   
      while(!try(ft_strdup(chaine), ft_strdup(tab[tetri]), iactuel[tetri], piecei,length) && chaine[iactuel[tetri]] != '\0')
	{
	  iactuel[tetri]++;
	}
      if(try(ft_strdup(chaine), ft_strdup(tab[tetri]), iactuel[tetri], piecei,length))
	{
	  try(chaine, ft_strdup(tab[tetri]), iactuel[tetri], piecei,length);
	  chaine = trans_di(chaine, carac);
	  tetri++;
	  carac++;
	  iactuel[tetri] = 0;
	}      
      else if(carac != 'A')
	{
	  carac--;
	  tetri--;
	  iactuel[tetri]++;
	  i = 0;
	  while(chaine[i] != '\0')
	    {
	      if(chaine[i] == carac)
		chaine[i] = '.';
	      i++;
	    }
	}
      else
	{
	  i = 0;
	  while(i < nbt)
	    {
	      iactuel[i] = 0;
	      i++;
	    }
	  chaine = malloc_chaine(chaine, ++length);
	  length++;
	  tetri = 0;
	  carac = 'A';
	}    
    }
  return (chaine);
}

void ft_all(char *piece)
{
  char *chaine;
  char **tab;
  int tetri;
  int length;
  char carac;
  int *iactuel;
  int nbt;

  chaine = NULL;
  nbt = nb_tetri(piece);
  iactuel = (int *)malloc(sizeof(int) * nbt + 1);
  tab = all_tetri(ft_strdup(piece), 0, 0, nb_tetri(piece));
  carac = 'A';
  length = 2;
  chaine = malloc_chaine(chaine, length);
  tetri = 0;
  length++;
  chaine = backtrack(iactuel, chaine, tetri, carac, length, 0, tab,nbt);
  printf("%s", chaine);
}
