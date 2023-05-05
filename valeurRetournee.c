#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**************************************************** QUESTION 4: valeur retournee ****************************************************/

int main(){

    int n;
    pid_t pidEnfant = fork(); // creation d'un processus enfant et on stocke son PID  dans pidEnfant
    int status;

    // Cas d'erreur de création du processus
    if (pidEnfant < 0) {
        fprintf(stderr, "Erreur\n");
        exit(1); // On quitte le processus parent avec un code d'erreur
    }

    if (pidEnfant == 0) {
        printf("Entrez la valeur à retourner: ");
        scanf("%d", &n);
        exit(n); // On quitte le processus enfant avec la valeur donnée en argument
    }

    wait(&status); // On attend la fin de l'exécution du processus enfant et on stocke la valeur de sortie dans la variable status
    printf("valeur: %d", WEXITSTATUS(status)); // On affiche la valeur de sortie du processus enfant avec WEXITSTATUS
    return 0;
}
