
#include <stdio.h>
#include <string.h>

#define MAX_ETUDIANTS 100

typedef struct {
    int jour;
    int mois;
    int annee;
} DateNaissance;

typedef struct {
    int numero;
    char nom[50];
    char prenom[50];
    DateNaissance dateNaissance;
    char departement[50];
    float noteGenerale;
} Etudiant;

Etudiant etudiants[MAX_ETUDIANTS];
int nombreEtudiants = 0;


void ajouterEtudiant() {
    int choix;
    if (nombreEtudiants < MAX_ETUDIANTS) {
        Etudiant e;
        e.numero = nombreEtudiants+1;
        printf("Numero unique: %d\n",e.numero);
        printf("Nom: ");
        scanf("%s", e.nom);
        printf("Prenom: ");
        scanf("%s", e.prenom);
        printf("Date de naissance (jj mm aaaa): ");
        scanf("%d %d %d", &e.dateNaissance.jour, &e.dateNaissance.mois, &e.dateNaissance.annee);
        printf("Departement: ");
        printf("1. pour pc ");
        printf("2. pour svt ");
        printf("entrez votre choix: ");
        scanf("%d", &choix);
        switch(choix){
        case 1:
            strcpy(e.departement, "pc");
            break;
        case 2:
            strcpy(e.departement, "svt");
            break;
        }


        printf("Note generale: ");
        scanf("%f", &e.noteGenerale);

        etudiants[nombreEtudiants] = e;
        nombreEtudiants++;
    } else {
        printf("Capacite maximale atteinte \n");
    }
}


void modifierEtudiant() {
    int numero;
    printf("Entrez le numero de l'etudiant a modifier: ");
    scanf("%d", &numero);

    for (int i = 0; i < nombreEtudiants; i++) {
        if (etudiants[i].numero == numero) {
            printf("Modifier le nom (actuel: %s): ", etudiants[i].nom);
            scanf("%s", etudiants[i].nom);
            printf("Modifier le prénom (actuel: %s): ", etudiants[i].prenom);
            scanf("%s", etudiants[i].prenom);
            printf("Modifier la date de naissance (actuel: %d/%d/%d): ",
                etudiants[i].dateNaissance.jour, etudiants[i].dateNaissance.mois, etudiants[i].dateNaissance.annee);
            scanf("%d %d %d", &etudiants[i].dateNaissance.jour, &etudiants[i].dateNaissance.mois, &etudiants[i].dateNaissance.annee);
            printf("Modifier le departement (actuel: %s): ", etudiants[i].departement);
            scanf("%s",etudiants[i].departement);
            printf("Modifier la note generale (actuelle: %.2f): ", etudiants[i].noteGenerale);
            scanf("%f", &etudiants[i].noteGenerale);
            printf("etudiant modifié avec succès!\n");
            return;
        }
    }
    printf("etudiant non trouve!\n");
}


void supprimerEtudiant() {
    int numero;

    printf("Entrez le numéro de l'etudiant à supprimer: ");
    scanf("%d", &numero);

    for (int i = 0; i < nombreEtudiants; i++) {
        if (etudiants[i].numero == numero) {
            for (int j = i; j < nombreEtudiants - 1; j++) {
                etudiants[j] = etudiants[j + 1];
            }
            nombreEtudiants--;
            printf("Etudiant a supprime avec succees! \n");
            return;
        }
    }
    printf("Etudiant non trouve!\n");
}


void afficherDetailsEtudiant() {


        if(nombreEtudiants==0){
            printf("Etudiant non trouvé!\n");
        }
    for (int i = 0; i < nombreEtudiants; i++) {
            printf("Numero: %d\n", etudiants[i].numero);
            printf("Nom: %s\n", etudiants[i].nom);
            printf("Prenom: %s\n", etudiants[i].prenom);
            printf("Date de naissance: %d/%d/%d\n", etudiants[i].dateNaissance.jour, etudiants[i].dateNaissance.mois, etudiants[i].dateNaissance.annee);
            printf("Departement: %s\n", etudiants[i].departement);
            printf("Note generale: %.2f\n", etudiants[i].noteGenerale);

    }

}


