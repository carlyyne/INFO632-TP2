#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

/**************************************************** QUESTION 1: Chaine de processus ****************************************************/

int main(int argc, char *argv[]) {
    /*
     * la fonction prend en argument un entier n représentant le nombre de processus à créer
     */

    int n = atoi(argv[1]);

    if (n < 0) {
        return 0;
    }

    pid_t pid = getpid();
    printf("Processus parent PID: %d\n", pid);

    for (int i = 0; i < n; i++) {
        pid = fork();

        // Cas d'erreur de création du processus
        if (pid < 0) {
            fprintf(stderr, "Erreur\n");
        }

        // Cas où le processus est l'enfant
        if (pid == 0) {
            printf("Enfant PID: %d, Parent PID: %d\n", getpid(), getppid());
        }

        // Cas où le processus est le parent
        else {
            sleep(10); // Attendre 10 seconde avant de terminer le processus enfant (pour avoir le temps d'écrire pstree)
            wait(NULL); // Bloque le processus parent en attendant que le fils soit bien créé
            exit(0); // Terminer le processus parent
        }
    }
}

