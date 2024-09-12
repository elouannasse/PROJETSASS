#include <stdio.h>
#include <string.h>

typedef struct
{
    int numero_unique;
    char nom[100];
    char prenom[100];
    char date_de_naissance[50];
    char departement[50];
    float note_generale;
} Etudiants;
Etudiants etudiant[100];
int count = 0;

void ajouter();
void modifier_supprimer();
void modifier();
void supprimer();
void afficher();
void moyenne_generale();
void moyenne_generale_de_luniversit();
void moyenne_generale_departement();
void Rechercher_etudiant();
void recherche_nom();
int main()
{
    int choix;
    do
    {

        printf("----------------------------------------------------------------------- \n");
        printf("Gestion des etudiants de luniversite\n");
        printf("1 : Ajouter un etudiant \n");
        printf("2 : Modifier ou supprimer un etudiant \n");
        printf("3 : Afficher les details dun etudiant \n");
        printf("4 : Calculer la moyenne generale \n");
        printf("5 : Statistiques \n");
        printf("6 : Rechercher un etudiant\n ");
        printf("7 : Trier  etudiant\n ");
        printf("8 : Quitter\n");
        printf("Siser votre choix : ");
        scanf("%d", &choix);
        printf("/* condition */____________________________________\n");
        if (choix == 1)
        {
            ajouter();
        }
        if (choix == 2)
        {
            modifier_supprimer();
        }
        if (choix == 3)
        {
            afficher();
        }
        if (choix == 4)
        {
            moyenne_generale();
        }
        if (choix == 6)
        {
            Rechercher_etudiant();
        }
        if (choix == 8)
        {
            return 0;
        }

    } while (choix != 8);
    return 0;
}

void ajouter()
{
    printf("Siser numero unique de l'etudiant : ");
    scanf("%d", &etudiant[count].numero_unique);
    printf("Siser nom de l'etudiant : ");
    scanf("%s", etudiant[count].nom);
    printf("Siser prenom de l'etudiant : ");
    scanf("%s", etudiant[count].prenom);
    printf("Siser date de naissance de l'etudiant : ");
    scanf("%s", etudiant[count].date_de_naissance);
    int valid = 0;
    do
    {

        printf("Siser departement de l'etudiant [math ou physique ou chimie] : ");
        scanf("%s", etudiant[count].departement);

        if (strcmp(etudiant[count].departement, "math") == 0 || strcmp(etudiant[count].departement, "physique") == 0 || strcmp(etudiant[count].departement, "chimie") == 0)
        {

            valid = 1;
        }
    } while (valid != 1);
    int valid_2 = 0;
    do
    {

        printf("Siser note generale de l'etudiant : ");
        scanf("%f", &etudiant[count].note_generale);

        if (etudiant[count].note_generale >= 0 && etudiant[count].note_generale <= 20)
        {
            valid_2 = 1;
        }
    } while (valid_2 != 1);

    count++;
    printf("etudiant est ajoute\n");
}
void modifier_supprimer()
{
    int choix_2;
    do
    {

        printf("1 : pour modifier \n");
        printf("2 : pour supprimer \n");
        printf("3 : Quitter le menu modifier/supprimer \n");
        printf("Siser votre choix \n");

        scanf("%d", &choix_2);
        if (choix_2 == 1)
        {
            modifier();
        }
        if (choix_2 == 2)
        {
            supprimer();
        }
        if (choix_2 == 3)
        {
            main();
        }
    } while (choix_2 != 3);
}
void modifier()
{
    int numero_unique_siser;
    printf("Entrez le numéro unique de l'étudiant à modifier : ");
    scanf("%d", &numero_unique_siser);
    for (int i = 0; i < count; i++)
    {
        if (etudiant[i].numero_unique == numero_unique_siser)
        {
            printf("Modifiez les informations de l'etudiant\n");
            printf("Siser numero unique de l'etudiant : \n");
            scanf("%d", &etudiant[i].numero_unique);
            printf("Siser nom de l'etudiant : \n");
            scanf("%s", etudiant[i].nom);
            printf("Siser prénom de l'etudiant : \n");
            scanf("%s", etudiant[i].prenom);
            printf("Siser date de naissance de l'etudiant : \n");
            scanf("%s", etudiant[i].date_de_naissance);
            printf("Siser departement de l'etudiant [economie ou math ou physique] : \n");
            scanf("%s", etudiant[i].departement);
            printf("Siser note generale de l'etudiant : \n");
            scanf("%f", &etudiant[i].note_generale);
            printf("Informations de l'etudiant sont modifiees \n");
            return;
        }
    }
    printf("Etudiant non trouve\n");
}

