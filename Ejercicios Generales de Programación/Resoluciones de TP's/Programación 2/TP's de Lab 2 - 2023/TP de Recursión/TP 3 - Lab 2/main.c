#include <stdio.h>
#include <stdlib.h>

// PROTOTIPADOS

// Ejercicio 1:
int factorial(int);

// Ejercicio 2:
int potencia(int, int);

// Ejercicio 3:
int cargaArreglo(int[], int *);
void muestraArregloRecursivo(int[], int, int);

// Ejercicio 4:
int cargaArreglo2(int[], int *);
void muestraArregloRecursivoInvertido(int[], int, int);

// Ejercicio 5:
int cargaArreglo3(int[], int *);
int arregloCapicuaRecursivo(int[], int, int);

// Ejercicio 6:
int cargaArreglo4(int[], int *);
int sumaRecursiva(int[], int, int);

// Ejercicio 7:
int cargaArreglo5(int[], int *);
int busquedaMenorRecursivo(int[], int, int);

// Ejercicio 8:
void cargaArchivoEnteros(FILE *, char[]);
int busquedaMenorArchivoRecursivo(FILE *, char[]);
void abrirYbuscarMenorEnArchivo(FILE *, char[]);

// Ejercicio 9:
void cargaArchivoEnteros2(FILE *, char[]);
void invertirArchivoRecursivo(FILE *, FILE *);
void abrirEinvertirElementosEnArchivo(FILE *, FILE *, char[], char[]);
void mostrarArchivos(FILE *, FILE *, char[], char[]);

// Ejercicio 10:
void cargaArchivoEnteros3(FILE *, char[]);
void mostrarArchivoRecursivo(FILE *, char[]);
void abrirYmostrarElementosDeArchvioRecursivo(FILE *, char[]);

// Ejercicio 11:
void mostrarLetrasInversas();

// Ejercicio 12:
int cargaArreglo6(int[], int *);
int busquedaDeUnElementoDetEnArregloRecursivo(int[], int, int, int);

int main()
{
    menu();
}

