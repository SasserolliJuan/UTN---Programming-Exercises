#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1=0, z1=0;
    printf("ingrese valor de variable x1:\n");
    scanf("%i", &x1);
    printf("ingrese valor de variable z1:\n");
    scanf("%i", &z1);
    if (x1>z1)
        {
        printf("en orden ascendente: %i \n", x1);
        printf("%i", z1);
        }
        else
            {
            if (z1>x1)
            {
                printf("en orden ascendente: %i \n", z1);
                printf("%i", x1);
            }
            else
                {
                printf("son iguales");
                }
            }
    return 0;
}
