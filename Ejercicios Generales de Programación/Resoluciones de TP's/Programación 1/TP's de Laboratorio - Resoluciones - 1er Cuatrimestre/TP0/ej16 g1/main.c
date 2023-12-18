#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;
    float numerox=0, producto=0;
    printf("ingrese numero a evaluar su tabla: \n");
    scanf("%f", &numerox);
    printf("multiplicando x multiplicador = producto \n");
    do
    {
        producto=numerox*i;
        printf("%.1f x %i = %.1f \n", numerox, i, producto);
        i++;
    }
    while (i<11);
    return 0;
}
