#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int try_1(char *chaine)
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
          if(chaine[i] == '.' || chaine[i] == '#')
            count++;
	  printf("%c",chaine[i]);
          i++;
        }
      printf("%c",chaine[i]);
      if(count != 4)
        return (0);
      count = 0;
      i++;
      time++;
    }
  time = 0;
  if(chaine[i] == '\0')
    return (1);
  printf("%c", chaine[i]);
  i++;
    }
  return (1);
}






int try_2(char *chaine)
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
	      if(chaine[i] == '#')
		count++;
	      i++;
	    }
	  i++;
	  time++;
	}
     if(count != 4)
       return (0);
     if(chaine[i] == '\0')
       return (1);
      count = 0;
      time = 0;
      i++;
    }
  return (1);
}

/*
int try_3(char *chaine)
{
  int i;
  int count;
  int ai;

  ai = 0;
  count = 0;
  i = 0;
  while(chaine[ai] != '#')
    ai++;
  while(chaine[i] != '\0')
    {
      if(chaine[i] == '#')
	{
	  if(chaine[i + 1] == '#' || chaine[i + 5] == '#' || chaine[i - 1] == '#' || chaine[i - 5] == '#')
	    {
	      count++;
	    }
	}
      i++;
    }
  if(count != 4)
    return (0);
  return (1);
  }*/


int try_3(char *chaine)
{
  int i;
  int count;
  
  count = 1;
  i = 0;
  while (chaine[i] != '#')
    i++;
  while(chaine[i] == '#' && count < 4 && chaine[i] != '\0')
    {
      chaine[i] = 'x';
      if(chaine[i + 1] == '#')
	{
	  i = i + 1;
	  count++;
	}
      else if(chaine[i + 5] == '#')
	{
	  count++;
          i = i + 5;
	}
      else if(chaine[i - 5] == '#')
	{
	  count++;
          i = i - 5;
        }
      else if(chaine[i - 1] == '#')
	{
	  count++;
          i = i - 1;
        }
      else if(count == 3)
	{
	  i = 0;
	  while(chaine[i] != '#' && chaine[i] != '\0')
	    i++;
	  if(chaine[i + 1] == 'x' || chaine[i + 5] == 'x' || chaine[i - 1] == 'x' || chaine[i - 5] == 'x')
              count++;
	}
    }
  if (count != 4)
    return (0); 
  return (1);
}


int all_try(char *chaine)
{
  if(try_1(chaine) && try_2(chaine) && try_3(chaine))
    return (1);
  return (0);
}


int main()
{
  char *chaine;
  /*
  if(argc != 2)
    {
      ft_putstr("error\n");
      return (0);
      }*/
  chaine = ft_strdup("##..\n.##.\n....\n#....\n");
  printf("%d", all_try(chaine));  
  return (0);
}
