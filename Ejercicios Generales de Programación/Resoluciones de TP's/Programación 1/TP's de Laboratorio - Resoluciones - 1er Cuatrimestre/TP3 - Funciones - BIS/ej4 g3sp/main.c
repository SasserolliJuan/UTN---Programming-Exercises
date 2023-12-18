#include <stdio.h>
#include <stdlib.h>

int tabla (int);

int main()
{
    int a=0;
    printf("ingrese valor a operar:\n");
    scanf("%i", &a);
    tabla(a);
    system("pause");
    return 0;
}

int tabla(int x)
{
    int multi=0, i=0;
    for (i=1; i<11; i++)
    {
        multi=x*i;
        printf("%i x %i = %i \n",x,i,multi);
    }
    return 0;
}
