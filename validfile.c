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
	      i++;
	    }
	  if(count != 4)
	    return (0);
	  count = 0;
	  i++;
	  time++;
	}
      time = 0;
      if(chaine[i] == '\0')
	return (1);
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
