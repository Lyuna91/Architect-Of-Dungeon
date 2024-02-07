opt = -c -Wall -Wextra -std=c99

all: architect_of_dongeon clean

architect_of_dongeon: main.o constructeur.o donjon.o salle.o couloir.o message.o
	gcc -o architect_of_dongeon main.o constructeur.o donjon.o salle.o couloir.o message.o

main.o: main.c
	gcc ${opt} main.c


constructeur.o: constructeur.c
	gcc ${opt} constructeur.c

donjon.o: donjon.c
	gcc ${opt} donjon.c

salle.o: salle.c
	gcc ${opt} salle.c

couloir.o: couloir.c
	gcc ${opt} couloir.c

message.o: message.c
	gcc ${opt} message.c

clean:
	del *.o