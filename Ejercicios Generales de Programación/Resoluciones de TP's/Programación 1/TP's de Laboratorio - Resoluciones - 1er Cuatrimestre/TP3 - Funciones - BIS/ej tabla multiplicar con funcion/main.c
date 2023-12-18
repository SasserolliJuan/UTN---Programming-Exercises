#include <stdio.h>
#include <stdlib.h>

int tablademultiplicar(int,int);

int main()
{
    int n=0, mul=0;
    printf("ingrese numero a multiplicar:\n");
    scanf("%i", &n);
    printf("ingrese hasta que numero multiplicar:\n");
    scanf("%i", &mul);
    tablademultiplicar(n,mul);
    return 0;
}

int tablademultiplicar(int a, int b)
{
    int i=0, valor=0;
    printf("valor = a x i \n");
    for (i=0; i<=b; i++)
    {
        valor=a*i;
        printf("%i = %i x %i \n",valor,a,i);
    }
    return 0;
}
