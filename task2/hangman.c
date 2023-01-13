#include <stdio.h>  
#include <stdlib.h> 
#include <time.h>   
#include <string.h> 

//funkcija za risanje vislice
void obesenjak(char CTelo[])
{
    printf(" |------\n"
           " |     |\n"
           " |    %c %c\n"
           " |    %c%c%c\n"
           " |    %c %c\n"
           "===\n",
           CTelo[0], CTelo[1], CTelo[2], CTelo[3], CTelo[4], CTelo[5], CTelo[6]);
    
}

void natisni_prazno_besedo(char sTempArr[])
{
    for (int j = 0; j < strlen(sTempArr); j++)
        printf("%c ", sTempArr[j]);
    printf("\n");
}

int cekovno_pismo(char sNakljucnaBeseda[], char cNovoPismo, char sTempArr[])
{
    int dCount = 0, dFlag = 0;
    for (int i = 0; i < strlen(sNakljucnaBeseda); i++)
    {
        
        if (sNakljucnaBeseda[i] == cNovoPismo)
        {
            sTempArr[i] = cNovoPismo;
            dCount++;
        } 
    }     

    if (dCount != 0)
        dFlag = 1;
    return dFlag;
}


void deli_telesa(int dObesenjak, char cTelo[])
{
    
    if (dObesenjak == 1)
    {
        cTelo[0] = '(';
        cTelo[1] = ')';
    }
    else if (dObesenjak == 2)
        cTelo[2] = '/';
    else if (dObesenjak == 3)
        cTelo[3] = '|';
    else if (dObesenjak == 4)
        cTelo[4] = '\\';
    else if (dObesenjak == 5)
        cTelo[5] = '/';
    else if (dObesenjak == 6)
        cTelo[6] = '\\';
}



int main()
{
    

    
    srand(time(0));           
    int dNakljucen = rand() % 7; 

    
    char *sBesedi[] = {"hisa", "stol", "praktikum", "Koper", "drevo", "zoga", "more"};

    
    char *sNakljucnaBeseda = sBesedi[dNakljucen];

    char *sTempArr = malloc(strlen(sNakljucnaBeseda) + 1); 
    for (int i = 0; sNakljucnaBeseda[i] != '\0'; i++)      
        sTempArr[i] = '_';

    char cNovoPismo;  
    int dObesenjak = 0; 

    char cTelo[7];              
    for (int i = 0; i < 7; i++) 
        cTelo[i] = ' ';

    


    while (dObesenjak <= 6)
    {
        
        obesenjak(cTelo);

        
        natisni_prazno_besedo(sTempArr);

        
        printf("\nVpisi pismo: ");
        scanf(" %c", &cNovoPismo);

        
        if (cekovno_pismo(sNakljucnaBeseda, cNovoPismo, sTempArr) != 1) 
        {
            dObesenjak++;                  
            deli_telesa(dObesenjak, cTelo); 
            
        }

        int dCounter = 0; 
        for (int s = 0; s < strlen(sNakljucnaBeseda); s++)
            if (sTempArr[s] == '_') 
                dCounter++;
        if (dCounter == 0 || dObesenjak == 6) 
            break;
    }

    
    printf("\nKonec igre!\n");
    if (dObesenjak == 6)
        printf("Izgubil si :(\n");
    else
        printf("Zmagal si :)\n");
    
    obesenjak(cTelo);
    printf("Pravilna beseda je bila: ");
    natisni_prazno_besedo(sNakljucnaBeseda);

    return 0;
}