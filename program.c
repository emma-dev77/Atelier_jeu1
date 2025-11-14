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
}