void menu()
{
    int opcion = 0;

    printf("Elija un ejercicio. \n");

    system("pause");
    system("cls");

    printf("1. Calcular el factorial de un numero en forma recursiva. \n");
    printf("2. Calcular la potencia de un numero en forma recursiva. \n");
    printf("3. Recorrer un arreglo y mostrar sus elementos en forma recursiva. \n");
    printf("4. Recorrer un arreglo comenzando desde la posicion 0 y mostrar sus elementos en forma invertida (recursivo). \n");
    printf("5. Determinar en forma recursiva si un arreglo es capicua. \n");
    printf("6. Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma. \n");
    printf("7. Buscar el menor elemento de un arreglo en forma recursiva. \n");
    printf("8. Buscar el menor elemento de un archivo de numeros enteros de forma recursiva (desde el mismo archivo). \n");
    printf("9. Invertir los elementos de un archivo de numeros enteros de forma recursiva. (si no te sale, primero proba con invertir los elementos de un arreglo de int). \n");
    printf("10. Recorrer un archivo y mostrar sus elementos en forma invertida de forma recursiva. \n");
    printf("11. Ingresar valores a una variable de tipo char (por teclado) y mostrarlo en el orden inverso (hasta ingresar un asterisco) de forma recursiva. NO usar arreglos. \n");
    printf("12. Determinar si un arreglo contiene un determinado elemento de forma recursiva (pueden intentarlo tambien con una funcion void). \n");
    printf("\n");
    fflush(stdin);
    scanf("%i", &opcion);

    system("cls");

    switch (opcion)
    {
    case 1:
    {
        int numero = 0, rta = 0;
        printf("Ingrese el numero del que desea saber el factorial: \n");
        fflush(stdin);
        scanf("%i", &numero);
        rta = factorial(numero);
        printf("El factorial de %i es %i", numero, rta);
        break;
    }
    case 2:
    {
        int numero = 0, pot = 0, rta = 0;
        printf("Ingrese el numero del que desea X potencia: \n");
        fflush(stdin);
        scanf("%i", &numero);
        printf("Ingrese la potencia a elevar el numeor %i: \n", numero);
        fflush(stdin);
        scanf("%i", &pot);
        rta = potencia(numero, pot);
        printf("El numero %i a la %ia potencia es %i. \n", numero, pot, rta);
        break;
    }
    case 3:
    {
        int A[6];
        int validos = 0;
        int i = 0;
        validos = cargaArreglo(A, &validos);
        muestraArregloRecursivo(A, i, validos);
        break;
    }
    case 4:
    {
        int A[6];
        int validos = 0;
        int i = 0;
        validos = cargaArreglo2(A, &validos);
        muestraArregloRecursivoInvertido(A, i, validos);
        break;
    }
    case 5:
    {
        int A[6];
        int validos = 0;
        int i = 0, j = 5;
        int rta = 0;
        cargaArreglo3(A, &validos);
        rta = arregloCapicuaRecursivo(A, i, j);
        if (rta == 1)
        {
            printf("El arreglo ES capicua. \n");
        }
        else
        {
            printf("El arreglo NO es capicua. \n");
        }
        break;
    }
    case 6:
    {
        int A[6];
        int validos = 0;
        int i = 0;
        int suma = 0;
        cargaArreglo4(A, &validos);
        suma = sumaRecursiva(A, i, validos);
        printf("La suma del arreglo es: %i", suma);
        break;
    }
    case 7:
    {
        int A[6];
        int validos = 0;
        int i = 0;
        int menor = 0;
        cargaArreglo5(A, &validos);
        menor = busquedaMenorRecursivo(A, i, validos);
        printf("El menor elemento del arreglo es: %i", menor);
        break;
    }
    case 8:
    {
        int menor = 0;
        FILE *archi;
        char nombreArchivo[20];
        printf("Ingrese el nombre del archivo: \n");
        fflush(stdin);
        gets(nombreArchivo);
        cargaArchivoEnteros(archi, nombreArchivo);
        abrirYbuscarMenorEnArchivo(archi, nombreArchivo);
        break;
    }
    case 9:
    {
        FILE *archi;
        FILE *archi2;
        char nombreArchivo[20], nombreArchivo2[20];
        printf("Ingrese el nombre del archivo 1: \n");
        fflush(stdin);
        gets(nombreArchivo);
        printf("Ingrese el nombre del archivo 2: \n");
        fflush(stdin);
        gets(nombreArchivo2);
        cargaArchivoEnteros2(archi, nombreArchivo);
        abrirEinvertirElementosEnArchivo(archi, archi2, nombreArchivo, nombreArchivo2);
        mostrarArchivos(archi, archi2, nombreArchivo, nombreArchivo2);
        break;
    }
    case 10:
    {
        FILE *archi;
        char nombreArchivo[20];
        printf("Ingrese el nombre del archivo: \n");
        fflush(stdin);
        gets(nombreArchivo);
        cargaArchivoEnteros(archi, nombreArchivo);
        abrirYmostrarElementosDeArchvioRecursivo(archi, nombreArchivo);
        break;
    }
    case 11:
    {
        mostrarLetrasInversas();
        break;
    }
    case 12:
    {
        int A[6];
        int validos = 0;
        int elemento = 0;
        int i = 0;
        int rta = 0;
        cargaArreglo6(A, &validos);
        printf("Ingrese el elemento a buscar: \n");
        fflush(stdin);
        scanf("%i", &elemento);
        rta = busquedaDeUnElementoDetEnArregloRecursivo(A, i, elemento, validos);
        if (rta == 1)
        {
            printf("Elemento encontrado. \n");
        }
        else
        {
            printf("Elemento NO encontrado. \n");
        }
        break;
    }
    }
}

// EJERCICIO 1:
int factorial(int numero)
{
    int rta;

    if (numero == 0)
    {
        rta = 1;
    }
    else
    {
        rta = numero * factorial(numero - 1);
    }

    return rta;
}

// EJERCICIO 2:
int potencia(int numero, int pot)
{
    int rta;

    if (pot == 0)
    {
        rta = 1;
    }
    else
    {
        rta = numero * potencia(numero, pot - 1);
    }

    return rta;
}

// EJERCICIO 3:
int cargaArreglo(int A[6], int *validos)
{
    printf("Ingrese los datos del arreglo. Maximo 6 elementos. \n");

    for (int i = 0; i < 6; i++)
    {
        fflush(stdin);
        scanf("%i", &A[i]);
        (*validos)++;
    }

    return *validos;
}

void muestraArregloRecursivo(int A[], int i, int validos)
{
    if (i == validos - 1)
    {
        printf("%i", A[i]);
    }
    else
    {
        printf("%i", A[i]);
        muestraArregloRecursivo(A, i + 1, validos);
    }
}

