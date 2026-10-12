
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

            case 1: {
                if (nombreEtudiants >= MAX_ETUDIANTS) {
                    printf("La liste est pleine !\n");
                    break;
                }

                struct Etudiant *e = &etudiants[nombreEtudiants];
                int dejaExistant = 0;

                printf("\n--- Ajouter un etudiant ---\n");

                printf("ID : ");
                if (scanf("%d", &e->id) != 1) {
                    printf("ID invalide.\n");
                    return 1;
                }

                for (int i = 0; i < nombreEtudiants; i++) {
                    if (etudiants[i].id == e->id) {
                        dejaExistant = 1;
                        break;
                    }
                }

                if (dejaExistant) {
                    printf("Cet ID existe deja.\n");
                    break;
                }

                printf("Nom : ");
                if (scanf("%49s", e->nom) != 1) {
                    printf("Nom invalide.\n");
                    return 1;
                }

                printf("Prenom : ");
                if (scanf("%49s", e->prenom) != 1) {
                    printf("Prenom invalide.\n");
                    return 1;
                }

                printf("Age : ");
                if (scanf("%d", &e->age) != 1 || e->age <= 0) {
                    printf("Age invalide.\n");
                    return 1;
                }

                nombreEtudiants++;

                printf("\nEtudiant ajoute avec succes !\n");
                break;
            }

            case 2: {
                printf("\n===== LISTE DES ETUDIANTS =====\n");

                if (nombreEtudiants == 0) {
                    printf("Aucun etudiant enregistre.\n");
                } else {
                    for (int i = 0; i < nombreEtudiants; i++) {
                        printf("\n--- Etudiant %d ---\n", i + 1);
                        printf("ID     : %d\n", etudiants[i].id);
                        printf("Nom    : %s\n", etudiants[i].nom);
                        printf("Prenom : %s\n", etudiants[i].prenom);
                        printf("Age    : %d\n", etudiants[i].age);
                    }

                    printf("\nTotal : %d etudiant(s)\n",
                           nombreEtudiants);
                }
                break;
            }

            case 3: {
                int idRecherche;
                int trouve = 0;

                printf("\n===== RECHERCHER UN ETUDIANT =====\n");
                printf("Entrez l'ID de l'etudiant : ");

                if (scanf("%d", &idRecherche) != 1) {
                    printf("ID invalide.\n");
                    return 1;
                }

                for (int i = 0; i < nombreEtudiants; i++) {
                    if (etudiants[i].id == idRecherche) {
                        printf("\nEtudiant trouve !\n");
                        printf("ID     : %d\n", etudiants[i].id);
                        printf("Nom    : %s\n", etudiants[i].nom);
                        printf("Prenom : %s\n", etudiants[i].prenom);
                        printf("Age    : %d\n", etudiants[i].age);

                        trouve = 1;
                        break;
                    }
                }

                if (!trouve) {
                    printf("\nAucun etudiant avec cet ID.\n");
                }
                break;
            }

            case 4: {
                int idModifier;
                int trouve = 0;

                printf("\n===== MODIFIER UN ETUDIANT =====\n");
                printf("Entrez l'ID de l'etudiant : ");

                if (scanf("%d", &idModifier) != 1) {
                    printf("ID invalide.\n");
                    return 1;
                }

                for (int i = 0; i < nombreEtudiants; i++) {
                    if (etudiants[i].id == idModifier) {
                        trouve = 1;

                        printf("\nInformations actuelles :\n");
                        printf("ID     : %d\n", etudiants[i].id);
                        printf("Nom    : %s\n", etudiants[i].nom);
                        printf("Prenom : %s\n", etudiants[i].prenom);
                        printf("Age    : %d\n", etudiants[i].age);

                        printf("\n--- Nouvelles informations ---\n");

                        printf("Nouveau nom : ");
                        if (scanf("%49s", etudiants[i].nom) != 1) {
                            printf("Nom invalide.\n");
                            return 1;
                        }

                        printf("Nouveau prenom : ");
                        if (scanf("%49s", etudiants[i].prenom) != 1) {
                            printf("Prenom invalide.\n");
                            return 1;
                        }

                        printf("Nouvel age : ");
                        if (scanf("%d", &etudiants[i].age) != 1 ||
                            etudiants[i].age <= 0) {
                            printf("Age invalide.\n");
                            return 1;
                        }

                        printf("\nEtudiant modifie avec succes !\n");
                        break;
                    }
                }

                if (!trouve) {
                    printf("\nAucun etudiant avec cet ID.\n");
                }
                break;
            }

            case 5: {
                int idSupprimer;
                int trouve = 0;

                printf("\n===== SUPPRIMER UN ETUDIANT =====\n");
                printf("Entrez l'ID de l'etudiant : ");

                if (scanf("%d", &idSupprimer) != 1) {
                    printf("ID invalide.\n");
                    return 1;
                }

                for (int i = 0; i < nombreEtudiants; i++) {
                    if (etudiants[i].id == idSupprimer) {
                        trouve = 1;

                        for (int j = i; j < nombreEtudiants - 1; j++) {
                            etudiants[j] = etudiants[j + 1];
                        }

                        nombreEtudiants--;

                        printf("\nEtudiant supprime avec succes !\n");
                        break;
                    }
                }

                if (!trouve) {
                    printf("\nAucun etudiant avec cet ID.\n");
                }
                break;
            }

            case 0:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide.\n");
                break;
        }

    } while (choix != 0);

    return 0;
}
