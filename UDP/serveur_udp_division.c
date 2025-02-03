#include "udp.h"
#include "erreur.h"
#include "nombre.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

int main(int argc, char** argv) {
    traiter_commande(argc == 2, argv[0], "<port>\nmauvais nombre d'arguments");

    traiter_commande(est_un_port_non_reserve(argv[1]), argv[0], "<port>\n<port> est un port non réservé");

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        traiter_erreur("Erreur lors de la création de la socket");
    }

    // Configuration de l'adresse du serveur
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons((uint16_t) convertir_nombre(argv[1]));

    // Liaison de la socket avec l'adresse du serveur
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        traiter_erreur("Erreur lors de la liaison de la socket");
    }

    // Ajoutez ici le code pour recevoir et traiter les messages UDP

    close(sockfd);
    exit(0);
}