// EJERCICIO 4:
int cargaArreglo2(int A[6], int *validos)
{
    printf("Ingrese los datos del arreglo. Maximo 6 elementos. \n");

    for (int i = 0; i < 6; i++)
    {
        fflush(stdin);
        scanf("%i", &A[i]);
        (*validos)++;
    }

    return *validos;
}

void muestraArregloRecursivoInvertido(int A[], int i, int validos)
{
    if (i == validos - 1)
    {
        printf("%i", A[i]);
    }
    else
    {
        muestraArregloRecursivoInvertido(A, i + 1, validos);
        printf("%i", A[i]);
    }
}

// EJERCICIO 5:
int cargaArreglo3(int A[6], int *validos)
{
    printf("Ingrese los datos del arreglo. Maximo 6 elementos. \n");

    for (int i = 0; i < 6; i++)
    {
        fflush(stdin);
        scanf("%i", &A[i]);
        (*validos)++;
    }

    return *validos;
}

int arregloCapicuaRecursivo(int A[], int i, int j)
{
    int rta = 1;

    if (i < j)
    {
        if (A[i] == A[j])
        {
            rta = arregloCapicuaRecursivo(A, i + 1, j - 1);
        }
        else
        {
            rta = 0;
        }
    }

    return rta;
}

// EJERCICIO 6:
int cargaArreglo4(int A[6], int *validos)
{
    printf("Ingrese los datos del arreglo. Maximo 6 elementos. \n");

    for (int i = 0; i < 6; i++)
    {
        fflush(stdin);
        scanf("%i", &A[i]);
        (*validos)++;
    }

    return *validos;
}

int sumaRecursiva(int A[], int i, int validos)
{
    int rta;

    if (i == validos - 1)
    {
        rta = A[i];
    }
    else
    {
        rta = A[i] + sumaRecursiva(A, i + 1, validos);
    }

    return rta;
}

// EJERCICIO 7:
int cargaArreglo5(int A[6], int *validos)
{
    printf("Ingrese los datos del arreglo. Maximo 6 elementos. \n");

    for (int i = 0; i < 6; i++)
    {
        fflush(stdin);
        scanf("%i", &A[i]);
        (*validos)++;
    }

    return *validos;
}

int busquedaMenorRecursivo(int A[], int i, int validos)
{
    int menor;

    if (i == validos - 1)
    {
        menor = A[i];
    }
    else
    {
        menor = busquedaMenorRecursivo(A, i + 1, validos);

        if (menor > A[i])
        {
            menor = A[i];
        }
    }

    return menor;
}

// EJERCICIO 8:
void cargaArchivoEnteros(FILE *archi, char nombreArchivo[])
{
    int numero = 0;
    archi = fopen(nombreArchivo, "wb");

    if (archi != NULL)
    {
        printf("Ingrese los numeros al archivo: \n");

        for (int i = 0; i < 6; i++)
        {
            fflush(stdin);
            scanf("%i", &numero);
            fwrite(&numero, sizeof(int), 1, archi);
        }

        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir el archivo para escritura binaria. \n");
    }
}

int busquedaMenorArchivoRecursivo(FILE *archi, char nombreArchivo[])
{
    int menor, aux;

    if (fread(&aux, sizeof(int), 1, archi) == 0)
    {
        fseek(archi, -1 * sizeof(int), SEEK_END);

        fread(&menor, sizeof(int), 1, archi);
    }
    else
    {
        menor = busquedaMenorArchivoRecursivo(archi, nombreArchivo);

        if (aux < menor)
        {
            menor = aux;
        }
    }

    return menor;
}

void abrirYbuscarMenorEnArchivo(FILE *archi, char nombreArchivo[])
{
    int menor;
    archi = fopen(nombreArchivo, "rb");

    if (archi != NULL)
    {
        menor = busquedaMenorArchivoRecursivo(archi, nombreArchivo);
        printf("El menor elemento del archivo es: %i", menor);
        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir el archivo para lectura y escritura binaria. \n");
    }
}

// EJERCICIO 9:
void cargaArchivoEnteros2(FILE *archi, char nombreArchivo[])
{
    int numero = 0;
    archi = fopen(nombreArchivo, "wb");

    if (archi != NULL)
    {
        printf("Ingrese los numeros al archivo: \n");

        for (int i = 0; i < 6; i++)
        {
            fflush(stdin);
            scanf("%i", &numero);
            fwrite(&numero, sizeof(int), 1, archi);
        }

        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir el archivo para escritura binaria. \n");
    }
}

