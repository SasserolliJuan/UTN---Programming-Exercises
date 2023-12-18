#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM_MAX 15
#define FIL 3
#define LONG 8

//PROTOTIPADOS

//Ejercicio 1:
void inicializacionCeldasArreglo(int arregloEnteros[]);
int cargaArregloEnteros(int arregloEnteros[], int* validos, int cantDatos);
int sumaElementosDelArreglo(int arregloEnteros[], int validos);
int cuentaDeElementosDelArreglo(int arregloEnteros[], int validos);
float calculoPromedioDelArreglo(int arregloEnteros[], int validos);

void main()
{
    int arregloEnteros[TAM_MAX], arregloEnterosE2[TAM_MAX], arregloEnterosE3[TAM_MAX], precipitaciones[12][31], arregloDiasMaximasPrecipitaciones[12], arregloOrdenado1[5] = {1,3,5,7,9}, arregloOrdenado2[5] = {2,4,6,8,10}, arregloOrdenado3[10], edades[TAM_MAX], arregloEnterosE10[TAM_MAX];
    char arregloChars[TAM_MAX], palindromo[TAM_MAX], apellidos[FIL][LONG];
    int matriz[12][31];
    int validos = 0;
    char validosChar = 0;
    int validosPrec = 0;
    int cantDatos = 0;
    int opcion = 0;
    int a = 0, b = 0;

    printf("TP1 - Lab 2. Seleccione un ejercicio: \n\n");

    system("pause");
    system("cls");

    printf("Ejercicio 1. Obtener el promedio de un arreglo de enteros. \n");
    printf("Ejercicio 2. Invertir el contenido de una arreglo. \n");
    printf("Ejercicio 3. Retornar el valor decimal de un arreglo de enteros. \n");
    printf("Ejercicio 4. Retornar la posicion del valor maximo de un arreglo. \n");
    printf("Ejercicio 5. Funciones con una matriz. \n");
    printf("Ejercicio 6. Determinar si una cadena de caracteres es un palindromo. \n");
    printf("Ejercicio 7. Intercambiar el contenido de dos variables. \n");
    printf("Ejercicio 8. Retornar un arreglo de enteros ordenados que recibe como parametros el contenido de otros dos arreglos. \n");
    printf("Ejercicio 9. Encontrar al apellido de la mayor edad usadno arreglos paralelos. \n");
    printf("Ejercicio 10. Hacer una funcion que reciba como parametros un arreglo de enteros, un valor maximo, un valor minimo y un promedio. \n");
    scanf("%i", &opcion);
    system("cls");

    switch(opcion)
    {

        float promedio = 0;
        int decimal = 0;
        int posMayor = 0;
        int mes = 0;
        int diaMaximaPrecipitacion = 0;
        int flag = 0;

        case 1:
            {
                inicializacionCeldasArreglo(arregloEnteros);
                cargaArregloEnteros(arregloEnteros, &validos, cantDatos);
                system("cls");
                promedio = calculoPromedioDelArreglo(arregloEnteros, validos);
                printf("El promedio del arreglo es de: %.2f", promedio);
                break;
            }
        case 2:
            {
                cargaArregloCaracteres(arregloChars, &validosChar);
                printf("Arreglo normal: \n");
                mostrarContenidoDelArreglo(arregloChars, validosChar);
                invertirNombre(arregloChars, validosChar);
                printf("\nArreglo invertido: \n");
                mostrarContenidoDelArreglo(arregloChars, validosChar);
                break;

            }
        case 3:
            {
                cargaArregloEnterosE2(arregloEnterosE2, &validos);
                decimal = numeroDecimalDelArreglo(arregloEnterosE2, validos);
                printf("El decimal del arreglo es: %i", decimal);
                break;
            }
        case 4:
            {
                cargaArregloEnterosE3(arregloEnterosE3, &validos);
                posMayor = mayorValorArreglo(arregloEnterosE3, validos);
                printf("El mayor elemento se encuentra en la posicion %i. \n", posMayor);
                break;
            }
        case 5:
            {
                cargaMatriz(precipitaciones, &validosPrec);
                mostrarMatriz(precipitaciones);
                printf("De que mes desea saber el dia de maxima precipitacion?: ");

                while(flag == 0)
                {
                     fflush(stdin);
                     scanf("%i", &mes);

                     if(mes > 12 || mes < 1)
                     {
                         printf("Numero no valido. \n");
                     }
                     else
                     {
                         diaMaximaPrecipitacion = diaMaximaPrecipitacionParaUnMes(precipitaciones, mes-1);
                         flag = 1;
                     }

                     printf("\nEl dia de mayor precipitacion del mes %i es el dia %i. \n", mes, diaMaximaPrecipitacion);
                }
                printf("\nMaximas precipitaciones por mes. \n");
                diasMaximasPrecipitaciones(arregloDiasMaximasPrecipitaciones, precipitaciones, &validosPrec);
                break;
            }
        case 6:
            {
                cargaPalindromo(palindromo);
                int conf = determinarSiEsPalindromo(palindromo);

                if(conf == 1)
                {
                   printf("La palabra SI es un palindromo. \n");
                }
                else
                {
                   printf("La palabra NO es un palindromo. \n");

                }
                break;
            }
        case 7:
            {
                cargaDeVariables(&a, &b);
                printf("Variables Originales: (%i,%i) \n", a, b);
                intercambio(&a, &b);
                printf("Varialbes Intercambiadas: (%i,%i) \n", a,b);
                break;
            }
        case 8:
            {
                int i = 0, j = 0, k = 0;
                intercaladoArreglos(arregloOrdenado1, arregloOrdenado2, arregloOrdenado3, &validos);

                printf("Arreglo 1: \n");

                while(i < 5)
                {
                    printf("[%i] ", arregloOrdenado1[i]);
                    i++;
                }

                printf("\n\nArreglo 2: \n");

                while(j < 5)
                {
                    printf("[%i] ", arregloOrdenado2[j]);
                    j++;
                }

                printf("\n\nArreglo Intercalado: \n");

                while(k < validos)
                {
                    printf("Elemento %i: %i \n", k+1, arregloOrdenado3[k]);
                    k++;
                }
                break;
            }
        case 9:
            {
                int pos = 0;
                cargaArregloApellidos(apellidos, edades);
                mostrarArregloApellidos(apellidos, edades);
                pos = buscarMayorEdad(edades);
                buscarNombrePorMayorEdad(apellidos, edades, pos);
                break;
            }
        case 10:
            {
                int valorMax = 0, valorMin = 0;
                float promedio = 0;
                cargaArregloEjercicio10(arregloEnterosE10, &validos);
                calculoPromedioEjercicio10(arregloEnterosE10, &valorMax, &valorMin, &promedio, validos);
                printf("\nEl maximo valor es: %i \n", valorMax);
                printf("\nEl minimo valor es: %i \n", valorMin);
                printf("\nEl promedio es: %.2f\n", promedio);
                break;
            }
        default:
            {
                break;
            }
}
}

