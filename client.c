#include "player.h"


int main()
{
	t_player player;
	
	char mode[20];
	// mode = (char *)malloc(sizeof(char) * 10);
	int socketClient = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addrClient;
	addrClient.sin_addr.s_addr = inet_addr("127.0.0.1");
	addrClient.sin_family = AF_INET;
	addrClient.sin_port = htons(1337);
	connect(socketClient, (const struct sockaddr *)&addrClient, sizeof(addrClient));
	printf("connecté \n");

	char msg[30];
	recv(socketClient, msg, 31, 0);
	printf("%s\n", msg);
	// player->nom = (char *)malloc(sizeof(char) * 30);
	scanf("%s", player.nom);
	send(socketClient, &player, sizeof(player), 0);
	printf("Bonjour  \033[0;32m%s !  \033[0mBienvenue dans notre jeu en ligne\n" , player.nom);
	printf("T'es nouveau! donc votre rank est IRON\n");
	printf("veuillez choisir un mode de jeu, unique ou multijoueur!\n");
	scanf("%s", mode);
	printf("===>size = %lu\n", strlen(mode));
	printf("--> %s\n", mode);
	if (strcmp(mode, "unique"))
	{
		printf("choix erroné\n");
		exit(0);
	}
	else 
		send(socketClient, mode, strlen(mode) + 1, 0);
	// printf("%s\n", player->nom);
	close(socketClient);
	return (0);
}