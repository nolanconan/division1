#include "udp.h"
#include "erreur.h"
#include "nombre.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>

int main(int argc, char** argv) {
    // Vérification du nombre d'arguments
    traiter_commande(argc == 2, argv[0], "<port>\nmauvais nombre d'arguments");

    // Vérification si le port est non réservé
    traiter_commande(est_un_port_non_reserve(argv[1]), argv[0], "<port>\n<port> est un port non réservé");

    // Conversion du port en entier
    int port = (int) convertir_nombre(argv[1]);

    // Création et attachement de la socket
    SOCK sock;
    creer_socket("", port, &sock);
    attacher_socket(&sock);

    // Buffer pour recevoir les messages
    char buffer[1024];

    printf("Serveur en attente de messages sur le port %d...\n", port);

    while (1) {
        // Réception d'un message
        recevoir_message(&sock, buffer);
        printf("Message reçu : %s\n", buffer);

        // Émission d'une réponse
        char* reponse = "Message reçu";
        envoyer_message(&sock, reponse);
    }

    // Fermeture de la connexion
    fermer_connexion(&sock);

    exit(0);
}
