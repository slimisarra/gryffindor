jeu:main.o background.o collision.o jeu.o perso.o
	gcc main.o background.o collision.o jeu.o perso.o -o jeu -lSDL -lSDL_image -g
main.o:main.c
	gcc -c main.c -g
background.o:background.c
	gcc -c background.c -g
collision.o:collision.c
	gcc -c collision.c -g
jeu.o:jeu.c
	gcc -c jeu.c -g
perso.o:perso.c
	gcc -c perso.c -lSDL_image -g

