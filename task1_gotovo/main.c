//simulator dvigala
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funkcijo za preverjanje, ali je vneseno nadstropje najdeno na seznamu
int preveri_tla(char sArr[][3], char sInput[]) {
    int dFlag = 1;
    for (int i = 0; i < 9; i++) { 
        if (strcmp(sInput, sArr[i]) == 0) { 
            dFlag = 0; 
            break;
        }
    }
    return dFlag;
}

// vrni indeks nadstropja
int return_index(char sArr[][3], char sPreveriTla[]) {
    int dIndex = 0;
    for (int i = 0; i < 9; i++)
        if (strcmp(sPreveriTla, sArr[i]) == 0) {
            dIndex = i;
            break;
        }
    return dIndex;
}

int main() {
   

    char sTrenutnoTlo[2] = "G"; 
    char sNaslednjeNastropje[2];          

    
    char sTla[9][3] = {"B3\0","B2\0","B1\0","G\0","1\0","2\0","3\0","4\0","5\0"};
    int dTrenutnoSteviloLjudi = 1; 
    int dLjudiKojiSoIsli;         
    char cOdgovor;                
    int dMaxSteviloLjudi = 0;     
    

    int flag = 1; 
    while (flag) {
        
        printf("Trenutno ste v nadstropju %s. V katero nadstropje želite iti?: ", sTrenutnoTlo);
        scanf(" %s", sNaslednjeNastropje);
        
        if (preveri_tla(sTla, sNaslednjeNastropje) == 1) {
            printf("Napačen vnos, poskusite znova. ");
            continue; 
        }             

        
        cOdgovor = 'y';
        while (cOdgovor == 'y') { 
            printf("Ali želi več ljudi vstopiti v dvigalo? (y/n): ");
            scanf(" %c", &cOdgovor);
            if (cOdgovor == 'y') {
                dTrenutnoSteviloLjudi++;
                dMaxSteviloLjudi++;
                if (dMaxSteviloLjudi == 9) { 
                    printf("Dvigalo je polno!\n");
                    break;
                }
            } 
        }    

        
        if (return_index(sTla, sNaslednjeNastropje) > return_index(sTla, sTrenutnoTlo)) {
            for (int i = return_index(sTla, sTrenutnoTlo) + 1; i <= return_index(sTla, sNaslednjeNastropje); i++)
                printf("\tIti gor. Dosegli smo nadstropje %s.\n", sTla[i]);
        } 
        else {
            for (int i = return_index(sTla, sTrenutnoTlo); i >= return_index(sTla, sNaslednjeNastropje); i--)
                printf("\tGrem dol. Dosegli smo nadstropje %s.\n", sTla[i]);
        } 

        
        strcpy(sTrenutnoTlo, sNaslednjeNastropje);

        
        dLjudiKojiSoIsli = -1; 
        while (dLjudiKojiSoIsli < 0 || dLjudiKojiSoIsli > dTrenutnoSteviloLjudi) {
            printf(" V nadstropje %s je prispelo %d ljudi. Koliko ljudi želi izstopiti? (0-%d): ", sTrenutnoTlo, dTrenutnoSteviloLjudi, dTrenutnoSteviloLjudi);
            scanf("%d", &dLjudiKojiSoIsli);
        }
        if (dLjudiKojiSoIsli >= dTrenutnoSteviloLjudi) {
            printf(" V dvigalu ni več ljudi. Adijo :)\n");
            flag = 0;
        } 
        else {
            dTrenutnoSteviloLjudi -= dLjudiKojiSoIsli; 
            dMaxSteviloLjudi += dLjudiKojiSoIsli;     
            printf(" V dvigalu je še %d ljudi.\n", dTrenutnoSteviloLjudi);
        } 

    } 
    return 0;
} 