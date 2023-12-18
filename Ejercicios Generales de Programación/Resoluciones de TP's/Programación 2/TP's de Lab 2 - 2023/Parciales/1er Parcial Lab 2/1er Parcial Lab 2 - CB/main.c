#include <stdio.h>
#include <stdlib.h>

// ESTRUCTURAS:
typedef struct
{
    char nombre[50];
    char telefono[50];
    int DNI; // valores del 1 al 100
} stPersona;

typedef struct
{
    stPersona dato;
    struct nodoPersona *siguiente;
} nodoPersona;

typedef struct
{
    int DNI;
    int tipoContacto; // 1-familia 2-trabajo 3-amigos
    int activo;       // 1-true 0-false
} stContacto;

typedef struct nodoCliente
{
    stContacto dato;
    struct nodoContacto *siguiente;
    struct nodoContacto *anterior;
} nodoContacto;

// PROTOTIPADOS:

// Funciones Auxiliares:
nodoPersona *iniclistaPersona();
nodoContacto *iniclistaContacto();
// Ejercicio 1:
int verificarExistenciaDNIenLista(nodoPersona *, int);

// Ejercicio 2:
stPersona cargarDatosAPersona();
nodoPersona *crearNodoPersona(stPersona);

// Ejercicio 3:
void imprimir(nodoPersona *);
void mostrarListaPersonasRecursiva(nodoPersona *);

// Ejercicio 4:
nodoPersona *cargarUnoAlFinal(nodoPersona *, nodoPersona *);
nodoPersona *cargarMuchos(nodoPersona *);

// Ejercicio 5:
stContacto cargarDatosAContacto();
nodoContacto *crearNodoContacto(stContacto);
int verificarExistenciaDNIContactoEnListaPersonas(nodoPersona *, int);

// Ejercicio 6:
nodoContacto *cargarListaOrdenadPorDNI(nodoContacto *, nodoContacto *);
nodoContacto *cargarMuchosContactos(nodoContacto *, nodoPersona *);

// Ejercicio 7:
void imprimirContacto(nodoContacto *);
void mostrarListaContactosRecursiva(nodoContacto *);

// Ejercicio 8:
int contarCantidadActivosListaContactos(nodoContacto *);

int main()
{
    int opcion = 0;
    char continuar = 's';

    nodoPersona *listaPersona = iniclistaPersona();
    nodoContacto *listaContacto = iniclistaContacto();

    printf("Elija un ejercicio...\n");

    system("pause");
    system("cls");

    do
    {
        printf("1. Cargar lista de Personas. \n");
        printf("2. Mostrar lista de Personas. \n");
        printf("3. Cargar lista de Contactos. \n");
        printf("4. Mostrar lista de Contactos. \n");
        printf("5. Cantidad de contactos activos. \n");
        printf("6. Salir.");
        printf("\n");
        printf("Opcion: ");
        fflush(stdin);
        scanf("%i", &opcion);

        system("cls");

        switch (opcion)
        {
        case 1:
        {
            listaPersona = cargarMuchos(listaPersona);
            break;
        }
        case 2:
        {
            mostrarListaPersonasRecursiva(listaPersona);
            break;
        }
        case 3:
        {
            listaContacto = cargarMuchosContactos(listaContacto, listaPersona);
            break;
        }
        case 4:
        {
            mostrarListaContactosRecursiva(listaContacto);
            break;
        }
        case 5:
        {
            int suma = 0;
            suma = contarCantidadActivosListaContactos(listaContacto);
            printf("Hay un total de %i contacto(s) activo(s). \n", suma);
            break;
        }
        case 6:
        {
            printf("Saliendo...\n");
            break;
        }
        default:
        {
            printf("Opcion no valida. Saliendo...");
            break;
        }
        }

        system("pause");
        fflush(stdin);
        printf("Desea volver al menu principal?: s/n\n");
        scanf("%c", &continuar);
        system("cls");

    } while ((continuar == 's' || continuar == 'S'));
}

// FUNCIONES AUXILIARES:
nodoPersona *iniclistaPersona()
{
    return NULL;
}

nodoContacto *iniclistaContacto()
{
    return NULL;
}

