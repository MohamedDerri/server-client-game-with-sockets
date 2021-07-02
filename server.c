#include "player.h"


void	*client_thread(void *arg)
{
	t_player player;
	
	char mode[20];
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




	close(socket);
	free(arg);
	pthread_exit(NULL);
}

int main(void)
{

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