void supprimer()
{
    int numero_unique_siser_2;
    printf("Entrez le numero unique de letudiant a supprimer : \n ");
    scanf("%d", &numero_unique_siser_2);
    for (int i = 0; i < count; i++)
    {
        if (etudiant[i].numero_unique == numero_unique_siser_2)
        {
            for (int j = i; j < count - 1; j++)
            {
                etudiant[j] = etudiant[j + 1];
            }
            count--;
            printf("Etudiant est supprime \n");
            return;
        }
    }
    printf("Etudiant non trouve\n");
}

void afficher()
{
    for (int i = 0; i < count; i++)
    {
        printf("----------------------------------------------------------------------- \n");
        printf("Numero unique de l'etudiant est : %d \n", etudiant[i].numero_unique);
        printf("Nom de l'etudiant est : %s \n", etudiant[i].nom);
        printf("Prenom de l'etudiant est : %s \n", etudiant[i].prenom);
        printf("Date de naissance de l'etudiant est : %s \n", etudiant[i].date_de_naissance);
        printf("Departement de l'etudiant est : %s \n", etudiant[i].departement);
        printf("Note generale de l'etudiant est : %.2f \n", etudiant[i].note_generale);
    }
}

void moyenne_generale()
{
    int choix_5;
    do
    {

        printf("1 : la moyenne generale de chaque departement \n");
        printf("2 : la moyenne generale de luniversite entiere \n");
        printf("3 : Quitter le menu moyenne generale \n");
        printf("Siser votre choix: ");

        scanf("%d", &choix_5);
        printf("____________________________________\n");
        if (choix_5 == 1)
        {
            moyenne_generale_departement();
        }
        if (choix_5 == 2)
        {
            moyenne_generale_de_luniversit();
        }
        if (choix_5 == 3)
        {
            main();
        }
    } while (choix_5 != 3);
}
void moyenne_generale_de_luniversit()
{
    float moyen = 0.00;
    float somme = 0.00;
    somme = 0;
    for (int i = 0; i < count; i++)
    {
        somme += etudiant[i].note_generale;
    }
    moyen = somme / count;
    printf("la moyen est %.2f\n", moyen);
    printf("--------------------------------------------");
}

void moyenne_generale_departement()
{
    int count_math = 0, count_physique = 0, count_chimie = 0;
    float note_generale_chimie = 0, note_generale_math = 0, note_generale_physique = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(etudiant[i].departement, "math") == 0)
        {
            count_math++;
            note_generale_math += etudiant[i].note_generale;
        }
        else if (strcmp(etudiant[i].departement, "physique") == 0)
        {
            count_physique++;
            note_generale_physique += etudiant[i].note_generale;
        }
        else if (strcmp(etudiant[i].departement, "chimie") == 0)
        {
            count_chimie++;
            note_generale_chimie += etudiant[i].note_generale;
        }
    }

    float moyenne_generale_physique = (count_physique > 0) ? (note_generale_physique / count_physique) : 0;
    float moyenne_generale_math = (count_math > 0) ? (note_generale_math / count_math) : 0;
    float moyenne_generale_chimie = (count_chimie > 0) ? (note_generale_chimie / count_chimie) : 0;

    printf("Moyenne générale de physique est : %.2f \n", moyenne_generale_physique);
    printf("Moyenne générale de math est : %.2f \n", moyenne_generale_math);
    printf("Moyenne générale de chimie est : %.2f \n", moyenne_generale_chimie);
}

void Rechercher_etudiant()
{
    int choix_7;
    do
    {
        printf("1 : Rechercher un etudiant par son nom\n");
        printf("2 : Liste departement specifique\n");
        printf("3 : Quitter le menu de recherche\n\n");
        printf("    Siser votre choix : ");

        scanf("%d", &choix_7);
        printf("____________________________________\n");
        if (choix_7 == 1)
        {
            recherche_nom();
        }
        if (choix_7 == 2)
        {
        }
        if (choix_7 == 3)
        {
            main();
        }
    } while (choix_7 != 3);
}

void recherche_nom(){
    
}
