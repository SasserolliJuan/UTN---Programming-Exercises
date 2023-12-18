#include <stdio.h>
#include <stdlib.h>

int main()
{
    int descuento=0;
    float totalcompra=0, comprainicial=0, x1=0;
    printf("ingrese total de compra inicial:\n");
    scanf("%f", &comprainicial);
    printf("ingrese descuento:\n");
    scanf("%d", &descuento);
    x1=(float) (100-descuento)/100;

    totalcompra=comprainicial*x1;
    printf("el total a pagar es: %2f", totalcompra);

    return 0;
}
