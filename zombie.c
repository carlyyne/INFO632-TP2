#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**************************************************** QUESTION 3: zombie ****************************************************/

int main() {

    pid_t pidEnfant = fork();

    // Cas d'erreur de création du processus
    if (pidEnfant < 0) {
        fprintf(stderr, "Erreur\n");
        exit(1);
    }

    if (pidEnfant == 0) {
        printf("Enfant PID: %d, Parent PID: %d\n", getpid(), getppid());
        exit(0);

    } else {
        sleep(10);
        wait(NULL);
    }
    return 0;
}