//EJERCICIO 1.
void inicializacionCeldasArreglo(int arregloEnteros[])
{
    for(int i = -1; i < TAM_MAX; i++)
    {
        arregloEnteros[i] = 0;
    }
}

int cargaArregloEnteros(int arregloEnteros[], int* validos, int cantDatos)
{
    int flag = 0;

    printf("Cuantos datos desea ingresar? (Cant. maxima permitida: 15): \n");

    while(flag == 0)
    {
        fflush(stdin);
        scanf("%i", &cantDatos);

        if(cantDatos > TAM_MAX || cantDatos < 0)
        {
            printf("Cantidad de datos no permitida. \n");
        }
        else
        {
            flag = 1;
        }

    }

    for(int i = -1; i < cantDatos-1; i++)
    {
        printf("Ingrese el dato al arreglo: ");
        fflush(stdin);
        scanf("%i", &arregloEnteros[i]);
        (*validos)++;
    }

    return *validos;

}

int sumaElementosDelArreglo(int arregloEnteros[], int validos)
{
    int suma = 0;

    for(int i = -1; i < validos; i++)
    {
        suma += arregloEnteros[i];
    }

    return suma;
}

int cuentaDeElementosDelArreglo(int arregloEnteros[], int validos)
{
    int cont = 0;

    for(int i = -1; i < validos - 1; i++)
    {
        printf("Dato del arreglo %i: %i \n", i+1, arregloEnteros[i]);
        cont++;
    }

    printf("El arreglo tiene %i datos cargados. \n", cont);

    return cont;

}

float calculoPromedioDelArreglo(int arregloEnteros[], int validos)
{
    int suma = 0;
    int cont = 0;
    float promedio = 0;

    suma = sumaElementosDelArreglo(arregloEnteros, validos);
    cont = cuentaDeElementosDelArreglo(arregloEnteros, validos);

    promedio = (float) suma / cont;

    return promedio;

}

//EJERCICIO 2.
int cargaArregloCaracteres(char arregloChars[], int* validosChar)
{
    int i = 0;
    char continuar = 's';

    while(continuar == 's' && i < TAM_MAX)
    {
        printf("Ingrese una letra: ");
        fflush(stdin);
        scanf("%c", &arregloChars[i]);
        (*validosChar)++;
        i++;

        printf("Desea continuar?: s/n  ");
        fflush(stdin);
        scanf("%c", &continuar);
    }

   return *validosChar;

}

