#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0, j=0, conteo=0;
    float numerox=0, cubo=1, cuarta=1;

    do {
        printf("ingrese numero:\n");
        scanf("%f", &numerox);
        conteo++;
        cubo=1;
        cuarta=1;
        for (i=1;i<4;i++)
            {
            cubo*=numerox;
            }
        for (j=1;j<5;j++)
            {
            cuarta*=numerox;
            }
        printf("%f al cubo da:\n", numerox);
        printf("%.2f\n", cubo);
        printf("%f a la cuarta da:\n", numerox);
        printf("%.2f\n", cuarta);
    }
    while (conteo<10);
    return 0;
}