// EJERCICIO 1:
int verificarExistenciaDNIPersonaEnLista(nodoPersona *lista, int dniABuscar)
{
    int rta;
    nodoPersona *seg = lista;

    if (lista == NULL) // Caso base, se asigna 0 a rta. O sea, el DNI de la persona que esta siendo ingresada a la lista NO SE ENCUNTRA REGISTRADO..
    {
        rta = 0;
    }
    else
    {
        if (seg->dato.DNI == dniABuscar) // Si lo encuentra, se asigna 1 a rta. O sea, el DNI de la persona que esta siendo ingresada a la lista YA SE ENCUNTRA REGISTRADO.
        {
            rta = 1;
        }
        else
        {
            rta = verificarExistenciaDNIPersonaEnLista(seg->siguiente, dniABuscar);
        }
    }

    return rta;
}

// EJERCICIO 2:
stPersona cargarDatosAPersona()
{
    stPersona datosPersona;
    printf("Ingrese los datos de la persona: \n");
    printf("NOMBRE: ");
    fflush(stdin);
    scanf("%s", datosPersona.nombre);

    printf("TELEFONO: ");
    fflush(stdin);
    scanf("%s", datosPersona.telefono);

    datosPersona.DNI = 0;

    while ((datosPersona.DNI < 1) || (datosPersona.DNI > 100)) // Verifica el rango del DNI...
    {
        printf("DNI: ");
        fflush(stdin);
        scanf("%i", &datosPersona.DNI);

        if ((datosPersona.DNI < 1) || (datosPersona.DNI > 100))
        {
            printf("Error: rango del DNI no aceptado. \n");
        }
    }
    return datosPersona;
}

nodoPersona *crearNodoPersona(stPersona datos)
{
    nodoPersona *aux = (nodoPersona *)malloc(sizeof(nodoPersona));

    aux->dato = datos;
    aux->siguiente = NULL;

    return aux;
}

// EJERCICIO 3:
void imprimir(nodoPersona *lista)
{
    printf("NOMBRE: %s\n", lista->dato.nombre);
    printf("TELEFONO: %s\n", lista->dato.telefono);
    printf("DNI: %i\n", lista->dato.DNI);
}

void mostrarListaPersonasRecursiva(nodoPersona *lista)
{
    if (lista != NULL)
    {
        imprimir(lista);
        mostrarListaPersonasRecursiva(lista->siguiente); // Se imprime recursivamente la lista de principio a fin (o de izquierda a derecha).
    }
}

// EJERCICIO 4:
nodoPersona *cargarUnoAlFinal(nodoPersona *lista, nodoPersona *nuevoNodo)
{
    if (lista == NULL) // Si la lista esta vacia....
    {
        lista = nuevoNodo;
    }
    else // Si la lista tiene al menos 1 elemento...
    {
        nodoPersona *ante;
        nodoPersona *seg = lista;

        while (seg->siguiente != NULL)
        {
            ante = seg;
            seg = seg->siguiente;
        }

        seg->siguiente = nuevoNodo;
    }

    return lista;
}

nodoPersona *cargarMuchos(nodoPersona *lista)
{
    int flag = 0;
    char continuar = 's';

    do
    {
        stPersona persona = cargarDatosAPersona();
        nodoPersona *aux = crearNodoPersona(persona);
        flag = verificarExistenciaDNIPersonaEnLista(lista, aux->dato.DNI);

        if (flag == 1)
        {
            printf("El DNI a ingresar ya se encuentra en la lista. \n");
        }
        else
        {
            lista = cargarUnoAlFinal(lista, aux);
        }

        printf("Desea seguir cargando personas a su respectiva lista?: s/n\n");
        fflush(stdin);
        scanf("%c", &continuar);

    } while ((continuar == 's') || (continuar == 'S'));

    return lista;
}

// EJERCICIO 5:
stContacto cargarDatosAContacto()
{
    int flag = 0;
    stContacto datosContacto;
    printf("Ingrese los datos del contacto: \n");
    printf("DNI: ");
    fflush(stdin);
    scanf("%i", &datosContacto.DNI);

    printf("TIPO DE CONTACTO (1, 2 o 3): ");
    fflush(stdin);

    datosContacto.tipoContacto = 0;

    while ((datosContacto.tipoContacto != 1) && (datosContacto.tipoContacto != 2) && (datosContacto.tipoContacto != 3)) // Verifica que el tipo de contacto sea uno de los 3 permitidos...
    {
        scanf("%i", &datosContacto.tipoContacto);

        if ((datosContacto.tipoContacto != 1) && (datosContacto.tipoContacto != 2) && (datosContacto.tipoContacto != 3))
        {
            printf("Error: tipo de contacto no permitido. Ingreselo nuevamente: \n");
        }
    }

    printf("ACTIVO (1 = activo) - (0 = inactivo): ");
    fflush(stdin);

    datosContacto.activo = 2;

    while ((datosContacto.activo != 1) && (datosContacto.activo != 0))
    {
        scanf("%i", &datosContacto.activo);

        if ((datosContacto.activo != 1) && (datosContacto.activo != 0))
        {
            printf("Error: Debe seleccionar o 1 o 0 (cero) para marcar si el contacto actual se encuentra activo o no. \n");
        }
    }

    return datosContacto;
}