void invertirNombre(char arregloChars[], int validosChar)
{
    char aux;
    int j = validosChar-1;

    for(int i = 0; i < j; i++)
    {
        aux = arregloChars[i];
        arregloChars[i] = arregloChars[j];
        arregloChars[j] = aux;
        j--;
    }
}

void mostrarContenidoDelArreglo(char arregloChars[], int validosChar)
{
    for(int i = 0; i < validosChar; i++)
    {
        printf("Elemento %i: %c ", i, arregloChars[i]);
    }
}

//EJERCICIO 3.
int cargaArregloEnterosE2(int arregloEnterosE2[], int* validos)
{
    int cantDatos = 0;
    printf("Cuantos elemetnos desea ingresar?: s/n\n");
    fflush(stdin);
    scanf("%i", &cantDatos);

    printf("Ingrese elementos al arreglo: \n");

    for(int i = 0; i < cantDatos; i++)
    {
        fflush(stdin);
        scanf("%i", &arregloEnterosE2[i]);
        (*validos)++;

    }

    return *validos;
}

int numeroDecimalDelArreglo(int arregloEnterosE2[], int validos)
{
    int decimal = 0;

    for(int i = 0; i < validos; i++)
    {
        decimal = decimal * 10 + arregloEnterosE2[i];
    }

    return decimal;
}

//EJERCICIO 4.
int cargaArregloEnterosE3(int arregloEnterosE3[], int* validos)
{
    int flag = 0;
    int cantDatos = 0;

    printf("Cuantos elementos desea ingresar?: s/n\n");

    while(flag == 0)
    {
        fflush(stdin);
        scanf("%i", &cantDatos);

        if(cantDatos > TAM_MAX || cantDatos < 0)
        {
            printf("Cantidad de datos no permitida. \n");
        }
        else
        {
            flag = 1;
        }

    }

    printf("Ingrese elementos al arreglo: \n");

    for(int i = 0; i < cantDatos; i++)
    {
        printf("Elemento %i: ", i);
        fflush(stdin);
        scanf("%i", &arregloEnterosE3[i]);
        (*validos)++;

    }

    return *validos;
}

int mayorValorArreglo(int arregloEnterosE3[], int validos)
{
    int i = 0;
    int posMayor = 0;
    int elementoMayor = 0;

    elementoMayor = arregloEnterosE3[i];
    posMayor = i;

    for(i = 1; i < validos; i++)
    {
        if(arregloEnterosE3[i] > elementoMayor)
        {
            elementoMayor = arregloEnterosE3[i];
            posMayor = i;

        }
    }

    return posMayor;
}


//EJERCICIO 5.
void cargaMatriz(int precipitaciones[][31])
{
   srand(time(NULL));

   for(int i = 0; i < 12; i++)
   {
       for(int j = 0; j < 31; j++)
       {
           precipitaciones[i][j] = (rand()% 50);
       }
   }

}

void mostrarMatriz(int precipitaciones[][31])
{
     for(int i = 0; i < 12; i++)
   {
       for(int j = 0; j < 31; j++)
       {
           printf("Dia %i del mes %i. Precipitacion: %i \n", j+1, i+1, precipitaciones[i][j]);
       }

       printf("\n");
   }
}

int diaMaximaPrecipitacionParaUnMes(int precipitaciones[][31], int mes)
{
    int maxPrec = precipitaciones[mes][0];
    int diaMaxPrecipitacion = 0;

    for(int i = 1; i < 31; i++)
    {
        if(precipitaciones[mes][i] > maxPrec)
        {
            maxPrec = precipitaciones[mes][i];
            diaMaxPrecipitacion = i+1;
        }
    }

    return diaMaxPrecipitacion; // Ajustar para devolver el día real
}

int diasMaximasPrecipitaciones(int arregloDiasMaximasPrecipitaciones[12], int precipitaciones[][31], int* validosPrec)
{

    for(int i = 0; i < 12; i++)
    {
        arregloDiasMaximasPrecipitaciones[i] = diaMaximaPrecipitacionParaUnMes(precipitaciones, i);
        printf("El dia de maxima precipitacion del mes %i es el dia %i. \n", i+1, arregloDiasMaximasPrecipitaciones[i]);
        (*validosPrec)++;
    }

    return *validosPrec;
}

//EJERCICIO 6.
void cargaPalindromo(char palindromo[])
{
    printf("Ingrese una palabra (15 caracteres maximo). \n");
    fflush(stdin);
    gets(palindromo);

    while((strlen(palindromo) > TAM_MAX) || (strlen(palindromo) < 0))
    {
        printf("Cantidad de caracteres invalida. Vuelva a ingresar la palabra. \n");
    }
}

int determinarSiEsPalindromo(char palindromo[])
{
    int i = 0, j = (strlen(palindromo) -1);
    int conf;

    while((palindromo[i] == palindromo[j]) && (i != j))
    {
        printf("El caracter %c es el mismo en la posicion %i y en la posicion %i. \n", palindromo[i], i,j);
        i++;
        j--;
    }
    if(i == j)
    {
        conf = 1;
    }
    else
    {
        conf = 0;

    }

    return conf;
}

