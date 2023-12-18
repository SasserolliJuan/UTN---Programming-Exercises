#include <stdio.h>
#include <stdlib.h>

int sumatoria (int);

int main()
{
    int a=0, valor=0;
    printf("ingrese valor a operar:\n");
    scanf("%i", &a);
    valor=sumatoria(a);
    printf("sumatoria de sus anteriores positivos: %i \n", valor);
    system("pause");
    return 0;
}

int sumatoria(int x)
{
    int summa=0;
    while (x>0)
    {
        summa=summa+x;
        x--;
    }
    return summa;
}
