#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**************************************************** QUESTION 2: arbre de processus ****************************************************/

void ArbreBinaire(int n) {

    if (n <= 0) {
        return;
    }

    pid_t pid1, pid2;

    /*********** creation du premier enfant ***********/
    pid1 = fork();

    // Cas d'erreur de création du processus
    if (pid1 < 0) {
        fprintf(stderr, "Erreur dans la création du processus\n");
        exit(1);
    }

    // Cas où le processus est bien l'enfant
    if (pid1 == 0) {
        printf("Enfant PID: %d, Parent PID: %d\n", getpid(), getppid());
        ArbreBinaire(n - 1); // utilisation recursive de la fonction
        exit(0);
    }

    /*********** creation du deuxieme enfant ***********/
    pid2 = fork();

    // Cas d'erreur de création du processus
    if (pid2 < 0) {
        fprintf(stderr, "Erreur dans la création du processus\n");
        exit(1);
    }

    // Cas où le processus est bien l'enfant
    if (pid2 == 0) {
        printf("Enfant PID: %d, Parent PID: %d\n", getpid(), getppid());
        ArbreBinaire(n - 1); // utilisation recursive de la fonction
        exit(0);
    }
    sleep(10); // Attendre 1 seconde avant de terminer le processus enfant
    wait(NULL); //attendre processus enfant 1
    wait(NULL); //attendre processus enfant 2

}

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    ArbreBinaire(n);
}