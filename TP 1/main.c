#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "AxelUTN.h"

int main()
{
    fflush(stdin);
    float numeroA=0, numeroB=0, resSuma,resResta,resDivision,resMultiplicacion;
    int flag1=0,flag2=0;
    unsigned long factorialA,factorialB;
    char continuar = 's';
    char opcion;
    while(continuar == 's')
    {
        system(("cls"));
        printf("Bienvenido a tu Calculadora.\n");
        printf("Axel Ghio UTN.\n");
        printf("\n1. Ingresaste como el operando A el numero: %.2f\n",numeroA);
        printf("\n2. Ingresaste como el operando B el numero: %.2f\n",numeroB);
        printf("\n3. Calcular todas las operaciones.\n");
        printf("\n4. Mostrar todas las operaciones.\n");
        printf(" a) Calcular la suma\n");
        printf(" b) Calcular la resta\n");
        printf(" c) Calcular la division\n");
        printf(" d) Calcular la multiplicacion\n");
        printf(" e) Calcular el factorial\n\n");
        printf("5. Salir\n\n");
        printf("Ingrese el numero de la operacion que desea realizar.\n\n");
        fflush(stdin);
        scanf("%c",&opcion);
        opcion = tolower(opcion);
        switch(opcion)
        {
            case '1':
                system(("cls"));
                printf("1. Ingrese 1er operando: ");
                fflush(stdin);
                scanf("%f",&numeroA);
                if(numeroA == 0)
                {
                    printf("Cuidado se ingreso un CERO.\n");
                    system("pause");
                }
                flag1=1;
                break;
            case '2':
                system(("cls"));
                printf("2. Ingrese 2do operando: ");
                fflush(stdin);
                scanf("%f",&numeroB);
                if(numeroB == 0)
                {
                    printf("Cuidado se ingreso un CERO.\n");
                    system("pause");
                }
                flag2=1;
                break;
            case '3':
                if(flag1==0 || flag2 == 0)
                {
                    system(("cls"));
                    printf("Error, falta ingresar operando.\n");
                    system(("pause"));
                }
                if(flag1==1 && flag2==1)
                {
                    system(("cls"));
                    resSuma=sumar(numeroA,numeroB);
                    resResta=restar(numeroA,numeroB);
                    resDivision=dividir(numeroA,numeroB);
                    resMultiplicacion=multiplicar(numeroA,numeroB);
                    factorialA=factorial(numeroA);
                    factorialB=factorial(numeroB);
                    printf("Se han realizado las operaciones.\n");
                    system("pause");
                }
                break;
            case '4':
                if(flag1 == 1 && flag2 == 1)
                {
                    system("cls");
                    printf("El resultado de la suma es: %.2f\n",resSuma);
                    printf("\nEl resultado de la resta es: %.2f\n",resResta);
                    if(numeroB != 0)
                    {
                        printf("\nEl resultado de la division es: %.2f\n",resDivision);
                    }
                    else
                    {
                        printf("\nEl Operando B no puede ser '0' en una division.\n");
                    }
                    printf("\nEl resultado de la multiplicacion es: %.2f\n",resMultiplicacion);
                    if(numeroA == 0 && numeroB == 0)
                    {
                        printf("\nNo se puede sacar el factorial de los numeroA  y numeroB siendo su valor '%.f' y '%.f'\n", numeroA, numeroB);
                    }
                    else if(numeroA==0)
                    {
                        printf("\nNo se puede sacar el factorial del numeroA siendo su valor '%.f'\n", numeroA);
                        printf("\nEl factorial numero B de '%.2f' es: '%ld'\n",numeroB,factorialB);
                    }
                    else if(numeroB==0)
                    {
                        printf("\nNo se puede sacar el factorial numeroB siendo su valor '%.f'\n", numeroB);
                        printf("\nEl factorial numero A de '%.2f' es: '%ld'\n",numeroA,factorialA);
                    }
                    else
                    {
                        printf("\nEl factorial numero A de '%.2f' es: '%ld'\n\n",numeroA,factorialA);
                        printf("\nEl factorial numero B de '%.2f' es: '%ld'\n\n",numeroB,factorialB);
                    }
                    numeroA = 0;
                    numeroB = 0;
                    flag1=0;
                    flag2=0;
                    system("pause");
                }
                break;
            case '5':
                printf("\n\nSalir\n\n");
                continuar='n';
                break;
            default:
                system(("cls"));
                printf("\nHas escrito una opcion no valida.\n\n");
                system(("pause"));
        }
    }
        return 0;
}
