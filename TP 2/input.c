#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include <ctype.h>

int getInt(char* mensaje)
{
    int aux;
    printf("%s",mensaje);
    scanf("%d",&aux);
    return aux;
}

float getFloat(char* mensaje)
{
    float aux;
    printf("%s",mensaje);
    scanf("%f",&aux);
    return aux;

}

char getChar(char* mensaje)
{
    fflush(stdin);
    char aux;
    printf("%s",mensaje);
    scanf("%c",&aux);
    return aux;
}
int esNumero(char* cadena)
{
    int i=0;
    int j;
    int realizoValidacion=0;

    j=strlen(cadena);

    while(i<j && realizoValidacion == 0)
    {
        if(isdigit(cadena[i])!=0)
        {
            i++;
        }
        else
        {
            realizoValidacion=1;
        }
    }
    return realizoValidacion;
}


int validarNumeroConSignos(char* pBuffer)
{
    int i=0;
    int j;
    int retornoValidacion=0;
    int acumuladorSignos=0;
    int acumuladorSignosNegativos=0;

    j=strlen(pBuffer);

    while (i<j && retornoValidacion==0)
    {
        if (isdigit(pBuffer[i])!=0||pBuffer[i]=='.'||pBuffer[i]==','||pBuffer[i]=='-')
        {
            if(pBuffer[i]=='.'||pBuffer[i]==',')
            {
                acumuladorSignos++;
            }
            if (pBuffer[i]=='-')
            {
                acumuladorSignosNegativos++;
            }
            if(acumuladorSignos>1||acumuladorSignosNegativos>1)
            {
                retornoValidacion=1;
                break;
            }
            i++;
        }
        else
        {
            retornoValidacion=1;
        }
    }
    return retornoValidacion;
}

float getFloatPositivo(const char* MSJ)
{

    float valorFlotante;
    char buffer[30];

    do
    {
        printf("INGRESE %s : ", MSJ);
        fflush(stdin);
        gets(buffer);

        while(validarNumeroConSignos(buffer)==1)
        {
            printf("[ERROR] REINGRESE NUMERO: ");
            fflush(stdin);
            gets(buffer);
            system("cls");
        }

        valorFlotante=atof(buffer);

        if(valorFlotante<0)
        {
            puts("[ERROR] VALOR SOLO POSITIVO\n");
            system("pause");
            system("cls");
        }

    }
    while(valorFlotante<0);

    return valorFlotante;
}

void esLetra(char* letras)
{
    esCadena(letras);
}
int esCadena(char* cadena)
{
    int i=0;
    int j;
    int realizoValidacion=0;

    j=strlen(cadena);

    while(i<j && realizoValidacion == 0)
    {
        if(isalpha(cadena[i])!=0)
        {
            i++;
        }
        else
        {
            realizoValidacion=1;
        }
    }
    return realizoValidacion;
}

/********************** PARA ABM **********************/

int esDato(char* dato, char* texto)
{
    int esDatoExito = 0;
    do
    {
        printf("INGRESE %s : ", texto);
        fflush(stdin);
        gets(dato);
        if(esCadena(dato)==1){
            printf("RE ");
        }
    }while(esCadena(dato)==1);
    return esDatoExito;
}
int esNumerico(char* numeros, char* texto)
{
    int esNumericoExito = 0;
    do
    {
        printf("INGRESE %s : ", texto);
        fflush(stdin);
        gets(numeros);
        if(esNumero(numeros)==1){
            printf("RE ");
        }
    }while(esCadena(numeros)==1);
    return esNumericoExito;
}

int sector()
{
    int retornoSector;
    int sector;
    do
    {
        printf("INGRESE SECTOR: ");
        scanf("%d",&sector);
        if(sector > 0)
        {
            retornoSector = sector;
        }
        else
        {
            system("cls");
            printf("RE ");
        }
    }while(retornoSector < 0);

    return retornoSector;
}
