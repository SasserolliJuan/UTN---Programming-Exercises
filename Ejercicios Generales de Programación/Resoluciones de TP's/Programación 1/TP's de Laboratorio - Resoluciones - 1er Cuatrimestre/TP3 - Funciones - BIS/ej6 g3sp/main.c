#include <stdio.h>
#include <stdlib.h>

//int negativoConRetorno (int);

int main()
{
    int a=0;
    srand(time(NULL));
    a= (rand() % 100);
    printf("valor entero positivo a convertir: %i \n", a);
    //a=negativoConRetorno(a);
    negativoPorReferencia(&a);
    printf("valor convertido: %i \n", a);
    system("pause");
    return 0;
}

void negativoPorReferencia(int *x) //el puntero le da la direccion de memoria de la variable "a". Se trabaja con la variable del main directamente.
{
    *x=-*x;
}

//int negativoConRetorno(int x) //x es un valor copia. tiene distinta direccion de memoria que "a".
//{
//   x=-x;
//    return x;
//}


