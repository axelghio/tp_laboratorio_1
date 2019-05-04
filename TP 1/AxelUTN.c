#include <stdio.h>
#include <stdint.h>
//mis funciones.
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
    float aux;
    float resultado;
    if(numeroY != 0)
    {
        aux=numeroX/numeroY;
        resultado = aux;
    }
    return resultado;
}
float multiplicar(float numeroX, float numeroY)
{
    float resultado;
    resultado = numeroX*numeroY;
    return resultado;
}
unsigned long factorial( int numero)
{
    int fact=1;
    int i;
    if(numero == 0)
    {
        //printf("\n\nEl operando no puede ser '0'\n\n");
    }
    else
    {
        for(i=1;i<=numero;i++)
        fact=fact*i;
    }
    return fact;
}
