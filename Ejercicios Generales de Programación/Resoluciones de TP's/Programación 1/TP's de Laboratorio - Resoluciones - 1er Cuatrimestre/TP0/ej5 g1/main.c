#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int descuento=20;
    float comprainicio=0, comprafinal=0, x1=0;
    printf("ingrese valor de compra inicial:\n");
    scanf("%f", &comprainicio);

    if (comprainicio>5000)
        {
        x1= (float) (100-descuento)/100;
        comprafinal=comprainicio*x1;
    } else
    {
        comprafinal=comprainicio;
    }
    printf("el valor a abonar es de: %.2f", comprafinal);
    return 0;
}
