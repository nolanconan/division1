COMPILER=gcc
EXE_DIR=/tmp/
FICHIERS=erreur udp nombre
OBJS:=$(FICHIERS:%=%.o)
SRCS=client_udp_division.c serveur_udp_division.c udp.c udp.h erreur.c erreur.h nombre.c nombre.h

all: division 
	-rm $(OBJS)

division: client_udp_division.c serveur_udp_division.c $(EXE_DIR) $(OBJS)
	mkdir -p $(EXE_DIR)/$@/UDP
	$(COMPILER) erreur.o udp.o nombre.o client_udp_$@.c -o $(EXE_DIR)/$@/UDP/client_udp_$@
	$(COMPILER) erreur.o udp.o nombre.o serveur_udp_$@.c -o $(EXE_DIR)/$@/UDP/serveur_udp_$@
	chmod -R u+x $(EXE_DIR)/$@/UDP

analyse: $(SRCS)
	cppcheck --error-exitcode=1 .
    
testsuite: build division1/exemples/exemple_de_tests/testsuite.c 
	$(COMPILER) $(OBJS) division1/exemples/exemple_de_tests/testsuite.c -lcunit -o $@
	./$@

build:
	@echo "Build target is a placeholder."

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
