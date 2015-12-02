#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
/*
int try_1(char *chaine)
{
  int i;
  int count;
  int countn;

  countn = 0;
  i = 0;
  count = 0;
  while(chaine[i] != '\0')
    {
      while(chaine[i] != '\n')
	{
	  if(chaine[i] == '.' || chaine[i] == '#')
	    count++;
	  i++;
	}
      if(count != 4)
	return (0);
      count = 0;
      i++;
    }
  return (1);
}

*/

int try_1(char *chaine, int i)
{
  int count;
  int time;

  time = 0;
  count = 0;
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
  printf("%d", i);
  if(chaine[i] == '\0')
    return (1);
  else if(chaine[i] == '\n')
    {
      printf("%d", i);    
      printf("%c",chaine[i]);
    try_1(chaine,i + 1);
    } 
  printf("dommage");
return (0);
}



/*
int try_2(char *chaine)
{
  //test si 4 #
}

int try_3(char *chaine)
{
  //test si les # sont a coter
}

int all_try(char chaine)
{
  if(try_1 && try_2 && try_3)
    return (1);
  return (0);
  }*/


int main()
{
  char *chaine;
  /*
  if(argc != 2)
    {
      ft_putstr("error\n");
      return (0);
      }*/
  //chaine = (char *)malloc(sizeof(char) * ft_strlen(argv[0]));
  chaine = "....\n....\n....\n....\n\n....\n....\n....\n....\n";
  printf("%d", try_1(chaine, 0));  
  return (0);
}
