#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numero1=0, numero2=0, total=0;
    printf("ingrese el primer numero:\n");
    scanf("%f", &numero1);
    printf("ingrese el segundo numero:\n");
    scanf("%f", &numero2);
    if (numero1==numero2)
        {
        total=numero1*numero2;
        printf("se multiplica \n");
        } else
        {
            if (numero1>numero2)
                {
                total=numero1-numero2;
                printf("se resta \n");
                } else
                {
                    total=numero1+numero2;
                    printf("se suma \n");
                }
        }
    printf("la operatoria da: %f", total);
    return 0;
}
