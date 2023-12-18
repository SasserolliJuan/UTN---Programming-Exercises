#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>

int PrintMenu();
void Menu(Pila *, Pila *);
int CargarPila(Pila *);
void CargaRandomPila(Pila *);
void MostrarPila(Pila *);
void Pasaje(Pila, Pila *);
void PasajeEnElMismoOrden(Pila, Pila *);
int BuscandoMenor(Pila *);
void PilaOrdenadaSeleccion(Pila *, Pila *);
void InsertarOrdenado(Pila *, Pila *);
void PilaOrdenadaInsercion(Pila *, Pila *);
int SumaTopes(Pila *);
int Promedio(Pila *);
int SumaProm(Pila *);
int CuentaPr(Pila *);
int Division(Pila *);
int PasajePuro(Pila *);

int main()
{
    Pila a, b;
    inicpila(&a);
    inicpila(&b);
    srand(time(NULL));
    Menu(&a, &b);
    return 0;
}
int PrintMenu()
{
    int op;
    printf("1 - Hacer una funcion que permita ingresar varios elementos a una pila, tanto como quiera el\nusuario.\n\n");
    printf("2 - Hacer una funcion que pase todos los elementos de una pila a otra.\n\n");
    printf("3 - Hacer una funcion que pase todos los elementos de una pila a otra, pero conservando el orden.\n\n");
    printf("4 - Hacer una funcion que encuentre el menor elemento de una pila y lo retorna. La\nmisma debe eliminar ese dato de la pila.\n\n");
    printf("5 - Hacer una funcion que pase los elementos de una pila a otra, de manera que se genere una\nnueva pila ordenada. Usar la funcion del ejercicio 4. (Ordenamiento por seleccion)\n\n");
    printf("6 - Hacer una funcion que inserta en una pila ordenada un nuevo elemento, conservando el orden\nde esta.\n\n");
    printf("7 - Hacer una funcion que pase los elementos de una pila a otra, de manera que se genere una\nnueva pila ordenada. Usar la funcion del ejercicio 6. (Ordenamiento por insercion)\n\n");
    printf("8 - Hacer una funcion que sume y retorne los dos primeros elementos de una pila (tope y anterior),\nsin alterar su contenido.\n\n");
    printf("9 - Hacer una funcion que calcule el promedio de los elementos de una pila, para ello hacer tambien\nuna funcion que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro\nfunciones, y la funcion que calcula el promedio invoca a las otras 3.\n\n");
    printf("10- Hacer una funcion que reciba una pila con numeros de un solo digito (es responsabilidad de\nquien usa el programa) y que transforme esos digitos en un numero decimal. Por ejemplo, la pila:\n\n");
    printf("A que ejercicio desea ingresar: ");
    scanf("%i", &op);
    system("cls");
    return op;
}
void Menu(Pila *a, Pila *b)
{
    int op, valor;
    do
    {
        op = PrintMenu();
        switch(op)
        {
        case 1:
            printf("1 - Hacer una funcion que permita ingresar varios elementos a una pila, tanto como quiera el\nusuario.\n\n");
            CargarPila(a);
            MostrarPila(a);
            system("pause");
            system("cls");
            break;
        case 2:
            printf("2 - Hacer una funcion que pase todos los elementos de una pila a otra.\n\n");
            CargarPila(a);
            Pasaje(*a, b);
            MostrarPila(b);
            system("pause");
            system("cls");
            break;
        case 3:
            printf("3 - Hacer una funcion que pase todos los elementos de una pila a otra, pero conservando el orden.\n\n");
            CargarPila(a);
            PasajeEnElMismoOrden(*a, b);
            MostrarPila(b);
            system("pause");
            system("cls");
            break;
        case 4:
            printf("4 - Hacer una funcion que encuentre el menor elemento de una pila y lo retorna. La\nmisma debe eliminar ese dato de la pila.\n\n");
            CargarPila(a);
            valor = BuscandoMenor(a);
            printf("\nEl menor elemento es: %i\n", valor);
            system("pause");
            system("cls");
            break;
        case 5:
            printf("5 - Hacer una funcion que pase los elementos de una pila a otra, de manera que se genere una\nnueva pila ordenada. Usar la funcion del ejercicio 4. (Ordenamiento por seleccion)\n\n");
            CargaRandomPila(a);
            PilaOrdenadaSeleccion(a, b);
            MostrarPila(b);
            system("pause");
            system("cls");
            break;
        case 6:
            printf("6 - Hacer una funcion que inserta en una pila ordenada un nuevo elemento, conservando el orden\nde esta.\n\n");
            CargarPila(a);
            printf("Ingrese un valor/elemento a la pila: ");
            scanf("%i", &valor);
            apilar(b, valor);
            InsertarOrdenado(a, b);
            MostrarPila(a);
            system("pause");
            system("cls");
            break;
        case 7:
            printf("7 - Hacer una funcion que pase los elementos de una pila a otra, de manera que se genere una\nnueva pila ordenada. Usar la funcion del ejercicio 6. (Ordenamiento por insercion)\n\n");
            CargarPila(a);
            PilaOrdenadaInsercion(b,a);
            MostrarPila(b);
            system("pause");
            system("cls");
            break;
        case 8:
            printf("8 - Hacer una funcion que sume y retorne los dos primeros elementos de una pila (tope y anterior),\nsin alterar su contenido.\n\n");
            CargaRandomPila(a);
            valor = SumaTopes(a);
            printf("La suma de los topes es: %i\n", valor);
            system("pause");
            system("cls");
            break;
        case 9:
            printf("9 - Hacer una funcion que calcule el promedio de los elementos de una pila, para ello hacer tambien\nuna funcion que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro\nfunciones, y la funcion que calcula el promedio invoca a las otras 3.\n\n");
            CargaRandomPila(a);
            valor = Promedio(a);
            printf("El promedio de la pila es: %i", valor);
            system("pause");
            system("cls");
            break;
        case 10:
            printf("10- Hacer una funcion que reciba una pila con numeros de un solo digito (es responsabilidad de\nquien usa el programa) y que transforme esos digitos en un numero decimal. Por ejemplo, la pila:\n\n");
            CargaRandomPila(a);
            valor = PasajePuro(a);
            MostrarPila(a);
            printf("El numero de la pila es: %i\n", valor);
            system("pause");
            system("cls");
            break;
        }
    }
    while(op != 0);
}
///--------------------------------------------------------------------------------------------------
/**Ejercicios extra, con el fin de generar una experiencia de usuario diferente a la que otorga la librería
se requiere desarrollar las siguientes funciones:**/
/**● Realizar una función que cargue la pila sin utilizar la función leer.**/
///--------------------------------------------------------------------------------------------------
/**1 - Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el\n
usuario.**/
int CargarPila(Pila *a)
{
    int valor, i = 0;
    char ctrl;

    do
    {
        printf("Ingrese un valor entero: ");
        scanf("%i", &valor);
        apilar(a, valor);
        i++;
        printf("Desea ingresar otro valor: ");
        fflush(stdin);
        scanf("%c", &ctrl);
    }
    while(ctrl == 's' || ctrl == 'S');
    return i;
}
/**Carga random pila**/
void CargaRandomPila(Pila *a)
{
    char ctrl;
    int valor = 0;
    do
    {
        valor = rand()%9;
        printf("El valor ingresado random es: %i\n", valor);
        apilar(a, valor);
        printf("Desea ingresar otro valor: ");
        fflush(stdin);
        scanf("%c", &ctrl);
    }
    while(ctrl == 's' || ctrl == 'S');
}
///--------------------------------------------------------------------------------------------------
/**● Realizar una función que muestre la pila sin utilizar la función mostrar**/
///--------------------------------------------------------------------------------------------------
/**Mostrar Pila**/
void MostrarPila(Pila *a)
{
    Pila aux;
    inicpila(&aux);
    int valor=0;
    printf("\nTope");
    while(!pilavacia(a))
    {
        valor = tope(a);
        printf(" %i -", valor);
        apilar(&aux, desapilar(a));
    }
    printf("Base\n\n");
    while(!pilavacia(&aux))
    {
        apilar(a, desapilar(&aux));
    }
}
/**2 - Hacer una función que pase todos los elementos de una pila a otra.**/
void Pasaje(Pila a, Pila *b)
{
    while(!pilavacia(&a))
    {
        apilar(b, desapilar(&a));
    }
}
/**3 - Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.**/
void PasajeEnElMismoOrden(Pila a, Pila *b)
{
    Pila aux;
    inicpila(&aux);
    Pasaje(a, &aux);
    Pasaje(aux, b);
}
/**4 - Hacer una función que encuentre el menor elemento de una pila y lo retorna. La\n
misma debe eliminar ese dato de la pila.**/
int BuscandoMenor(Pila *a)
{
    Pila aux, menor;
    inicpila(&aux);
    inicpila(&menor);
    apilar(&menor, desapilar(a));
    while(!pilavacia(a))
    {
        if(tope(a) < tope(&menor))
        {
            apilar(&aux, desapilar(&menor));
            apilar(&menor, desapilar(a));
        }
        else
        {
            apilar(&aux, desapilar(a));
        }
    }
    while(!pilavacia(&aux))
    {
        apilar(a, desapilar(&aux));
    }
    return tope(&menor);
}
/**5 - Hacer una función que pase los elementos de una pila a otra, de manera que se genere una\n
nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)**/
void PilaOrdenadaSeleccion(Pila *a, Pila *b)
{
    while(!pilavacia(a))
    {
        apilar(b, BuscandoMenor(a));
    }
}
/**6. Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden
de ésta.**/
void InsertarOrdenado(Pila *a, Pila *b)
{
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(b)&&tope(a)<tope(b))
    {
        apilar(&aux, desapilar(a));
    }
    apilar(a,desapilar(b));
    while(!pilavacia(&aux))
    {
        apilar(a, desapilar(&aux));
    }
}
/**7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
nueva pila ordenada. Usar la función del ejercicio 6. (Ordenamiento por inserción)**/
void PilaOrdenadaInsercion(Pila *a, Pila *b)
{
    while(!pilavacia(b))
    {
        InsertarOrdenado(a,b);
    }
}
/**8. Hacer una función que sume y retorne los dos primeros elementos de una pila (tope y anterior),
sin alterar su contenido.**/
int SumaTopes(Pila *a)
{
    Pila b;
    inicpila(&b);
    int suma=0;
    for(int i = 0; i<2; i++)
    {
        suma += tope(a);
        apilar(&b, desapilar(a));
    }
    return suma;
}
/**9. Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también
una función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro
funciones, y la función que calcula el promedio invoca a las otras 3.**/
int Promedio(Pila *a)
{
    int rta = 0;
    rta = Division(a);
    return rta;
}
int SumaProm(Pila *a)
{
    Pila b;
    inicpila(&b);
    int suma=0;
    while(!pilavacia(a))
    {
        suma = suma + tope(a);
        apilar(&b, desapilar(a));
    }
    while(!pilavacia(&b))
    {
        apilar(a, desapilar(&b));
    }
    return suma;
}
int CuentaPr(Pila *a)
{
    Pila b;
    inicpila(&b);
    int i=0;
    while(!pilavacia(a))
    {
        apilar(&b, desapilar(a));
        i++;
    }
    while(!pilavacia(&b))
    {
        apilar(a, desapilar(&b));
    }
    return i;
}
int Division(Pila *a)
{
    int div = 0, sum = 0, con = 0;
    sum = SumaProm(a);
    con = CuentaPr(a);
    div = sum / con;
    return div;
}

/**10. Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad de
quien usa el programa) y que transforme esos dígitos en un número decimal. Por ejemplo, la pila:**/
/**
    1
    4
    6   Debe retornar el número: 14675
    7
    5
**/
int PasajePuro(Pila *a)
{
    Pila aux, aux1;
    inicpila(&aux);
    inicpila(&aux1);
    int numero = 0, valor = 0, i = 1;
    while(!pilavacia(a))
    {
        valor = tope(a);
        numero = (i * valor) + numero;
        i = i * 10;
        apilar(&aux, desapilar(a));
    }
    while(!pilavacia(&aux))
    {
        apilar(a, desapilar(&aux));
    }

    return numero;
}
