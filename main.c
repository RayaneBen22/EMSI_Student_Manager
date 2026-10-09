
#include <stdio.h>

int main(void) {
    int choix;

    do {
        printf("\n===== EMSI STUDENT MANAGER =====\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Afficher les etudiants\n");
        printf("3. Rechercher un etudiant\n");
        printf("4. Modifier un etudiant\n");
        printf("5. Supprimer un etudiant\n");
        printf("0. Quitter\n");

        printf("\nVotre choix : ");

        if (scanf("%d", &choix) != 1) {
            printf("Saisie invalide.\n");
            return 1;
        }

        switch (choix) {
            case 1:
                printf("Ajouter un etudiant\n");
                break;
            case 2:
                printf("Afficher les etudiants\n");
                break;
            case 3:
                printf("Rechercher un etudiant\n");
                break;
            case 4:
                printf("Modifier un etudiant\n");
                break;
            case 5:
                printf("Supprimer un etudiant\n");
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }

    } while (choix != 0);

    return 0;
}
