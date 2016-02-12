/*
** match.c for Match in Piscine_C_match-nmatch
**
** Made by michel mancier
** Login   <mancie_m@epitech.net>
**
** Started on  Sun Oct 11 19:24:19 2015 michel mancier
** Last update Sun Jan 24 20:48:41 2016 Michel Mancier
*/

int	nmatching(char *s1, char *s2)
{
  if (*s1 != '\0' && *s2 == '*')
    return (nmatching(s1 + 1, s2) + nmatching(s1, s2 + 1));
  if (*s1 == '\0' && *s2 == '*')
    return (nmatching(s1, s2 + 1));
  if (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
    return (nmatching(s1 + 1, s2 + 1));
  if (*s1 == *s2 && *s1 == '\0' && *s2 == '\0')
    return (1);
  return (0);
}

int	match(char *s1, char *s2)
{
  if (nmatching(s1, s2) > 0)
    return (1);
  else if (nmatching(s1, s2) == 0)
    return (0);
  return (0);
}
