#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define DIM 100

typedef struct
{
    char patente[6];
    int valor;
    char marca[10];
} stAuto;

typedef struct _nodoAuto
{
    stAuto dato;
    struct _nodoAuto* siguiente;
} nodoAuto;

nodoAuto* inicLista()
{
    return NULL;
}

nodoAuto * crearNodo (stAuto a);
nodoAuto* buscaUltimo(nodoAuto* lista);
void agregarFinal(nodoAuto** lista, nodoAuto* nuevo);
int insertarCelda(stAuto A[], stAuto a, int v);
void agregarMuchos(nodoAuto** lista);
void mostrarUnAuto(stAuto a);
void mostrarLista(nodoAuto* lista);
int pasar(nodoAuto* lista, stAuto A[]);
void mostrarArregloRecursivo(stAuto A[], int i, int cant);
int sumaValorListaR(nodoAuto* lista);
int dameUltimoValorPatente(char patente[]);


int main()
{
    printf("Hello practica adicional!\n");

    nodoAuto * lista = inicLista();
    agregarMuchos(&lista);

    printf("\n Contenido de la lista: \n");
    mostrarLista(lista);

    stAuto ArregloDeAutos[DIM];
    int validos =0;

    validos=pasar(lista, ArregloDeAutos);

    printf("\n Contenido del arreglo cargado con los datos de la lista: \n");
    mostrarArregloRecursivo(ArregloDeAutos, 0, validos);

    int suma = sumaValorListaR(lista);

    printf("\n Suma de los valores pares de la lista: %d", suma);

    return 0;
}



/**
1) Crea un nodo de tipo nodoAuto *.
*/

nodoAuto * crearNodo (stAuto a)
{
    nodoAuto * aux = (nodoAuto *) malloc(sizeof(nodoAuto));
    aux->dato = a;
    aux->siguiente=NULL;
    return aux;
}

/**
2)Agrega un nuevo nodo al final de la lista (utilizando puntero doble)
*/
nodoAuto* buscaUltimo(nodoAuto* lista)
{
    nodoAuto* seg=lista;
    if(seg){
        while(seg->siguiente){
            seg=seg->siguiente;
        }
    }
    return seg;
}

void agregarFinal(nodoAuto** lista, nodoAuto* nuevo)
{
    if(!(*lista)){
        (*lista)=nuevo;
    }
    else{
        nodoAuto* ultimo = buscaUltimo(*lista);
        ultimo->siguiente=nuevo;
    }
}
/**
3) Inserta los datos de un nuevo auto en el arreglo, de manera de conservarlo ordenado
por valor en forma creciente. C es la cantidad de datos que tiene el arreglo y retorna c+1.
Al inicio c vale 0.
*/
int insertarCelda(stAuto A[], stAuto a, int v)
{
    int i = v-1;


    /// buscamos el lugar en el arreglo y hacemos el corrimiento de los datos
    while(i>=0 && A[i].valor> a.valor){
        A[i+1]=A[i];
        i--;
    }

    /// insertamos en orden
    A[i+1]=a;

    return v+1;
}

/**
4) Esta función pide al usuario el ingreso de
los datos de un auto, crea un nodo y lo agrega al final de la lista (invocando a la función 2).
*/
void agregarMuchos(nodoAuto** lista)
{
    char opcion;
    stAuto a;

    nodoAuto* aux=NULL;

    do{
        system("cls");
        printf("\n Ingrese patente: ");
        fflush(stdin);
        scanf("%s",a.patente);

        printf("\n Ingrese valor: $ ");
        scanf("%d",&a.valor);

        printf("\n Ingrese marca: ");
        fflush(stdin);
        scanf("%s",a.marca);

        aux = crearNodo(a);
        agregarFinal(lista, aux);

        printf("\n ESC para salir .....  ");
        opcion=getch();
    }
    while(opcion != 27);
}

// aux

void mostrarUnAuto(stAuto a){
    printf("\n Patente......: %s", a.patente);
    printf("\n Valor........: %d", a.valor);
    printf("\n Marca........: %s", a.marca);
    printf("\n -------------------------------------------------");
}

void mostrarLista(nodoAuto* lista)
{
    if (lista)
    {
        mostrarUnAuto(lista->dato);
        mostrarLista(lista->siguiente);
    }
}

/**
5) Esta función pasa el contenido de
la lista al arreglo A de forma de crear un arreglo ordenado. Para ello debe recorrer
la lista e insertar los datos al arreglo usando la función 3.
*/
int pasar(nodoAuto* lista, stAuto A[])
{
    nodoAuto* seg=lista;
    int i =0;

    while(seg && i< DIM)
    {
        i = insertarCelda(A, seg->dato, i);
        seg = seg->siguiente;
    }

    return i;
}

/**
6) Muestra el arreglo en forma recursiva, desde la posición cero hasta la posición cant.
El parámetro i representa la posición actual del arreglo a mostrar.
*/
void mostrarArregloRecursivo(stAuto A[], int i, int cant)
{
    if(i<cant)
    {
        mostrarUnAuto(A[i]);
        mostrarArregloRecursivo(A, i+1, cant);
    }
}

/**
7) Hacer una función recursiva que sume el valor de los
vehículos de la lista que tengan patente “par”.
*/

int sumaValorListaR(nodoAuto* lista)
{
    int suma=0;
    if(lista){
        if(dameUltimoValorPatente(lista->dato.patente)%2==0){
            suma=lista->dato.valor+sumaValorListaR(lista->siguiente);
        }else{
            suma=sumaValorListaR(lista->siguiente);
        }
    }
    return suma;
}

int dameUltimoValorPatente(char patente[])
{
    /// Suponiendo que trabajamos con patentes con el siguiente formato: "AAA111"
    /// Podemos trasformar el ultimo caracter a un valor numerico, gracias a los códigos ASCII
    /// Si el último numero de la patente es par, su código ASCII también
    /// lo mismo para impar y lo mismo para letras

    int i=strlen(patente); ///leemos la cantidad de caracteres de la patente

    int num = (int) patente[i-1]-48; /// accedemos y transformamos en ASCII el último caracter

    return num;
}
