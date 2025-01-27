#include "udp.h"
#include "erreur.h"
#include "nombre.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
int traiter_commande_wrapper(int argc, char** argv){
      traiter_commande(argc[2], argv[0], "<port>\nmauvais nombre d'arguments");
      traiter_commande (est_un_port_non_reserve(argv[2]), argv[0], "<port>\n<port> est un port non réservé");
}
int main(int argc, char** argv) {
      
      traiter_commande_wrapper(argc,argv);{}
      


      
      exit(0);
}
