/*
** server_cmds.c for myirc in /home/flipper/rendu/PSU_2016_myirc/server/parser/
**
** Made by Matthis Le Texier
** Login   <matthis.le-texier@epitech.eu@epitech.eu>
**
** Started on  Mon May 29 20:28:29 2017 Matthis Le Texier
** Last update Tue May 30 19:44:55 2017 Matthis Le Texier
*/

#include <stdlib.h>
#include <unistd.h>
#include "server.h"
#include "reply.h"

int     cmd_server(int sock, char* args)
{
  char str[15];

  send_reply(sock, RPL_WELCOME, host, 0);
  send_reply(sock, RPL_YOURHOST, host, "1.0");
  send_reply(sock, RPL_CREATED, date_creation, 0);
  sprintf(str, "%d", nb_client);
  send_reply(sock, RPL_LUSERCLIENT, str, 0);
}

int     cmd_nick(int sock, char* args)
{
  int   i;
  char  buf[BUF_SIZE];

  memset(buf, 0, BUF_SIZE);
  i = 0;
  while (args[i] && args[i] != ' ' && args[i] != '\n') {
    buf[i] = args[i];
    i++;
  }
  if (strlen(buf) == 0)
    return (send_reply(sock, ERR_NONICKNAMEGIVEN, "", 0), 1);
  if (!check_nickname(sock, buf))
    return 1;
  memset(client->name, 0, NICK_MAX_SIZE + 1);
  strcpy(client->name, buf);
  //send_reply(sock, RPL_WELCOME, buf, 0);
  return 0;
}

int   cmd_users(int sock, char* args)
{

  return 0;
}
