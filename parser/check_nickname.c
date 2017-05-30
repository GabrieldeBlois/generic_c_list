/*
** check_nickname.c for myirc in /home/flipper/rendu/PSU_2016_myirc/server/parser/
**
** Made by Matthis Le Texier
** Login   <matthis.le-texier@epitech.eu@epitech.eu>
**
** Started on  Tue May 30 18:09:51 2017 Matthis Le Texier
** Last update Tue May 30 19:24:35 2017 Matthis Le Texier
*/

#include "server.h"

int     cmp_nick(void* d1, void* d2)
{
  char* n1;
  char* n2;

  n1 = (char*)d1;
  n2 = ((t_client*)d2)->name;
  if (!n1 || !n2)
    return 1;
  if (strcmp(n1, n2) == 0)
    return 0;
  return 1;
}

int     is_chars_valid(char* str)
{
  int   i;

  i = 0;
  while (str[i]) {
    if (c < ' ' || c >= 127)
      return 0;
  }
  return 1;
}

int   check_nickname(int sock, char* nick)
{
  if (strlen(nick) > NICK_MAX_SIZE || !is_chars_valid(nick))
    return (send_reply(sock, ERR_ERRONEUSNICKNAME, nick, 0), 0);
  if (nick_exist(list, nick))
    return (send_reply(sock, ERR_NICKNAMEINUSE, nick, 0), 0);
  return 1;
}
