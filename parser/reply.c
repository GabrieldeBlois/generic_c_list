/*
** reply.c for ftp in /home/flipper/rendu/PSU_2016_myftp/src/
**
** Made by Matthis Le Texier
** Login   <matthis.le-texier@epitech.eu@epitech.eu>
**
** Started on  Thu May 18 17:20:05 2017 Matthis Le Texier
** Last update Tue May 30 19:43:04 2017 Matthis Le Texier
*/

#include "ftp.h"

t_reply     g_reply[] =
{
  {RPL_WELCOME,  "%d :Welcome to the Internet Relay Network %s!\r\n", 0}
  {RPL_YOURHOST, "%d :Your host is %s, running version %s\r\n", 0},
  {RPL_CREATED,  "%d :This server was created %s\r\n", 0},
  {RPL_BOUNCE,   "%d :Try server %s,port %s\r\n", 1},
  {RPL_LUSERCLIENT, "%d :There are %s users on 1 server\r\n", 0}
  {ERR_NOSUCHNICK      ,  "%d %s :No such nick/channel\r\n", 0},
  {ERR_NOSUCHSERVER    ,  "%d %s :No such server\r\n", 0},
  {ERR_NOSUCHCHANNEL   ,  "%d %s :No such channel\r\n", 0},
  {ERR_CANNOTSENDTOCHAN,  "%d %s :Cannot send to channel\r\n", 0},
  {ERR_TOOMANYCHANNELS ,  "%d %s :You have joined too many channels\r\n", 0},
  {ERR_WASNOSUCHNICK   ,  "%d %s :There was no such nickname\r\n", 0},
{ERR_TOOMANYTARGETS,"%d %s :Duplicate recipients. No message delivered\r\n", 0},
  {ERR_NOORIGIN        ,  "%d %s :No origin specified\r\n", 0},
  {ERR_NORECIPIENT     ,  "%d :No recipient given(%s)\r\n", 0},
  {ERR_NOTEXTTOSEND    ,  "%d %s:No text to send\r\n", 0},
  {ERR_NOTOPLEVEL      ,  "%d %s :No toplevel domain specified\r\n", 0},
  {ERR_WILDTOPLEVEL    ,  "%d %s :Wildcard in toplevel domain\r\n", 0},
  {ERR_UNKNOWNCOMMAND  ,  "%d %s :Unknown command\r\n", 0},
  {ERR_NOMOTD          ,  "%d %s:MOTD File is missing\r\n", 0},
  {ERR_NOADMININFO     ,  "%d %s :No administrative info available\r\n", 0},
  {ERR_FILEERROR       ,  "%d File error doing %s on %s\r\n", 1},
  {ERR_NONICKNAMEGIVEN ,  "%d %s:No nickname given\r\n", 0},
  {ERR_ERRONEUSNICKNAME,  "%d %s :Erroneus nickname\r\n", 0},
  {ERR_NICKNAMEINUSE   ,  "%d %s :Nickname is already in use\r\n", 0},
  {ERR_NICKCOLLISION   ,  "%d %s :Nickname collision KILL\r\n", 0},
  {ERR_USERNOTINCHANNEL,  "%d %s %s :They aren't on that channel\r\n", 1},
  {ERR_NOTONCHANNEL    ,  "%d %s :You're not on that channel\r\n", 0},
  {ERR_USERONCHANNEL   ,  "%d %s %s :is already on channel\r\n", 1},
  {ERR_NOLOGIN         ,  "%d %s :User not logged in\r\n", 0},
  {ERR_SUMMONDISABLED  ,  "%d %s:SUMMON has been disabled\r\n", 0},
  {ERR_USERSDISABLED   ,  "%d %s:USERS has been disabled\r\n", 0},
  {ERR_NOTREGISTERED   ,  "%d %s:You have not registered\r\n", 0},
  {ERR_NEEDMOREPARAMS  ,  "%d %s :Not enough parameters\r\n", 0},
  {ERR_ALREADYREGISTRED,  "%d %s:You may not reregister\r\n", 0},
  {ERR_NOPERMFORHOST   ,  "%d %s:Your host isn't among the privileged\r\n", 0},
  {ERR_PASSWDMISMATCH  ,  "%d %s:Password incorrect\r\n", 0},
  {ERR_YOUREBANNEDCREEP,  "%d %s:You are banned from this server\r\n", 0},
  {ERR_KEYSET          ,  "%d %s :Channel key already set\r\n", 0},
  {ERR_CHANNELISFULL   ,  "%d %s :Cannot join channel (+l)\r\n", 0},
  {ERR_UNKNOWNMODE     ,  "%d %s :is unknown mode char to me\r\n", 0},
  {ERR_INVITEONLYCHAN  ,  "%d %s :Cannot join channel (+i)\r\n", 0},
  {ERR_BANNEDFROMCHAN  ,  "%d %s :Cannot join channel (+b)\r\n", 0},
  {ERR_BADCHANNELKEY   ,  "%d %s :Cannot join channel (+k)\r\n", 0},
{ERR_NOPRIVILEGES,"%d %s:Permission Denied- You're not an IRC operator\r\n", 0},
  {ERR_CHANOPRIVSNEEDED,  "%d %s :You're not channel operator\r\n", 0},
  {ERR_CANTKILLSERVER  ,  "%d %s:You cant kill a server!\r\n", 0},
  {ERR_NOOPERHOST      ,  "%d %s:No O-lines for your host\r\n", 0},
  {ERR_UMODEUNKNOWNFLAG,  "%d %s:Unknown MODE flag\r\n", 0},
  {ERR_USERSDONTMATCH  ,  "%d %s:Cant change mode for other users\r\n", 0},
  {-1,  (char*)0, 0}
};

int     send_reply(int fd, int code, char* param, char* msg)
{
  int   i;
  char  buffer[SIZE_BUFF];

  i = 0;
  while (g_reply[i].code != -1 && g_reply[i].code != code) i++;
  if (g_reply[i].code == -1)
    return -1;
  if (g_reply[i].add_msg == 1 && msg)
    sprintf(buffer, g_reply[i].fmt, g_reply[i].code, param, msg);
  else
    sprintf(buffer, g_reply[i].fmt, g_reply[i].code);
  write(fd, buffer, strlen(buffer));
  return 0;
}
