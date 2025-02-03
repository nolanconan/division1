COMPILER=gcc
EXE_DIR=/tmp/
FICHIERS=erreur udp nombre
OBJS:=$(FICHIERS:%=%.o)
SRCS=client_udp_division.c serveur_udp_division.c udp.c udp.h erreur.c erreur.h nombre.c nombre.h

all: division
    -rm $(OBJS)

division: client_udp_division.o serveur_udp_division.o $(EXE_DIR) $(OBJS)
    mkdir -p $(EXE_DIR)/division/UDP
    $(COMPILER) erreur.o udp.o nombre.o client_udp_division.o -o $(EXE_DIR)/division/UDP/client_udp_division
    $(COMPILER) erreur.o udp.o nombre.o serveur_udp_division.o -o $(EXE_DIR)/division/UDP/serveur_udp_division
    chmod -R u+x $(EXE_DIR)/division/UDP

analyse: $(SRCS)
    cppcheck --error-exitcode=1 .

testsuite: $(SRCS) exemples/exemple_de_tests/testsuite.c
    $(COMPILER) $(OBJS) exemples/exemple_de_tests/testsuite.c -lcunit -o testsuite
    ./testsuite

udp.o: udp.c udp.h
    $(COMPILER) -c udp.c -o udp.o

erreur.o: erreur.c erreur.h
    $(COMPILER) -c erreur.c -o erreur.o

nombre.o: nombre.c nombre.h
    $(COMPILER) -c nombre.c -o nombre.o

client_udp_division.o: client_udp_division.c
    $(COMPILER) -c client_udp_division.c -o client_udp_division.o

serveur_udp_division.o: serveur_udp_division.c
    $(COMPILER) -c serveur_udp_division.c -o serveur_udp_division.o

$(EXE_DIR):
    mkdir -p $(EXE_DIR)
