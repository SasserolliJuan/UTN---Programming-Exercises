#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

void ordenacionInsercion(int C[], int validosC)
{
    int aux = 0, j = 0;

    for(int i = 1; i < validosC; i++)
    {
        aux = C[i];

        for(j = i ; j > 0 && C[j - 1] > aux; j--)
        {
            C[j] = C[j-1];
        }
         C[j] = aux;
    }
}
