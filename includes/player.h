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
# include <fcntl.h>
# include "libft.h"

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

typedef struct	s_quiz
{
	char			*question;
	char			*choixA;
	char			*choixB;
	char			*choixC;
	char			*choixD;
	char			*bonneR;
	struct s_quiz	*next;
}				t_quiz;

// typedef struct	s_thread_argument
// {
// 	int		socket;
// 	t_quiz	*q;
// }				t_thread_argument;




#endif