#include "player.h"

t_quiz	*global_q;


void	display_list(t_quiz *q)
{
	t_quiz *z;

	z = q;
	while (z->next != NULL)
	{
		printf("quest : %s\n", z->question);
		printf("choix A : %s\n", z->choixA);
		printf("choix B : %s\n", z->choixB);
		printf("choix C : %s\n", z->choixC);
		printf("choix D : %s\n", z->choixD);
		printf("la bonne reponse : %s\n", z->bonneR);
		z = z->next;
	}
}


t_quiz	*parse_file(char *name)
{
	char *line;
	int i;
	int fd;
	int length2;
	char **tab;

	t_quiz	*head;
	t_quiz	*q;
	head = (t_quiz *)malloc(sizeof(t_quiz));
	q = head;

	if ((fd = open(name, O_RDONLY)) < 0)
		printf("OPEN_ERROR\n");
	i = 0;
	while ((i = get_next_line(fd, &line)) == 1)
	{
		if (i < 0)
			printf("READ_ERROR\n");
		tab = ft_strsplit(line, '/');
		length2 = ft_strlen(tab[0]);
		q->question = (char *)malloc(sizeof(char) * length2);
		ft_strcpy(q->question, tab[0]);
		length2 = ft_strlen(tab[1]);
		q->choixA = (char *)malloc(sizeof(char) * length2);
		ft_strcpy(q->choixA, tab[1]);
		length2 = ft_strlen(tab[2]);
		q->choixB = (char *)malloc(sizeof(char) * length2);
		ft_strcpy(q->choixB, tab[2]);
		length2 = ft_strlen(tab[3]);
		q->choixC = (char *)malloc(sizeof(char) * length2);
		ft_strcpy(q->choixC, tab[3]);
		length2 = ft_strlen(tab[4]);
		q->choixD = (char *)malloc(sizeof(char) * length2);
		ft_strcpy(q->choixD, tab[4]);
		length2 = ft_strlen(tab[5]);
		q->bonneR = (char *)malloc(sizeof(char) * length2);
		ft_strcpy(q->bonneR, tab[5]);
		q->next = (t_quiz *)malloc(sizeof(t_quiz));
		q = q->next;
	}
	q->next = (t_quiz *)malloc(sizeof(t_quiz));
	q->next = NULL;
	close(fd);
	return (head);
}


void	*client_thread(void *arg)
{
	t_player player;
	t_quiz	*global_q2;

	global_q2 = global_q;
	// display_list(global_q2);
	char mode[20];
	// char bienvenue[255];
	player.rank = 1;
	player.score = 0;
	int socket = *(int*)arg;
	const char msg[] = "quel est votre nom\n";
	send(socket, msg, strlen(msg) + 1, 0);
	recv(socket, &player, sizeof(player), 0);
	printf("client's name : \033[0;35m %s\n", player.nom);
	printf("===>%s\n", mode);
	recv(socket, &mode, 30, 0);
	printf("===>size = %lu\n", strlen(mode));
	printf("===>%s\n", mode);
	printf("\033[0m%s a choisi de jouer en mode : \033[0;35m %s\n", player.nom, mode);
	if (strcmp(mode, "unique") == 0)
	{
		char rep[2];
		char bRep[1];
		while (global_q2->next != NULL)
		{
			printf("quest = %s\n", global_q2->question);
			send(socket, global_q2->question, ft_strlen(global_q2->question) + 1, 0);
			sleep(1);
			send(socket, global_q2->choixA, ft_strlen(global_q2->choixA) + 1, 0);
			sleep(1);
			send(socket, global_q2->choixB, ft_strlen(global_q2->choixB) + 1, 0);
			sleep(1);
			send(socket, global_q2->choixC, ft_strlen(global_q2->choixC) + 1, 0);
			sleep(1);
			send(socket, global_q2->choixD, ft_strlen(global_q2->choixD) + 1, 0);
			sleep(1);
			recv(socket, rep, 2, 0);
			printf("==>%s\n", rep);
			if (ft_strcmp(global_q2->bonneR, global_q2->choixA) == 0)
				bRep[0] = 'A';
			if (ft_strcmp(global_q2->bonneR, global_q2->choixB) == 0)
				bRep[0] = 'B';
			if (ft_strcmp(global_q2->bonneR, global_q2->choixC) == 0)
				bRep[0] = 'C';
			if (ft_strcmp(global_q2->bonneR, global_q2->choixD) == 0)
				bRep[0] = 'D';
			if (ft_strcmp(rep, bRep) == 0)
			{
				char mssg[] = "reponse correct!\n";
				send(socket, mssg, ft_strlen(mssg) + 1, 0);
				player.score++;
			}
			sleep(3);
			global_q2 = global_q2->next;
		}
	}





	// close(socket);
	free(arg);
	pthread_exit(NULL);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage : ./server [quiz.txt]\n");
		exit(0);
	}
	t_quiz *quiz;
	quiz = (t_quiz *)malloc(sizeof(quiz));
	quiz = parse_file(argv[1]);
	// display_list(quiz);
	global_q = quiz;
	

	pthread_t clientThreads[MAX_PLAYERS];

	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addrServer;
	addrServer.sin_addr.s_addr = inet_addr("127.0.0.1");//htonl(INADDR_ANY);
	addrServer.sin_family = AF_INET;
	addrServer.sin_port = htons(1337);

	bind(serverSocket, (const struct sockaddr *)&addrServer, sizeof(addrServer));
	printf("bind ==> %d \n", serverSocket);

	listen(serverSocket, MAX_CONNECTIONS);
	printf("listening\n");


	int i = 0;
	while (i < MAX_PLAYERS)
	{
		struct sockaddr_in addrClient;
		socklen_t csize = sizeof(addrClient);
		int socketClient = accept(serverSocket, (struct sockaddr *)&addrClient, &csize);
		printf("accepting the connexion\n");
		printf("client id : \033[0;35m%d\n", socketClient);
		int *arg = malloc(sizeof(int));
		*arg = socketClient;
		pthread_create(&clientThreads[i], NULL, client_thread, arg);
		i++;
	}

	i = 0;
	while (i < MAX_PLAYERS)
	{
		pthread_join(clientThreads[i], NULL);
		i++;
	}
	close(serverSocket);
}
