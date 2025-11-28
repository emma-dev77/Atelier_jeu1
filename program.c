#include <stdio.h>
#include <stdlib.h>

#define JEUX 6
#define CARTES 52 * JEUX

int sabot[CARTES];
int position = 0;

void initialiserSabot() {
    int index=0;
    for (int j = 0; j < JEUX; j++) {
        for (int i = 1; i <= 13; i++) {
            for (int k = 0; k < 4; k++){ 
                sabot[index++] = i; 
            }
        }
    }

}

void melangerSabot() {
    for (int i = CARTES - 1; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = sabot [i];
        sabot [i] = sabot [j];
        sabot [j] = temp;

    }
}

int tirercarte() {
    if (position >= CARTES) {
        printf ("\nSabot vide ! On le remélange...\n");
        position = 0;
        melangerSabot()
    }
    return sabot [position++];
}

int calculerScore (int cartes [], int nb) {
    int total = 0, nbas = 0;
    for (int i = 0; i < nb; i++){
        int val = valeurCarte (cartes[i]);
        if (cartes[i] == 1) nbas++;
        total += val;
    }
    while (nbas > 0 && total + 10 <= 21) {
        total += 10; 
        nbas--;
    }
    return total;
}

void afficherRègles(){
    printf("===============================================\n");
    printf("            BIENVENUE AU BLACKJACK             \n");
    printf("===============================================\n");
    printf("REGLES DU JEU:\n");
    printf("1) Le but est d'atteindre 21 sans le dépasser.\n");
    printf("1) Les figures valent 10 points.\n");
    printf("3) L'As vaut 1 ou 11 selon la meilleure option.\n");
    printf("4) Vous pouvez tirer (T) ou rester (R).\n");
    printf("===============================================\n");
}

int main (){
    srand((unsigned)time(NULL)); 
    initialiserSabot();
    melangerSabot();

    char rejouer = '0';
    afficherRègles();

    while (rejouer == '0') {
        int joueur[10], banque [10];
        int nbJ = 0, nbB = 0;
        char choix;

        joueur [nbJ++] = tirerCarte();
        joueur [nbJ++] = tirerCarte();
        banque [nbB++] = tirerCarte();
        banque [nbB++] = tirerCarte();

        printf("---------------------------------------------\n");
        printf("Score de la banque : %d\n", valeurCarte(banque[0]));
        printf("Votre score actuel : %d\n", calculerScore(joueur, nbJ));

        while (1) {
            int scoreJ = calculerScore(joueur, nbJ);
            if (scoreJ > 21) {
                printf("Vous dépassez 21 ! Vous perdez.\n");
                goto fin_partie;
            }

            printf("Voulez-vous Tirer (T) ou Rester (R)");
            scanf("%c", &choix);

            if (choix == 'T'|| choix == 't') {
                joueur [nbJ++] = tirerCarte(); 
                printf("Votre nouveau score ; %d\n", calculerScore(joueur, nbJ));
            }
            else if (choix == 'R' || choix == 'r') { 
                break;
            }
            else {
                printf("Choix invalide.\n");
            }
        }

        
    }
}