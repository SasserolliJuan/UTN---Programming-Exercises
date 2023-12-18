#include <stdio.h>
#include <stdlib.h>

int comparador (int, int, int);

int main()
{
    int a=0, b=0, c=0, valor=0;
    printf("1er numero: \n");
    scanf("%i", &a);
    printf("2do numero: \n");
    scanf("%i", &b);
    printf("3er numero: \n");
    scanf("%i", &c);
    comparador(a,b,c);

    system("pause");
    return 0;
}

int comparador(int x, int y, int z)
{
    if (x>y && y>z)
    {
        printf("Valor maximo: %i \n", x);
        printf("Valor minimo: %i \n", z);
    } else
    {
       if (x>y && x<z)
       {
           printf("Valor maximo: %i \n", z);
           printf("Valor minimo: %i \n", y);
       } else
       {
           if (x<y && x>z)
       {
           printf("Valor maximo: %i \n", y);
           printf("Valor minimo: %i \n", z);
       } else
       {
           if (x>z && y<z)
       {
           printf("Valor maximo: %i \n", x);
           printf("Valor minimo: %i \n", y);
       } else
       {
           if (x<y && y<z)
       {
           printf("Valor maximo: %i \n", z);
           printf("Valor minimo: %i \n", x);
       } else
       {
           if (x<y && x<z)
       {
           printf("Valor maximo: %i \n", y);
           printf("Valor minimo: %i \n", x);
       } else
       {
           printf("no hay solucion");
       }
       }
       }
       }
       }
    }
    return 0;

}
