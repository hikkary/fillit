#include "libft.h"
#include <stdlib.h>
#include <stdio.h>


int try_1(char *chaine)
{
  int i;

  i = 0;
  while(chaine[i] != '\0')
    {
      if(chaine[i] != '.' && chaine[i] != '#' && chaine[i] != '\n')
	return (0);
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

int try_3(char *chaine)
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

int try_4(char *chaine)
{
  int i;
  int count;
  int max;
  int i2;
  int line;
  int myline;

  myline = 0;
  line = 1;
  i2 = 0;
  max = 10;  
  count = 1;
  i = 0;
  while(chaine[i] != '\0')
    {
      while(chaine[i] != '\n')
	{
	  if(chaine[i] == '#')
	    {
	      if(max > i2)
		{
		  myline = line;
		  max = i2;
		}
	    }
	  i2++;
	  i++;
	}
      i++;
      i2 = 0;
      line++; 
   }
  i =  (5 * (myline - 1)) + max;
  printf("max : ");
    printf("%d", max);
    printf("line : ");
    printf("%d", myline);
    printf("my i : ");
    printf("%d", i);
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
  if(try_1(chaine) && try_2(chaine) && try_3(chaine) && try_4(chaine))
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
  chaine = ft_strdup("...#\n..##\n..#.\n....\n");  
  printf("%d", all_try(chaine));  
  return (0);
}
