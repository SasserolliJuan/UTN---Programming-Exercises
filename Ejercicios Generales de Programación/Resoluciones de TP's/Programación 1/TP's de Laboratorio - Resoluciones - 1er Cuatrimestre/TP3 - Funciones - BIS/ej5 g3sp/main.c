#include <stdio.h>
#include <stdlib.h>

float suma (float,float);
float resta (float,float);
float multip (float,float);
float divide (float,float);

int main()
{
    float a=0, b=0, valor=0;
    int caso=0;
    printf("Ingrese valor de A:\n");
    scanf("%f", &a);
    printf("Ingrese valor de B:\n");
    scanf("%f", &b);
    printf("Ingrese operacion a realizar 0=suma, 1=resta, 2=multiplicacion, 3=division: \n");
    scanf("%i", &caso);
    switch(caso)
            {
            case 0:
                valor=suma(a,b);
                printf("El valor de la operacion realizada da: %.2f \n", valor);
                system("pause");
                break;
            case 1:
                valor=resta(a,b);
                printf("El valor de la operacion realizada da: %.2f \n", valor);
                system("pause");
                break;
            case 2:
                valor=multip(a,b);
                printf("El valor de la operacion realizada da: %.2f \n", valor);
                system("pause");
                break;
            case 3:
                if (b!=0)
                {
                    valor=divide(a,b);
                    printf("El valor de la operacion realizada da: %.2f \n", valor);
                    system("pause");
                } else
                {
                    printf("n/a \n");
                }
                break;
            default:
                printf("opcion invalida \n");
            }
    return 0;
}

float suma(float x, float y)
{
    float resultado=0;
    resultado= x+y;
    return resultado;
}
float resta(float x, float y)
{
    float resultado=0;
    resultado= x-y;
    return resultado;
}
float multip(float x, float y)
{
    float resultado=0;
    resultado= x*y;
    return resultado;
}
float divide(float x, float y)
{
    float resultado=0;
    resultado= x/y;
    return resultado;
}