//EJERCICIO 7.
void cargaDeVariables(int* a, int* b)
{
    printf("Ingrese un valor para la variable A: \n");
    fflush(stdin);
    scanf("%i", a);  //No se usa el & porque al pasarlo por referencia, ya se tiene la dir. de memoria.

    printf("Ingrese un valor para la variable B: \n");
    fflush(stdin);
    scanf("%i", b);
}

void intercambio(int* a, int* b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

//EJERCICIO 8.
int intercaladoArreglos(int arregloOrdenado1[], int arregloOrdenado2[], int arregloOrdenado3[], int* validos)
{
    int i = 0, j = 0, k = 0;

    while(k < 10)
    {
        if((arregloOrdenado1[i] > arregloOrdenado2[j]) || (arregloOrdenado1[i] == 0))
        {
            arregloOrdenado3[k] = arregloOrdenado2[j];
            j++;
            (*validos)++;
        }
        else if((arregloOrdenado1[i] < arregloOrdenado2[j]) || (arregloOrdenado2[j] == 0))
        {
            arregloOrdenado3[k] = arregloOrdenado1[i];
            i++;
            (*validos)++;

        }
        k++;
    }

    return arregloOrdenado3[10];
}

//EJERCICIO 9.
void cargaArregloApellidos(char apellidos[][LONG], int edades[])
{
    int i = 0;

    printf("Ingrese los apellidos y luego, sus edades: \n");

    for(i = 0; i < FIL; i++)
    {
        fflush(stdin);
        gets(apellidos[i]);
        scanf("\n%i\n", &edades[i]);
        printf("\n");
    }
}

void mostrarArregloApellidos(char apellidos[][LONG], int edades[])
{
    int i = 0;

    for(i = 0; i < FIL; i++)
    {
        printf("Apellido %i: %s\n", i+1, apellidos[i]);
        printf("Edad de %s: %i\n", apellidos[i], edades[i]);
        printf("\n");
    }
}

int buscarMayorEdad(int edades[])
{
    int edadMy = 0, pos = 0, i = 0, j = 0;

    edadMy = edades[i];
    pos = i;

    for(i = 0; i < FIL; i++)
    {

        if((j = i+1) > edadMy)
        {
            edadMy = edades[j];
            pos = j;
        }
    }

    printf("La mayor edad es: %i \n", edadMy);

    return pos;
}

void buscarNombrePorMayorEdad(char apellidos[][LONG], int edades[], int pos)
{
    for(int i = 0; i < FIL; i++)
    {
        if(edades[i] == edades[pos])
        {
            printf("La edad correponde a: %s \n", apellidos[pos]);
        }
    }
}


//EJERCICIO 10.
int cargaArregloEjercicio10(int arregloEnterosE10[], int* validos)
{
    int cant = 0, i = 0;

    printf("Cuantos datos desea ingresar?: \n");
    fflush(stdin);
    scanf("%i", &cant);
    printf("\n");

    for(i = 0; i < cant; i++)
    {
        fflush(stdin);
        scanf("%i", &arregloEnterosE10[i]);
        (*validos)++;
    }

    return *validos;
}

void calculoPromedioEjercicio10(int arregloEnterosE10[], int* valorMax, int* valorMin, float* promedio, int validos)
{
    int i = 0, j = 0, suma = 0, cont = 0;

    *valorMax = arregloEnterosE10[i];


    for(i = 0; i < validos; i++)
    {
        if(arregloEnterosE10[i] > *valorMax)
        {
            *valorMax = arregloEnterosE10[i];
        }
    }



    i = 0;

    *valorMin = arregloEnterosE10[i];

    for(i = 0; i < validos; i++)
    {
        if(arregloEnterosE10[i] < *valorMin)
        {
            *valorMin = arregloEnterosE10[i];
        }
    }

    suma = sumaElementosDelArregloEjercicio10(arregloEnterosE10, validos);
    cont = contarElementosDelArregloEjercicio10(arregloEnterosE10, validos);

    *promedio = (float) suma / cont;

}

int sumaElementosDelArregloEjercicio10(int arregloEnterosE10[], int validos)
{
    int suma = 0;

    for(int i = 0; i < validos; i++)
    {
        suma += arregloEnterosE10[i];
    }

    return suma;
}

int contarElementosDelArregloEjercicio10(int arregloEnterosE10[], int validos)
{
    int cont = 0;

    for(int i = 0; i < validos; i++)
    {
        printf("Elemento %i del Arreglo: [%i] \n", i+1, arregloEnterosE10[i]);
        cont++;
    }

    return cont;
}
