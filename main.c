#include<stdio.h>
#define LOW 0 
#define MEDIUM 1
#define HIGH 2
// 0,1,2: poure le choix de priorite
 struct Date {
 	int jours,mois,annee ;
 };
 typedef struct {
 	char Tname[50];
 	int Priorite ;
 	char Description[200] ;
 	struct Date tdate;
 	
 }Tach;
 int nbrtach = 0;
// la founction dajoute
int ajoutertache(Tach tableau[]) {
if (nbrtach < 100  ){
	printf("entrer le nome de tache :\n");
	scanf("%s",tableau[nbrtach].Tname);
	printf("entrer la priorite du tache 0= low ,1= medium ,2= high :\n");
	scanf("%d",&tableau[nbrtach].Priorite);
	printf("entrer la Description de tache:\n");
	scanf("%s",tableau[nbrtach].Description);
	//printf("Entrez la date de la tache (jour mois annee):\n ");
	//scanf("%d %d %d",&tableau[nbrtach].tdate.jours,&tableau[nbrtach].tdate.mois,&tableau[nbrtach].tdate.annee);
//incrementation	
	nbrtach++ ;
	printf("la tache a ete ajouter ");
} 
else 
	 printf("Le tableau de taches est plein ");
}


//fouction afficher
// Fonction pour afficher les tâches
void afficher_tach(Tach tableau[] ) {
    int i;
    for (i = 0; i < nbrtach; i++) {
        printf("Tache %d :\n", i + 1);
        printf("Nom : %s\n", tableau[i].Tname);
        printf("Priorite : %d\n", tableau[i].Priorite);
        //   %[^\n]     ; pour une descrition avec espace
        printf("Description : %s\n", tableau[i].Description);
       // printf("Date : %d-%d-%d\n", tableau[i].tdate.jours, tableau[i].tdate.mois, tableau[i].tdate.annee);
        printf("\n");
    }
}

void supprimertache(Tach tableau[]) {
    int index;
    printf("Entrez le numéro de la tâche à supprimer :\n");
    scanf("%d", &index);

    if (index >= 1 && index <= nbrtach) {
        // Décaler les tâches suivantes vers la gauche pour remplir l'emplacement supprimé
        int i;
		for (i = index - 1; i < nbrtach - 1; i++) {
            tableau[i] = tableau[i + 1];
        }

        // Décrémenter le nombre de tâches après la suppression
        nbrtach--;

        printf("La tâche a été supprimée.\n");
    } else {
        printf("Numéro de tâche invalide.\n");
    }
}





int main() {
	 Tach tableau[100];
	 
	int choix;
	while(1){
	printf("l'espace de gestion des taches\n\n");
	printf("1.pour afficher la liste des taches :\n");
	printf("2.pour ajouter une nouvelle tache:\n" );
	printf("3.pour  Modifier une Tache:\n");
	printf("4.pour Supprimer une Tache :\n");
	printf("5.pour  Ordonner les Taches:\n");
	printf("6.pour Filtrer les Taches  :\n");
	printf("7.pour Quitter  :\n");
	scanf("%d", &choix);
	 switch (choix) {
            case 1:
                afficher_tach(tableau);
                break;
            case 2:
            	ajoutertache(tableau);
            	
                break;
            case 3:
                // Ajoutez le code pour modifier une tâche
                break;
            case 4:
                supprimertache(tableau);
                break;
            case 5:
                // Ajoutez le code pour ordonner les tâches
                break;
            case 6:
                // Ajoutez le code pour filtrer les tâches
                break;
            case 7:
                // Ajoutez le code pour quitter le programme
                
                return 0;
            default:
                printf("Choix invalide. Veuillez choisir un nombre entre 1 et 7.\n");
        }
}


	
	
	
	return 0;
}