void calculerMoyenneGenerale() {

    float sommeGenerale = 0;
    for (int i = 0; i < nombreEtudiants; i++) {
        sommeGenerale += etudiants[i].noteGenerale;
    }
    if (nombreEtudiants > 0) {
        printf("Moyenne generale de l'universite: %.2f\n", sommeGenerale / nombreEtudiants);
    } else {
        printf("Aucun etudiant inscrit!\n");
    }


    char departements[MAX_ETUDIANTS][50];
    float sommeDepartements[MAX_ETUDIANTS] = {0};
    int nombreEtudiantsDepartement[MAX_ETUDIANTS] = {0};
    int nombreDepts = 0;


    for (int i = 0; i < nombreEtudiants; i++) {
        int found = 0;
        for (int j = 0; j < nombreDepts; j++) {
            if (strcmp(etudiants[i].departement, departements[j]) == 0) {
                sommeDepartements[j] += etudiants[i].noteGenerale;
                nombreEtudiantsDepartement[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(departements[nombreDepts], etudiants[i].departement);
            sommeDepartements[nombreDepts] += etudiants[i].noteGenerale;
            nombreEtudiantsDepartement[nombreDepts]++;
            nombreDepts++;
        }
    }


    for (int i = 0; i < nombreDepts; i++) {
        if (nombreEtudiantsDepartement[i] > 0) {
            float moyenne = sommeDepartements[i] / nombreEtudiantsDepartement[i];
            printf("Moyenne generale du departement %s: %.2f\n", departements[i], moyenne);
        } else {
            printf("Pas d'etudiants dans le departement %s\n", departements[i]);
        }
    }
}


void afficherStatistiques() {
    printf("Nombre total d'etudiants inscrits: %d\n", nombreEtudiants);


    char departements[MAX_ETUDIANTS][50];
    int nombreDepartements[MAX_ETUDIANTS] = {0};
    int nombreDepts = 0;

    for (int i = 0; i < nombreEtudiants; i++) {
        int found = 0;
        for (int j = 0; j < nombreDepts; j++) {
            if (strcmp(etudiants[i].departement, departements[j]) == 0) {
                nombreDepartements[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(departements[nombreDepts], etudiants[i].departement);
            nombreDepartements[nombreDepts]++;
            nombreDepts++;
        }
    }

    for (int i = 0; i < nombreDepts; i++) {
        printf("Nombre d'etudiants dans le departement %s: %d\n", departements[i], nombreDepartements[i]);
    }


    float seuil;
    printf("Entrez le seuil de moyenne: ");
    scanf("%f", &seuil);

    printf("etudiants ayant une moyenne superieure à %.2f:\n", seuil);
    for (int i = 0; i < nombreEtudiants; i++) {
        if (etudiants[i].noteGenerale > seuil) {
            printf("%s %s avec une moyenne de %.2f\n", etudiants[i].nom, etudiants[i].prenom, etudiants[i].noteGenerale);
        }
    }


    printf("Les 3 meilleurs étudiants:\n");
    Etudiant topEtudiants[3];
    int count = 0;

    for (int i = 0; i < nombreEtudiants; i++) {
        if (count < 3) {
            topEtudiants[count++] = etudiants[i];
        } else {
            for (int j = 0; j < 3; j++) {
                if (etudiants[i].noteGenerale > topEtudiants[j].noteGenerale) {
                    topEtudiants[j] = etudiants[i];
                    break;
                }
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%s %s avec une moyenne de %.2f\n", topEtudiants[i].nom, topEtudiants[i].prenom, topEtudiants[i].noteGenerale);
    }
}
void rechercherEtudiant() {
    int choix;
    printf("Rechercher par: \n1. Numéro\n2. Nom\nEntrez votre choix: ");
    scanf("%d", &choix);

    if (choix == 1) {
        int numero;
        printf("Entrez le numero de l'etudiant: ");
        scanf("%d", &numero);

        for (int i = 0; i < nombreEtudiants; i++) {
            if (etudiants[i].numero == numero) {
                printf("Etudiant trouve!\n");
                afficherDetailsEtudiant(etudiants[i]);
                return;
            }
        }
    } else if (choix == 2) {
        char nom[50];
        printf("Entrez le nom de l'etudiant: ");
        scanf("%s", nom);

        for (int i = 0; i < nombreEtudiants; i++) {
            if (strcmp(etudiants[i].nom, nom) == 0) {
                printf("Etudiant trouvé!\n");
                afficherDetailsEtudiant(etudiants[i]);
                return;
            }
        }
    }

    printf("Etudiant non trouvé!\n");
}




















void trierEtudiantsParNom() {

    for (int i = 0; i < nombreEtudiants - 1; i++) {
        for (int j = 0; j < nombreEtudiants-i-1; j++) {
            if (strcmp(etudiants[j].nom, etudiants[j+1].nom) > 0) {
                Etudiant temp = etudiants[j];
                etudiants[j] = etudiants[j+1];
                etudiants[j+1] = temp;
            }
        }
    }
    printf("Etudiant tries par nom!\n");
}

void trierEtudiantsParMoyenne()
{
    for(int i = 0 ; i < nombreEtudiants-1 ; i++)
    {
        for(int j = 0 ; j < nombreEtudiants-i-1 ; j++)
        {
            if(etudiants[j].noteGenerale > etudiants[j+1].noteGenerale)
            {
                Etudiant temmp = etudiants[j];
                etudiants[j] = etudiants[j+1];
                etudiants[j+1] = temmp;
            }
        }
    }
        printf("Etudiant tries par Moyenne!\n");


}

int main() {
    int choix;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Ajouter un Etudiant\n");
        printf("2. Modifier un Etudiant\n");
        printf("3. Supprimer un Etudiant\n");
        printf("4. Afficher les details d'un Etudiant\n");
        printf("5. Calculer la moyenne generale de l'universite et par departement\n");
        printf("6. Afficher les statistiques\n");
        printf("7.Recherche un etudiant par un nom \n") ;
        printf("8. Trier les Etudiants par nom\n");
        printf("9.Trier les Etudiant par moyenne genaral \n") ;
        printf("10. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterEtudiant();
                break;
            case 2:
                modifierEtudiant();
                break;
            case 3:
                supprimerEtudiant();
                break;
            case 4:
                afficherDetailsEtudiant();
                break;
            case 5:
                calculerMoyenneGenerale();
                break;
            case 6:
                afficherStatistiques();
                break;
            case 7 :
                 rechercherEtudiant() ;
                 break ;

            case 8:
                trierEtudiantsParNom();
                break;
            case 9 :
                trierEtudiantsParMoyenne();
                break;

            case 10:
                return 0;
            default:
                printf("Choix invalide!\n");
        }
    }

    return 0;
}

