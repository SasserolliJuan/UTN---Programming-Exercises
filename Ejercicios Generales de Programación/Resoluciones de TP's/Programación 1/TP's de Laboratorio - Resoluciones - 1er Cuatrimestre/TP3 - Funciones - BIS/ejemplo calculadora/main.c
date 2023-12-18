#include <stdio.h>
#include <stdlib.h>

float suma (float,float);
float resta (float,float);
float multiplicacion (float,float);
float division (float,float);
void menu ();

int main()
{
    int c;
    float a=0,b=0,valor=0,resultado=0;
    printf("ingrese el primer valor: \n");
    scanf("%f", &a);
    printf("ingrese el segundo valor: \n");
    scanf("%f", &b);
    printf("ingrese la opcion deseada: \n");
    printf("0:suma\ 1:resta\ 2:multiplicacion\ 3:division\n");
    scanf("%i", &c);

    switch(c)
    {
    case 0:
    {
        valor=suma(a,b);
        printf("el resultado de la operacion es: %.2f \n", valor);
        system("pause");
        break;
    }
    case 1:
    {
        valor=resta(a,b);
        printf("el resultado de la operacion es: %.2f \n", valor);
        system("pause");
        break;
    }
    case 2:
    {
        valor=multiplicacion(a,b);
        printf("el resultado de la operacion es: %.2f \n", valor);
        system("pause");
        break;
    }
    case 3:
    {

        if (b=0)
        {
            printf("no es posible de hacer");
        }
        else
        {
            valor= division(a,b);
            printf("el resultado de la operacion es: %.2f \n", valor);
            system("pause");
        }
        break;
    }
    default:
    {
        printf ("opcion no valida");
        break;
    }
    }

   return 0;
}


float suma (float x,float y)
{
    float resultado=0;
    resultado= x+y;
    return resultado;
}

float resta (float x,float y)
{
    float resultado=0;
    resultado=x-y;
    return resultado;
}

float multiplicacion (float x, float y)
{
    float resultado=0;
    resultado= x*y;
    return resultado;
}

float division (float x, float y)
{
    float resultado=0;
    resultado= x/y;
    return resultado;
}
