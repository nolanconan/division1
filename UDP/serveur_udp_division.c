#include "udp.h"
#include "erreur.h"
#include "nombre.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>

int main(int argc, char** argv) {
    
    traiter_commande(argc == 2, argv[0], "<port>\nmauvais nombre d'arguments");

    
    traiter_commande(est_un_port_non_reserve(argv[1]), argv[0], "<port>\n<port> est un port non réservé");

    
    int port = (int) convertir_nombre(argv[1]);

   
    SOCK sock;
    creer_socket("", port, &sock);
    attacher_socket(&sock);

   
    char buffer[1024];

    printf("Serveur en attente de messages sur le port %d...\n", port);

    while (1) {
        
        recevoir_message(&sock, buffer);
        printf("Message reçu : %s\n", buffer);

        
        char* reponse = "Message reçu";
        envoyer_message(&sock, reponse);
    }

    
    fermer_connexion(&sock);

    exit(0);
}
