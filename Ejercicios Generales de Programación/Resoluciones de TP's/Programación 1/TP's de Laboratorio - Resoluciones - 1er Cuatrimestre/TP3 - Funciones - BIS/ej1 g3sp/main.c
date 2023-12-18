#include <stdio.h>
#include <stdlib.h>

int randomm (int);

int main()
{
    int a=0, valor=0;
    a=100;
    srand(time(NULL));
    valor=randomm(a);
    printf("valor random: %i \n", valor);
    system("pause");
    return 0;
}

int randomm(int x)
{
    int resultado=0;
    resultado= (rand() % x);
    return resultado;
}
