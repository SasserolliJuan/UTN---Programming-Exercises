#include <stdio.h>
#include <stdlib.h>

int main()
{
    int camisascompradas=0, conteo_camisas=0;
    float preciocamisa=0, totalinicial=0, total=0;
    printf("ingrese la cantidad de camisas compradas:\n");
    scanf("%i", &camisascompradas);
    do
    {
        printf("ingrese la precio de camisa:\n");
        scanf("%f", &preciocamisa);
        totalinicial+=preciocamisa;
        conteo_camisas++;
    }
    while (conteo_camisas<camisascompradas);
    if (camisascompradas>=3)
    {
        total=totalinicial*0.8;
    } else
    {
        total=totalinicial*0.9;
    }
    printf("el total a pagar es de: %.2f", total);
    return 0;
}
