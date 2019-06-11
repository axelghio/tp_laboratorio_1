#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

float sumar(float numeroX, float numeroY)
{
    float resultado;
    resultado = numeroX+numeroY;
    return resultado;
}
float restar(float numeroX, float numeroY)
{
    float resultado;
    resultado = numeroX-numeroY;
    return resultado;
}
float dividir(float numeroX, float numeroY)
{
    float resultado;
    if(numeroY == 0)
    {
        printf("\n\nNo se puede dividir por '0'\n\n");
    }
    else
    {
        resultado = numeroX/numeroY;
    }
    return resultado;
}
float multiplicar(float numeroX, float numeroY)
{
    float resultado;
    resultado = numeroX*numeroY;
    return resultado;
}
unsigned long factorial(int numero)
{
    int fact=1;
    int i;
    if(numero == 0)
    {
        printf("\n\nEl operando no puede ser '0'\n\n");
    }
    else
    {
        for(i=1; i<=numero; i++)
            fact=fact*i;
    }
    return fact;
}
int getData(int min, int max, int* dato, int intentos, char* tipoDato, char* mensaje, char* eMensaje)
{
    int aux;
    int contador;
    int ok = 0;

    printf("%s %s entre: %d y %d : ", mensaje, tipoDato, min, max);
    scanf("%d", &aux);

    while((aux<min || aux>max) && contador < intentos)
    {
        contador++;
        //fflush(stdin);

        if(contador == intentos)
        {
            break;
        }
        printf("%s %d y %d.\n\n", eMensaje, min, max);
        printf("%s %s entre: %d y %d : ", mensaje, tipoDato, min, max);
        scanf("%d", &aux);
    }
    if(contador < intentos)
    {
        *dato = aux;
        ok = 1;
    }
    return ok;
}
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

int esNumerico(char cadena[])
{
    int sePudo=0;
    int i=0;

    while(cadena[i]!='\0')
    {
        if(cadena[i]<'0' || cadena[i]>'9')
        {
            sePudo=0;
        }
        else
        {
            sePudo=1;
        }
        i++;
    }
    return sePudo;
}
int esSoloLetras(char cadena[])
{
    int sePudo=0;
    int i=0;

    while(cadena[i]!='\0')
    {
        if((cadena[i]!=' ')&&(cadena[i]<'a' || cadena[i]>'z')&&(cadena[i]<'A'||cadena[i]>'Z'))
        {
            sePudo=0;
        }
        else
        {
            sePudo=1;
        }
        i++;
    }

    return sePudo;
}
int esAlfaNumerico(char cadena[])
{
    int sePudo=0;
    int i=0;

    while(cadena[i]!='\0')
    {
        if((cadena[i]!=' ')&&(cadena[i]<'a' || cadena[i]>'z')&&(cadena[i]<'A'||cadena[i]>'Z')&&(cadena[i]<'0' || cadena[i]>'9'))
        {
            sePudo=0;
        }
        else
        {
            sePudo=1;
        }
        i++;
    }

    return sePudo;
}
int esTelefono(char cadena[])
{
    int sePudo=0;
    int i=0;
    int cantidadGuiones=0;
    while(cadena[i]!= '\0')
    {
        if((cadena[i]!=' ')&&(cadena[i]!='-')&&(cadena[i]<'0' || cadena[i]>'9'))
        {
            sePudo=0;
        }
        if(cadena[i]=='-')
        {
            cantidadGuiones++;
        }
        i++;
    }
    if(cantidadGuiones==1)
    {
        sePudo=1;
    }
    return sePudo;
}

int burbujeo(char cadena[], int largoCadena, char signo)
{
    int retorno=0;
    char aux;
    if(signo=='<')
    {
        for(int i = 0; i< largoCadena-1; i++)
        {
            for(int j = i; j< largoCadena; j++)
            {
                if(cadena[i]>cadena[j])
                {
                    aux = cadena[i];
                    cadena[i] = cadena[j];
                    cadena[j] = aux;
                    fflush(stdin);
                }
            }
        }
        retorno = 1;
    }
    else if(signo=='>')
    {
        for(int i = 0; i< largoCadena-1; i++)
        {
            for(int j = i; j< largoCadena; j++)
            {
                if(cadena[i]<cadena[j])
                {
                    aux = cadena[i];
                    cadena[i] = cadena[j];
                    cadena[j] = aux;
                    fflush(stdin);
                }
            }
        }
        retorno = 1;
    }
    return retorno;
}
int menu()
{
    int opcion = 0;
    system("cls");
    printf("BIENVENIDO AL TP NUMERO 3.\n\n");
    printf("1. CARGAR LOS DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO data.csv (MODO TEXTO).\n");
    printf("2. CARGAR LOS DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO data.csv (MODO BINARIO).\n");
    printf("3. ALTA DE EMPLEADO.\n");
    printf("4. MODIFICAR DATOS DE EMPLEADO.\n");
    printf("5. BAJA DE EMPLEADO.\n");
    printf("6. LISTAR EMPLEADO.\n");
    printf("7. ORDENAR EMPLEADOS.\n");
    printf("8. GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCGIVO data.csv (MODO TEXTO).\n");
    printf("9. GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCGIVO data.bin (MODO BINARIO).\n");
    printf("10. SALIR.\n");
    printf("INGRESE OPCION: ");
    scanf("%d", &opcion);
    return opcion;
}
