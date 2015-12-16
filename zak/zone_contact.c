#include <stdio.h>
int *go_rightz(char *chaine, char *piece, int chainei, int piecei, int *count);
int *go_downz(char *chaine, char *piece, int chainei, int piecei, int *count);
int *go_upz(char *chaine, char *piece, int chainei, int piecei, int *count);
int *go_leftz(char *chaine, char *piece, int chainei, int piecei, int *count);

int ft_contact(char chaine)
{
	if (chaine >= 65 && chaine <= 122)
	   return(1);
	else
		return (0);
}

int *zone(char *chaine, int pc, int pl, int *count)
{
  if(ft_contact(chaine[pl][pc + 1]))
    {
      printf("|D|");
      count[0]++;
    }
  if(ft_contact(chaine[pl + 1][pc]))
    { 
      printf("|B|");
      count[0]++;
    }
 if(ft_contact(chaine[pl - 1][pc]))
    {
      printf("|H|");
      count[0]++;
    }
 if(ft_contact(chaine[pl][pc - 1]))
    {
      printf("|G|");
      count[0]++;
    }
  return (count);
}

int *go_rightz(char *chaine, char *piece, int pc, int pl, int piecei, int *count)
{
  count[1]++;
  printf(" ---nb fois %d----",count[1]);
  if(count[1] < 4)
    {
  printf(" Right");
  piece[piecei] = 'x';
  piecei = piecei + 1;
  pc = pc + 1;
  count = zone(chaine, pc, pl, count);
  if(piece[piecei + 1] == '#' && chaine[pl][pc + 1] == '.')
    {
      count = go_rightz(chaine, piece, pc, pl, piecei, count);
    }
  if(piece[piecei + 5] == '#' && chaine[pl + 1][pc] == '.')
    {
      count = go_downz(chaine, piece, pc, pl, piecei, count);
    }
  if(piece[piecei - 5] == '#' && chaine[pl - 1][pc] == '.')
    {
      count = go_upz(chaine, piece, pc, pl, count);
    }
  if(piece[piecei - 1] == '#' && chaine[pl][pc - 1] == '.')
    {
      count = go_leftz(chaine, piece, pc, pl, count);
    }
    }
  return (count);
}
int *go_downz(char *chaine, char *piece, int pc, int pl, int piecei, int *count)
{
  count[1]++;
  printf(" ---nb fois %d----",count[1]);
  if(count[1] < 4)
    {
  printf(" down");
  piece[piecei] = 'x';
  piecei = piecei + 5;
  pl = pl + 1;
  count = zone(chaine, pc, pl, count);
  if(piece[piecei + 1] == '#' && chaine[pl][pc + 1] == '.')
    {
      count = go_rightz(chaine, piece, pc, pl, piecei, count);
    }
  if(piece[piecei + 5] == '#' && chaine[pl + 1][pc] == '.')
    {
      count = go_downz(chaine, piece, pc, pl, piecei, count);
    }
  if(piece[piecei - 5] == '#' && chaine[pl - 1][pc] == '.')
    {
      count = go_upz(chaine, piece, pc, pl, count);
    }
  if(piece[piecei - 1] == '#' && chaine[pl][pc - 1] == '.')
    {
      count = go_leftz(chaine, piece, pc, pl, count);
    }
       }
return (count);
}

int *go_upz(char *chaine, char *piece, int pc, int pl, int piecei, int *count)
{
  count[1]++;
  printf(" ---nb fois %d----",count[1]);
  if(count[1] < 4)
    {
    
  printf(" up");
  piece[piecei] = 'x';
  piecei = piecei - 5;
  pl = pl - 1;
  count = zone(chaine, pc, pl, count);
  if(piece[piecei + 1] == '#' && chaine[pl][pc + 1] == '.')
    {
      count = go_rightz(chaine, piece, pc, pl, piecei, count);
    }
  if(piece[piecei + 5] == '#' && chaine[pl + 1][pc] == '.')
    {
      count = go_downz(chaine, piece, pc, pl, piecei, count);
    }
  if(piece[piecei - 5] == '#' && chaine[pl - 1][pc] == '.')
    {
      count = go_upz(chaine, piece, pc, pl, count);
    }
  if(piece[piecei - 1] == '#' && chaine[pl][pc - 1] == '.')
    {
      count = go_leftz(chaine, piece, pc, pl, count);
    }
     }
  return (count);
}

int *go_leftz(char *chaine, char *piece, int pc, int pl, int piecei, int *count)
{
  count[1]++;
printf(" ---nb fois %d----",count[1]);
  if(count[1] < 4)
    {
      
  printf(" left");
  piece[piecei] = 'x';
  piecei = piecei - 1;
  pc = pc - 1;
  count = zone(chaine, pc, pl, count);
  if(piece[piecei + 1] == '#' && chaine[pl][pc + 1] == '.')
    {
      count = go_rightz(chaine, piece, pc, pl, piecei, count);
    }
  if(piece[piecei + 5] == '#' && chaine[pl + 1][pc] == '.')
    {
      count = go_downz(chaine, piece, pc, pl, piecei, count);
    }
  if(piece[piecei - 5] == '#' && chaine[pl - 1][pc] == '.')
    {
      count = go_upz(chaine, piece, pc, pl, count);
    }
  if(piece[piecei - 1] == '#' && chaine[pl][pc - 1] == '.')
    {
      count = go_leftz(chaine, piece, pc, pl, count);
    }
    }
  return (count);
}
