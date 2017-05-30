/*
** cmd.c for myirc in /home/flipper/rendu/PSU_2016_myirc/server/parser/
**
** Made by Matthis Le Texier
** Login   <matthis.le-texier@epitech.eu@epitech.eu>
**
** Started on  Mon May 29 20:14:43 2017 Matthis Le Texier
** Last update Tue May 30 17:15:06 2017 Matthis Le Texier
*/

#include "server.h"

t_cmd   g_cmd[] =
{
  {"server",      cmd_server},
  {"nick",        cmd_nick},
  {"list",        cmd_list},
  {"join",        cmd_join},
  {"part",        cmd_part},
  {"users",       cmd_users},
  {"names",       cmd_names},
  {"msg",         cmd_msg},
  {"accept_file", cmd_acc_file},
  {"", NULL}
}

int   handle_cmd(int sock, char* input)
{
  int i;

  if (!input)
    return 1;
  if (input[0] == '/') {
    i = 1;
    while (g_cmd[i].fct && strncmp(input, g_cmd[i].name, strlen(g_cmd[i].name)))
      i++;
    if (g_cmd[i].fct)
      (g_cmd[i].fct)(sock, input + strlen(g_cmd[i].name) + 2);
    else
      return (fprintf(stderr,"%s\n","Unknown command."), 1);
  }
  else {
    //send message to all of the users connected to the current channel
  }
}