void invertirArchivoRecursivo(FILE *archi, FILE *archi2)
{
    int org;

    if (fread(&org, sizeof(int), 1, archi) != 0) // Condicion de corte implic�ta
    {
        invertirArchivoRecursivo(archi, archi2);
        fseek(archi2, 0, SEEK_END); // Mover el puntero al final del archivo 2
        fwrite(&org, sizeof(int), 1, archi2);
    }
}

void abrirEinvertirElementosEnArchivo(FILE *archi, FILE *archi2, char nombreArchivo[], char nombreArchivo2[])
{
    int menor;
    archi = fopen(nombreArchivo, "r+b");

    if (archi != NULL)
    {
        archi2 = fopen(nombreArchivo2, "wb"); // Abrir para escritura
        if (archi2 != NULL)
        {
            invertirArchivoRecursivo(archi, archi2);
            fclose(archi2);
        }
        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir el archivo para lectura y escritura binaria. \n");
    }
}

void mostrarArchivos(FILE *archi, FILE *archi2, char nombreArchivo[], char nombreArchivo2[])
{
    int org;
    int aux;
    int i = 0;
    archi = fopen(nombreArchivo, "rb");
    archi2 = fopen(nombreArchivo2, "rb");

    if ((archi != NULL) && (archi2 != NULL))
    {
        while (fread(&org, sizeof(int), 1, archi) > 0)
        {
            printf("Elemento %i del archivo 1: %i \n", i + 1, org);
            i++;
        }

        i = 0;
        while (fread(&aux, sizeof(int), 1, archi2) > 0)
        {
            printf("Elemento %i del archivo 2: %i \n", i + 1, aux);
            i++;
        }

        fclose(archi);
        fclose(archi2);
    }
    else
    {
        printf("No se pudieron abrir los archivos para mostrarlos. \n");
    }
}

// EJERCICIO 10:
void cargaArchivoEnteros3(FILE *archi, char nombreArchivo[])
{
    int numero = 0;
    archi = fopen(nombreArchivo, "wb");

    if (archi != NULL)
    {
        printf("Ingrese los numeros al archivo: \n");

        for (int i = 0; i < 6; i++)
        {
            fflush(stdin);
            scanf("%i", &numero);
            fwrite(&numero, sizeof(int), 1, archi);
        }

        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir el archivo para escritura binaria. \n");
    }
}

void mostrarArchivoRecursivo(FILE *archi, char nombreArchivo[])
{
    int aux;
    int imp;

    if (fread(&aux, sizeof(int), 1, archi) != 0)
    {
        mostrarArchivoRecursivo(archi, nombreArchivo);
        printf("%i \n", aux);
    }
}

void abrirYmostrarElementosDeArchvioRecursivo(FILE *archi, char nombreArchivo[])
{
    archi = fopen(nombreArchivo, "rb");

    if (archi != NULL)
    {
        mostrarArchivoRecursivo(archi, nombreArchivo);
        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir el archivo para lectura. \n");
    }
}

// EJERCICIO 11:
void mostrarLetrasInversas()
{
    char letra;

    printf("Ingrese una letra. En caso de ingresar un '*' se van a mostrar todas las letras ingresadas: \n");
    fflush(stdin);
    scanf("%c", &letra);

    if (letra != '*')
    {
        mostrarLetrasInversas();
        printf("Letra: %c \n", letra);
    }
}

// EJERCICIO 12:
int cargaArreglo6(int A[6], int *validos)
{
    printf("Ingrese los datos del arreglo. Maximo 6 elementos. \n");

    for (int i = 0; i < 6; i++)
    {
        fflush(stdin);
        scanf("%i", &A[i]);
        (*validos)++;
    }

    return *validos;
}

int busquedaDeUnElementoDetEnArregloRecursivo(int A[], int i, int elemento, int validos)
{
    int rta;

    if (i < validos - 1)
    {
        if (elemento == A[i])
        {
            rta = 1;
        }
        else
        {
            rta = busquedaDeUnElementoDetEnArregloRecursivo(A, i + 1, elemento, validos);
        }
    }
    else
    {
        rta = 0;
    }

    return rta;
}
