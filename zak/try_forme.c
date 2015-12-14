#include <stdio.h>

int go_right(char *chaine, int i, int count);
int go_down(char *chaine, int i, int count);
int go_up(char *chaine, int i, int count);
int go_left(char *chaine, int i, int count);


int go_right(char *chaine, int i, int count)
{
if(count < 4)
    {
  i = i + 1;
  count++;
  chaine[i] = 'x';
  
  if(chaine[i + 1] == '#')
    {
      count = go_right(chaine , i, count);
    }
  if(chaine[i + 5] == '#')
    {
      count = go_down(chaine, i, count);
    }
  if(chaine[i - 5] == '#')
    {
      count = go_up(chaine, i, count);
    }
  if(chaine[i - 1] == '#')
    {
      count = go_left(chaine, i, count);
    }
    }
  return (count);
}
int go_down(char *chaine, int i, int count)
{
if(count < 4)
    {
  i = i + 5;
  count++;
  chaine[i] = 'x';
  
  if(chaine[i + 1] == '#')
    {
      count = go_right(chaine , i, count);
    }
  if(chaine[i + 5] == '#')
    {
      count = go_down(chaine, i, count);
    }
  if(chaine[i - 5] == '#')
    {
      count = go_up(chaine, i, count);
    }
  if(chaine[i - 1] == '#')
    {
      count = go_left(chaine, i, count);
    }
    }
  return (count);
}
int go_up(char *chaine, int i, int count)
{
if(count < 4)
    {
  i = i - 5;
  count++;
  chaine[i] = 'x';
  
  if(chaine[i + 1] == '#')
    {
      count = go_right(chaine , i, count);
    }
  if(chaine[i + 5] == '#')
    {
      count = go_down(chaine, i, count);
    }
  if(chaine[i - 5] == '#')
    {
      count = go_up(chaine, i, count);
    }
  if(chaine[i - 1] == '#')
    {
      count = go_left(chaine, i, count);
    }
    }
  return (count);
}
int go_left(char *chaine, int i, int count)
{
  if(count < 4)
    {
      i = i - 1;
      count++;
      chaine[i] = 'x';
      if(chaine[i + 1] == '#')
	{
	  count = go_right(chaine , i, count);
	}
      if(chaine[i + 5] == '#')
	{
	  count = go_down(chaine, i, count);
	}
      if(chaine[i - 5] == '#')
	{
	  count = go_up(chaine, i, count);
	}
      if(chaine[i - 1] == '#')
	{
	  count = go_left(chaine, i, count);
	}
    }
  return (count);
}
