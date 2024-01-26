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
// la founction dajoute
int ajoutertache(Tach tableau[],int nbrtach) {
if (nbrtach < 100  ){
	printf("entrer le nome de tache");
	scanf("%s",tableau[nbrtach].Tname);
	printf("entrer la priorite du tache");
	scanf("%d",&tableau[nbrtach].Priorite);
	printf("entrer la Description de tache");
	scanf("%s",tableau[nbrtach].Description);
	printf("Entrez la date de la tache (jour mois annee): ");
	scanf("%d %d %d",&tableau[nbrtach].tdate.jours,&tableau[nbrtach].tdate.mois,&tableau[nbrtach].tdate.annee);
//incrementation	
	nbrtach++ ;
	printf("la tache a ete ajouter ");
} 
else 
	 printf("Le tableau de taches est plein ");
}






int main() {
	 Tach tableau[100];
	 int nbr;
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
                // Ajoutez le code pour afficher la liste des tâches
                break;
            case 2:
            	ajoutertache(tableau,nbr);
                break;
            case 3:
                // Ajoutez le code pour modifier une tâche
                break;
            case 4:
                // Ajoutez le code pour supprimer une tâche
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
