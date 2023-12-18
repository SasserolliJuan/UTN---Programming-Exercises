#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numero1=0, numero2=0, numero3=0;
    printf("ingrese el primer numero:\n");
    scanf("%f", &numero1);
    printf("ingrese el segundo numero:\n");
    scanf("%f", &numero2);
    printf("ingrese el tercer numero:\n");
    scanf("%f", &numero3);
    if ((numero1==numero2)&&(numero1==numero3))
        {
        printf("son iguales los 3\n");
        } else {
        if ((numero1>=numero2)&&(numero1>=numero3))
            {
            if (numero1==numero2)
            {
                printf("el 1er y 2do numero son los mayores");
            }
            else
                {
                if (numero1==numero3)
                    {
                    printf("el 1er y 3er numero son iguales");
                    } else
                    {
                        printf("el mayor es el 1er numero");
                    }
                }
        } else
        {
            if ((numero2>=numero1)&&(numero2>=numero3))
                {
                if (numero2==numero1)
                {
                    printf("el 1er y 2do numero son los mayores");
                }
                else
                {
                    if (numero2==numero3)
                    {
                        printf("el 2do y 3er numero son iguales");
                    } else
                    {
                        printf("el mayor es el 2do numero");
                    }
                }
                } else
                {
                    if ((numero3>=numero1)&&(numero3>=numero2))
                {
                if (numero3==numero1)
                {
                    printf("el 1er y 3er numero son los mayores");
                }
                else
                {
                    if (numero3==numero2)
                    {
                        printf("el 2do y 3er numero son iguales");
                    } else
                    {
                        printf("el mayor es el 3er numero");
                    }
                }
                }
                }
        }
        }
    return 0;
}
