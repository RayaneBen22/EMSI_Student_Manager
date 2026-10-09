
#include <stdio.h>
#define MAX_ETUDIANTS 100

struct Etudiant {
    int id;
    char nom[50];
    char prenom[50];
    int age;
};

int main(void) {
    int choix;
    struct Etudiant etudiants[MAX_ETUDIANTS];
    int nombreEtudiants = 0;

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
    if (nombreEtudiants >= MAX_ETUDIANTS) {
        printf("La liste est pleine !\n");
        break;
    }

    struct Etudiant *e = &etudiants[nombreEtudiants];

    printf("\n--- Ajouter un etudiant ---\n");

    printf("ID : ");
    if (scanf("%d", &e->id) != 1) {
        printf("ID invalide.\n");
        return 1;
    }

    printf("Nom : ");
    scanf("%49s", e->nom);

    printf("Prenom : ");
    scanf("%49s", e->prenom);

    printf("Age : ");
    if (scanf("%d", &e->age) != 1) {
        printf("Age invalide.\n");
        return 1;
    }

    nombreEtudiants++;

    printf("\nEtudiant ajoute avec succes !\n");
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
