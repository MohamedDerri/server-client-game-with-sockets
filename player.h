#ifndef SOCKETS_H
# define SOCKETS_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_CONNECTIONS 12
#define MAX_PLAYERS 12

typedef enum	e_rank
{
	IRON, BRONZE, SILVER, GOLD, PLATIUNIUM, DIAMOND
}				t_rank;


typedef struct	s_player
{
	char 	nom[30];
	int 	score;
	t_rank 	rank;

}				t_player;


#endif