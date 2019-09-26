/*

ES_001_csv
Author: Cuniberti Andrea
Class: 4AROB
project start:16-09-2019
project end:


Creare un programma in linguaggio C che legga il file vgsales.csv e lo importi in un array di strutture.
Ogni riga contiene i campi separati da virgole, per cui pu� essere comodo creare una funzione split
che dalla riga letta ritorni la struttura valorizzata.

*/

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define L_NOME 100
#define NUMERO_RIGHE 16600

typedef struct colonne{

    char *Publisher;
    char *Name;
    char *Genre;
    char *Platform;
    float NA_Sales,EU_Sales,JP_Sales,Other_Sales,Global_Sales;
    int Rank, Year;

}Colonne;

int main(){

    Colonne tab[NUMERO_RIGHE];
    caricaTab(tab);

}

void caricaTab(Colonne tab[]){
    FILE *fp;
    char *buffer;
    char *field;
    int k=0;


    fp = fopen("vgsales.csv", "r");
    if (fp==NULL){
        printf("\n Non e' stato trovato alcun file");
    }else{

        fgets(buffer,1,fp);
        filed=strtok(buffer, ",");
        tab[k].Rank=atoi(field);
        field=strtok(NULL, ",");
        tab[k].Name=field;
        field=strtok(NULL, ",");
        tab[k].Platform=field;
        field=strtok(NULL, ",");
        tab[k].Year=field;
        field=strtok(NULL, ",");
        tab[k].Publisher=field;
        field=strtok(NULL, ",");
        tab[k].NA_Sales=field;
        field=strtok(NULL, ",");
        tab[k].EU_Sales=field;
        field=strtok(NULL, ",");
        tab[k].JP_Sales=field;
        field=strtok(NULL, ",");
        tab[k].Other_Sales=field;
        field=strtok(NULL, ",");
        tab[k].Global_Sales=field;

            while(fgets(buffer, NUMERO_RIGHE, fp)){
                filed=strtok(buffer, ",");
                tab[k].Rank=atoi(field);
                field=strtok(NULL, ",");
                tab[k].Name=field;
                field=strtok(NULL, ",");
                tab[k].Platform=field;
                field=strtok(NULL, ",");
                tab[k].Year=atoi(field);
                field=strtok(NULL, ",");
                tab[k].Publisher=field;
                field=strtok(NULL, ",");
                tab[k].NA_Sales=atof(field);
                field=strtok(NULL, ",");
                tab[k].EU_Sales=atof(field);
                field=strtok(NULL, ",");
                tab[k].JP_Sales=atof(field);
                field=strtok(NULL, ",");
                tab[k].Other_Sales=atof(field);
                field=strtok(NULL, ",");
                tab[k].Global_Sales=atof(field);
            }  
        }
    fclose(fp);
    return;
}