nodoContacto *crearNodoContacto(stContacto datos)
{
    nodoContacto *aux = (nodoContacto *)malloc(sizeof(nodoContacto));

    aux->dato = datos;
    aux->anterior = NULL;
    aux->siguiente = NULL;

    return aux;
}

int verificarExistenciaDNIContactoEnListaPersonas(nodoPersona *lista, int dniABuscar)
{
    int rta;
    nodoPersona *seg = lista;

    if (lista == NULL) // Caso base, se asigna 0 a rta. O sea, el DNI de la persona que esta siendo ingresada a la lista NO SE ENCUENTRA REGISTRADO..
    {
        rta = 0;
    }
    else
    {
        if (seg->dato.DNI == dniABuscar) // Si lo encuentra, se asigna 1 a rta. O sea, el DNI de la persona que esta siendo ingresada a la lista YA SE ENCUNTRA REGISTRADO.
        {
            rta = 1;
        }
        else
        {
            rta = verificarExistenciaDNIContactoEnListaPersonas(seg->siguiente, dniABuscar);
        }
    }

    return rta;
}

// EJERCICIO 6:
nodoContacto *cargarListaOrdenadPorDNI(nodoContacto *lista, nodoContacto *nuevoNodo)
{
    if (lista == NULL) // Si la lista esta vacia...
    {
        lista = nuevoNodo;
    }
    else // Si tiene al menos un elemento...
    {
        nodoContacto *ante;
        nodoContacto *seg = lista;

        if (nuevoNodo->dato.DNI < seg->dato.DNI) // Si el dato.dni del nodo a insertar es menor al dato.dni del primer nodo...
        {
            nuevoNodo->siguiente = seg;
            seg->anterior = nuevoNodo;
            lista = nuevoNodo;
        }
        else // Si el nodo nuevo se lo debe insertar en el medio o final de la lista....
        {
            while ((seg != NULL) && (nuevoNodo->dato.DNI > seg->dato.DNI)) // Busca el hueco para insertar segun el valor del campo DNI...
            {
                ante = seg;
                seg = seg->siguiente;
            }

            ante->siguiente = nuevoNodo;
            nuevoNodo->anterior = ante;
            nuevoNodo->siguiente = seg;
        }
    }

    return lista;
}

nodoContacto *cargarMuchosContactos(nodoContacto *lista, nodoPersona *listaAux)
{
    int flag = 0;
    char continuar = 's';

    do
    {
        stContacto contacto = cargarDatosAContacto();
        nodoContacto *aux = crearNodoContacto(contacto);
        flag = verificarExistenciaDNIContactoEnListaPersonas(listaAux, aux->dato.DNI); // Verifica que el DNI del contacto no se encuentre ya registrado en la lista de personas...

        if (flag == 1)
        {
            printf("El DNI a ingresar ya se encuentra en la lista. \n");
        }
        else
        {
            lista = cargarListaOrdenadPorDNI(lista, aux);
        }

        printf("Desea seguir cargando contactos a su respectiva lista?: s/n\n");
        fflush(stdin);
        scanf("%c", &continuar);

    } while ((continuar == 's') || (continuar == 'S'));

    return lista;
}

// EJERCICIO 7:
void imprimirContacto(nodoContacto *lista)
{
    printf("DNI: %i\n", lista->dato.DNI);
    printf("TIPO DE CONTACTO: %i\n", lista->dato.tipoContacto);
    printf("ACTIVO: %i\n", lista->dato.activo);
}

void mostrarListaContactosRecursiva(nodoContacto *lista)
{
    if (lista != NULL)
    {
        mostrarListaContactosRecursiva(lista->siguiente); // Muestra la lista de contactos recursivamente desde el final hasta el principio (o de derecha a izquierda)...
        imprimirContacto(lista);
    }
}

// EJERCICIO 8
int contarCantidadActivosListaContactos(nodoContacto *lista)
{
    int cantActivos = 0;
    nodoContacto *seg = lista;

    while (seg != NULL)
    {
        if (seg->dato.activo == 1) // Suma aquellos que solo sean contactos activos...
        {
            cantActivos++;
            seg = seg->siguiente;
        }
        else
        {
            seg = seg->siguiente;
        }
    }

    return cantActivos;
}
