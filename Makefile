EXEC= changebase # nom de l'exécutable

CC= g++ #compilateur
CPPFLAGS= -Wall -std=c++17 #options de compilation pour les sources C++

SRC= *.cpp # tout les fichiers cpp du répertoire
HDR= *.hpp
# nommage automatique des fichiers objets d'apres les noms des sources CPP
OBJ= $(SRC:.cpp=.o)

# crée l'exécutable 
$(EXEC) : $(OBJ)
	$(CC) -o $@ $^

# compile les fichiers source en fichier objets correspondants.
%.o : %.cpp
	$(CC) -c $(CPPFLAGS) $^

clean :
	rm -f $(EXEC) *.o

git :
	git add $(SRC) $(HDR) Makefile
	git commit -m "$m"
	git push -u origin main
