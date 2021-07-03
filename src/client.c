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
	{
		char question[300];
		char choixA[40];
		char choixB[40];
		char choixC[40];
		char choixD[40];
		char mssg[30];
		// char bonneR[30];
		char rep[2];
		int i = 0;
		while (i < 7)
		{
			memset(question, 0, 300);
			memset(choixA, 0, 40);
			memset(choixB, 0, 40);
			memset(choixC, 0, 40);
			memset(choixD, 0, 40);
			memset(rep, 0, 2);
			send(socketClient, mode, strlen(mode) + 1, 0);
			recv(socketClient, question, 300, 0);
			printf("question : %s\n", question);
			sleep(1);
			recv(socketClient, choixA, 40, 0);
			printf("choix A : %s\n", choixA);
			sleep(1);

			recv(socketClient, choixB, 40, 0);
			printf("choix B : %s\n", choixB);
			sleep(1);

			recv(socketClient, choixC, 40, 0);
			printf("choix C : %s\n", choixC);
			sleep(1);

			recv(socketClient, choixD, 40, 0);
			printf("choix D : %s\n", choixD);
			sleep(1);

			printf("veuillez choisir un choix, soit A, B, C et D\n");
			scanf("%s", rep);
			sleep(1);

			send(socketClient, rep, ft_strlen(rep), 0);
			recv(socketClient, mssg, 31, 0);
			printf("%s\n", mssg);
			printf("\033[0m");
;			sleep(1);
			i++;

		}
		recv(socketClient, &player, sizeof(player), 0);
		// printf("%s 's total scores is %d\n", player.nom, player.score);
	}
	// printf("%s\n", player->nom);
	// close(socketClient);
	return (0);
}