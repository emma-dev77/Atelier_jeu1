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
        
    }
}



