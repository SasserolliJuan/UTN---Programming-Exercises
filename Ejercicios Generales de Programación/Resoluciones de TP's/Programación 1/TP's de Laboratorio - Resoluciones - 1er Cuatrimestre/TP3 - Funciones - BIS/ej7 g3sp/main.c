#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=0, b=0;
    srand(time(NULL));
    a= (rand() % 100);
    printf("primer valor entero: %i \n", a);
    a= (rand() % 100);
    printf("segundo valor entero: %i \n", b);
    negativoPorReferencia(&a,&b);
    printf("primer valor nuevo: %i \n", a);
    printf("segundo valor nuevo: %i \n", b);
    system("pause");
    return 0;
}

void negativoPorReferencia(int *x, int *y) //el puntero le da la direccion de memoria de la variable "a". Se trabaja con la variable del main directamente.
{
    printf("ingrese nuevo valor de a:\n");
    scanf("%i", x);
    printf("ingrese nuevo valor de b:\n");
    scanf("%i", y);
}
