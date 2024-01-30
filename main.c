#include<stdio.h>



 struct Date {
 	int jours,mois,annee ;
 };
 typedef struct {
 	char Tname[50];
 	int Priorite ;
 	char Description[200] ;
 	struct Date tdate;
 	
 }Tach;
 //v.globale
 int nbrtach = 0;
  int index;
  
// la founction dajoute
int ajoutertache(Tach tableau[]) {
if (nbrtach < 100  ){
	printf("entrer le nome de tache :\n");
	scanf("%s",tableau[nbrtach].Tname);
	printf("entrer la priorite du tache 0= low ,1= medium ,2= high :\n");
	scanf("%d",&tableau[nbrtach].Priorite);
	printf("entrer la Description de tache:\n");
	//   %[^\n]     ; pour une descrition avec espace
	scanf(" %[^\n]s",tableau[nbrtach].Description);
	printf("Entrez la date de la tache (jour mois annee):\n ");
	scanf("%d %d %d",&tableau[nbrtach].tdate.jours,&tableau[nbrtach].tdate.mois,&tableau[nbrtach].tdate.annee);
//incrementation	
	nbrtach++ ;
	printf("la tache a ete ajouter ");
} 
else 
	 printf("Le tableau de taches est plein ");
}



// Fonction pour afficher les tâches
void afficher_tach(Tach tableau[] ) {
    int i;
    for (i = 0; i < nbrtach; i++) {
        printf("Tache %d :\n", i + 1);
        printf("Nom : %s\n", tableau[i].Tname);
        printf("Priorite : %d\n", tableau[i].Priorite);
        printf("Description : %s\n", tableau[i].Description);
       printf("Date : %d-%d-%d\n", tableau[i].tdate.jours, tableau[i].tdate.mois, tableau[i].tdate.annee);
        printf("\n");
    }
}
// founction de modifier 
void modifier_tach(Tach tableau[]){
	printf("enter le numero de tache pour modifier :\n");
	scanf("%d",&index);
	if (index >=1 &&index<= nbrtach) {
		printf("entrer le nouveau nom de tach :\n");
		scanf("%s",tableau[index-1].Tname);
		printf("entrer la  nouveau priorite du tache 0= low ,1= medium ,2= high :\n");
	    scanf("%d",&tableau[index-1].Priorite);
	    printf("Nouveau description : %s\n", tableau[index-1].Description);
	    scanf(" %[^\n]s",tableau[index-1].Description);
       printf("Nouveau date : %d-%d-%d\n", tableau[index-1].tdate.jours, tableau[index-1].tdate.mois, tableau[index-1].tdate.annee);
       
	    printf("\n");
	}
	else{
		printf("numero invalid :\n");
	}
	
}

// founction de supprimer une tach 

void supprimertache(Tach tableau[]) {
   
    printf("Entrez le numéro de la tâche à supprimer :\n");
    scanf("%d", &index);

    if (index >= 1 && index <= nbrtach) {
        // Décaler les tâches suivantes vers la gauche pour remplir l'emplacement supprimé
        int i;
		for (i = index - 1; i < nbrtach - 1; i++) {
            tableau[i] = tableau[i + 1];
        }

        // Décrémentation
        nbrtach--;

        printf("La tâche a été supprimée.\n");
    } else {
        printf("Numéro de tâche invalide.\n");
    }
}
// founction poure trier par date
void trierTaches(Tach tableau[],  int ordre) {
  int i , j;
    for ( i = 0; i < nbrtach - 1; i++) {
        for (j = 0; j < nbrtach - i - 1; j++) {
            // Comparaison des dates en fonction de l'ordre sélectionné
            int resultatComparaison;
            if (ordre == 1) {
                resultatComparaison = (tableau[j].tdate.annee > tableau[j + 1].tdate.annee) ||
                                      (tableau[j].tdate.annee == tableau[j + 1].tdate.annee &&
                                       tableau[j].tdate.mois > tableau[j + 1].tdate.mois) ||
                                      (tableau[j].tdate.annee == tableau[j + 1].tdate.annee &&
                                       tableau[j].tdate.mois == tableau[j + 1].tdate.mois &&
                                       tableau[j].tdate.jours > tableau[j + 1].tdate.jours);
            } else {
                resultatComparaison = (tableau[j].tdate.annee < tableau[j + 1].tdate.annee) ||
                                      (tableau[j].tdate.annee == tableau[j + 1].tdate.annee &&
                                       tableau[j].tdate.mois < tableau[j + 1].tdate.mois) ||
                                      (tableau[j].tdate.annee == tableau[j + 1].tdate.annee &&
                                       tableau[j].tdate.mois == tableau[j + 1].tdate.mois &&
                                       tableau[j].tdate.jours < tableau[j + 1].tdate.jours);
            }

            if (resultatComparaison) {
                // Échanger les tâches si elles ne sont pas dans le bon ordre
                Tach temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
            }
        }
    }
}
// fouction de filter par Priorite



int main() {
	 Tach tableau[100];
	 int order;
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
                modifier_tach(tableau);
                break;
            case 4:
                supprimertache(tableau);
                break;
            case 5:
                printf("1. Trier par date croissante\n");
                printf("2. Trier par date decroissante\n");
                printf("Entrez votre choix : ");
                scanf("%d", &order);
                trierTaches(tableau, order);
                printf("\n");
                printf(" > Taches triees.\n");
                printf("\n");
                break;
                
            case 6:
                // Ajoutez le code pour filtrer les tâches
                break;
            case 7:
                return 0;
            default:
                printf("Choix invalide. Veuillez choisir un nombre entre 1 et 7.\n");
        }
}


	
	
	
	return 0;
}
