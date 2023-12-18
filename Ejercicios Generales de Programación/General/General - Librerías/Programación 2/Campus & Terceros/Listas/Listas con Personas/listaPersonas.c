#include "listaPersonas.h"

/**********************************************/
/** \brief Inicializa la lista "vacía".       */
/** \param no necesita parámetros.            */
/** \return puntero a NULL.                   */
/**********************************************/

/** NOTA: retornar NULL, es como decir que la lista inicialize "vacía". */

/* retorna el puntero a NULL */
nodo* iniciarLista()
{
    return NULL;
}

/**********************************************/
/** \brief Carga una lista.                   */
/** \param puntero de tipo NODO.              */
/** \return puntero de tipo NODO modificado.  */
/**********************************************/

/** NOTA: El último dato ingresado, se convierte en el inicio de la lista.  */

/* carga la lista */
nodo* cargarLista(nodo* lista)
{
    stPersona persona;
    nodo* nuevoNodo;
    char seguir = 's';

    while(seguir == 's'){
        system("cls");

        printf(" CARGANDO LISTA... \n\n");

        persona = cargarUnaPersona(persona);
        nuevoNodo = crearNodo(persona);
        lista = addPrincipioLista(lista , nuevoNodo);

        printf("\n %cQuieres cargar otra persona? s=SI / n=NO ", 168);
        fflush(stdin);
        seguir = getch();
        printf("\n\n");
    }

    return lista;

}

/**********************************************/
/** \brief Carga una lista ordenada.          */
/** \param puntero de tipo NODO.              */
/** \return puntero de tipo NODO modificado.  */
/**********************************************/

/* cargar lista ordenada */
nodo* cargarListaOrdenada(nodo* lista)
{
    stPersona persona;
    nodo* nuevoNodo;
    char seguir = 's';

    while(seguir == 's'){
        system("cls");

        printf(" CARGANDO LISTA... \n\n");

        persona = cargarUnaPersona(persona);
        nuevoNodo = crearNodo(persona);
        lista = insertarOrdenado(lista , nuevoNodo);

        printf("\n %cQuieres cargar otra persona? s=SI / n=NO ", 168);
        fflush(stdin);
        seguir = getch();
        printf("\n\n");
    }

    return lista;

}

/**********************************************/
/** \brief Crear un nodo.                     */
/** \param variable de tipo STRUCT.           */
/** \return variable de tipo NODO.            */
/**********************************************/

/* crea un nuevo nodo */
nodo* crearNodo(stPersona persona)
{
    nodo* aux;

    aux = (nodo*)malloc(sizeof(nodo)); /* malloc reserva espacio de memoría en tiempo de ejecución */

    aux->datos = persona;
    aux->siguiente = NULL;

    return aux;
}

/**********************************************/
/** \brief Agrega al principio de la lista.   */
/** \param puntero de tipo NODO.              */
/** \param puntero de tipo NODO.              */
/** \return puntero de tipo NODO modificado.  */
/**********************************************/

/** NOTA: Cada nodo se va a agregando al principio de la lista. */
/**       El último nodo agregando va a hacer el nuevo inicio de la lista.*/

/* agrega el nodo al principio de la lista */
nodo* addPrincipioLista(nodo* lista , nodo* nuevoNodo)
{
    if(lista == NULL){
        lista = nuevoNodo; // si la lista está vacía, se agrega directamente al principio
    }else{
        nuevoNodo->siguiente = lista; // si la lista ya tiene datos, el nuevo nodo pasa a apuntar al dato que estaba al principio.
        lista = nuevoNodo;  // lista pasa a apuntar al nuevo nodo ingresado y pasa a ser el nuevo inicio de la lista.
    }

    return lista;
}

/**********************************************/
/** \brief Mostrar lista.                     */
/** \param puntero de tipo NODO.              */
/**********************************************/

/* muestra la lista */
void mostrarLista(nodo* lista)
{
    int numPersona = 0;
    nodo* seguidor = lista;

    while(seguidor != NULL){
        printf(" Persona N%c%d \n" , 248 , numPersona+1);

        mostrarUnaPersona(seguidor->datos);
        seguidor = seguidor->siguiente;
        numPersona++;
    }
}

/**********************************************/
/** \brief Verifica si existe la persona.     */
/** \param puntero de tipo NODO.              */
/** \param String.                            */
/** \return 1 ó 0. 1 si existe - 0 no existe. */
/**********************************************/

int verificaSiExistePersona(nodo* lista , char nombre[])
{
    int flag = 0;
    nodo* seguidor = lista;

    while((seguidor != NULL) && (flag == 0)){
        if(strcmpi(seguidor->datos.nombre , nombre) == 0){
            flag = 1; // retorna 1 si la persona se encuentra en la lista.
        }else{
            seguidor = seguidor->siguiente;
        }
    }

    return flag;
}


stPersona buscarPersona(nodo* lista , char nombre[])
{
    stPersona personaEncontrada;
    nodo* seguidor = lista;
    int flag = 0;

    while((flag == 0) && (seguidor != NULL)){  // se usa una variable de control para la condición de corte.
        if(strcmpi(seguidor->datos.nombre , nombre) == 0){
            flag = 1;
            personaEncontrada = seguidor->datos;
        }else{
            seguidor = seguidor->siguiente;
        }
    }

    return personaEncontrada;
}

/**********************************************/
/** \brief Insertar dato conservando orden.   */
/** \param puntero de tipo NODO.              */
/** \param puntero de tipo NODO.              */
/** \return puntero de tipo NODO modificado.  */
/**********************************************/

/** NOTA: Va insertando el dato conservando el orden utilizando 2 punteros de tipo NODO, en caso de que la lista tenga datos. */

/* inserta un nodo en una lista ordenada */
nodo* insertarOrdenado(nodo* lista , nodo* nuevoNodo)
{
    nodo* ante;
    nodo* seguidor;

    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        if(strcmp(nuevoNodo->datos.nombre , lista->datos.nombre) < 0){
            lista = addPrincipioLista(lista , nuevoNodo);
        }else{
            ante = lista;
            seguidor = lista->siguiente;

            while((seguidor != NULL) && (strcmp(nuevoNodo->datos.nombre , seguidor->datos.nombre) >= 0)){
                ante = seguidor;
                seguidor = seguidor->siguiente;
            }

            nuevoNodo->siguiente = seguidor;
            ante->siguiente = nuevoNodo;
        }
    }

    return lista;
}

/*************************************************/
/** \brief Pasar datos del archivo a una lista.  */
/** \param String (Nombre del archivo).          */
/** \param puntero de tipo NODO.                 */
/** \return puntero de tipo NODO modificado.     */
/*************************************************/

/** NOTA: A medida que va leyendo el archivo, lo va insertando en la lista. */

/* pasa los datos de un archivo a una lista sin ordenar */
nodo* pasarArchivoToLista(char nombreArchivo[] , nodo* lista)
{
    FILE *pArchivo;
    stPersona aux;
    nodo* nodoNuevo;

    pArchivo = fopen(nombreArchivo , "rb");

    if(pArchivo != NULL){
        while(fread(&aux , sizeof(stPersona) , 1 , pArchivo) > 0){
            nodoNuevo = crearNodo(aux);
            lista = addFinalLista(lista , nodoNuevo);
        }
        fclose(pArchivo);
    }else{
        printf(" ERROR en la lectura del archivo. \n\n");
    }

    return lista;
}

/**********************************************************/
/** \brief Pasar datos del archivo a una lista en orden.  */
/** \param String (Nombre del archivo).                   */
/** \param puntero de tipo NODO.                          */
/** \return puntero de tipo NODO modificado.              */
/**********************************************************/

/** NOTA: A medida que va leyendo el archivo, compara que dato es menor, luego lo va insertando a la lista en orden. */
/**       En este caso se va a ordenar por NOMBRE. */

/* pasar los datos de un archivo a una lista de forma ordenada */
nodo* pasarArchivoToListaOrdenado(char nombreArchivo[] , nodo* lista)
{
    stPersona aux;
    nodo* nodoRecepor;
    FILE *pArchivo;

    pArchivo = fopen(nombreArchivo , "rb");

    if(pArchivo != NULL){
        while(fread(&aux , sizeof(stPersona) , 1 , pArchivo) > 0){
            nodoRecepor = crearNodo(aux);
            lista = insertarOrdenado(lista , nodoRecepor);
        }
        fclose(pArchivo);
    }else{
        printf(" ERROR en la apertura del archivo... \n\n");
    }

    return lista;
}

/**********************************************/
/** \brief Agregar dato al final de la lista. */
/** \param puntero de tipo NODO.              */
/** \param puntero de tipo NODO.              */
/** \return Puntero de tipo NODO modificado.  */
/**********************************************/

/** NOTA: Retorna la lista modficada. */

/* agrega un dato al final de la lista */
nodo* addFinalLista(nodo* lista , nodo* nuevoNodo)
{
    nodo* ultimoNodo;

    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        ultimoNodo = buscarUltimoNodo(lista);
        ultimoNodo->siguiente = nuevoNodo;
    }

    return lista;
}

/**********************************************/
/** \brief Buscar el último dato de la lista. */
/** \param puntero de tipo NODO.              */
/** \return Puntero de tipo NODO.             */
/**********************************************/

/** NOTA: Retrona la estructura que se encuentra al final de la lista.
          Utilizamos un puntero auxiliar para no modificar el puntero del inicio de la lista. */

/* buscar el ultimo dato de la lista */
nodo* buscarUltimoNodo(nodo* lista)
{
    nodo* seguidor = lista;

    while(seguidor->siguiente != NULL){
        seguidor = seguidor->siguiente;
    }

    return seguidor;
}

/*************************************************/
/** \brief Intercarlar listas ordenadas.         */
/** \param Puntero de tipo NODO                  */
/** \param Puntero de tipo NODO.                 */
/** \param Puntero de tipo NODO.                 */
/** \return Puntero de tipo NODO modificado.     */
/*************************************************/

/* intercalar 2 listas ordenadas */
nodo* intercalarListasOrdenadas(nodo* lista1 , nodo* lista2 , nodo* listaDestino)
{
    nodo* aux;

    while((lista1 != NULL) && (lista2 != NULL)){
        if(lista1->datos.edad <= lista2->datos.edad){
            aux = lista1;
            lista1 = lista1->siguiente;
        }else{
            aux = lista2;
            lista2 = lista2->siguiente;
        }

        aux->siguiente = NULL;
        listaDestino = addFinalLista(listaDestino , aux);
    }

    if(lista1 != NULL){
        listaDestino = addFinalLista(listaDestino , lista1);
    }else if(lista2 != NULL){
        listaDestino = addFinalLista(listaDestino , lista2);
    }

    return listaDestino;
}

/*************************************************/
/** \brief Borrar persona de la lista.           */
/** \param Puntero de tipo NODO.                 */
/** \param String (nombre de la persona).        */
/** \return Puntero al inicio de la lista.       */
/*************************************************/

/* borrar una persona de la lista */
nodo* borrarPersona(nodo* lista , char nombre[])
{
    nodo* ante;
    nodo* seguidor;

    if(lista != NULL && strcmp(lista->datos.nombre , nombre) == 0){
        seguidor = lista;
        lista = lista->siguiente;
        free(seguidor);
    }else{
        seguidor = lista;
        while((seguidor != NULL) && (strcmp(seguidor->datos.nombre , nombre) != 0)){
            ante = seguidor;
            seguidor = seguidor->siguiente;
        }

        if(seguidor != NULL){
            ante->siguiente = seguidor->siguiente;
            free(seguidor);
        }
    }else{
        printf(" La persona no se encuentra en la lista. \n\n");
    }

    return lista;
}

nodo* borrarLista(nodo* lista)
{
    nodo* seguidor;

    if(lista->siguiente == NULL){
        seguidor = lista;
        free(lista);
    }else{
        while(lista != NULL){
            seguidor = lista;
            lista = lista->siguiente;
            free(seguidor);
        }
    }


    return lista;
}

/**********************************************/
/** \brief Invierte una lista.                */
/** \param puntero de tipo NODO.              */
/** \return puntero de tipo NODO modificado.  */
/**********************************************/

/* invierte una lista */
nodo* invertirLista(nodo* lista)
{
    nodo* aux;
    nodo* listaInvertida;

    listaInvertida = iniciarLista();

    while(lista != NULL){
        aux = lista;
        lista = lista->siguiente;
        aux->siguiente = NULL;
        listaInvertida = addPrincipioLista(listaInvertida , aux);
    }

    return listaInvertida;
}

/* modifica una persona */
nodo* modificarPersona(nodo* lista , char nombre[])
{
    nodo* seguidor = lista;
    stPersona aux;
    stPersona personaEncontrada;
    int existePersona = 0;
    int flag = 0;

    existePersona = verificaSiExistePersona(lista , nombre);

    if(existePersona == 1){
        system("cls");

        personaEncontrada = buscarPersona(lista , nombre);

        printf(" Los datos de %s son: \n\n" , nombre);
        mostrarUnaPersona(personaEncontrada);

        system("pause");
        system("cls");

        printf(" Ingresar nuevo nombre: ");
        fflush(stdin);
        gets(aux.nombre);

        printf(" Ingresar nueva edad: ");
        scanf("%d" , &aux.edad);

        while((flag == 0) && (seguidor != NULL)){
            if(strcmp(seguidor->datos.nombre , nombre) == 0){
                seguidor->datos = aux;
            }else{
                seguidor = seguidor->siguiente;
            }
        }

    }else{
        printf(" La persona no se encuentra en la lista. \n\n");
    }

    return lista;

}

/* ------------------------------------------ FUNCIONES AUXILIARES ------------------------------------------ */

/*************************************************/
/** \brief Carga de una persona.                 */
/** \param Variable de tipo STRUCT.              */
/** \return Variable de tipo STRUCT modificada.  */
/*************************************************/

/* carga una persona */
stPersona cargarUnaPersona(stPersona persona)
{
     printf(" Ingresar nombre: ");
     fflush(stdin);
     gets(persona.nombre);

     printf(" Ingresar edad: ");
     scanf("%d" , &persona.edad);

     return persona;
}

/*************************************************/
/** \brief Mostrar una persona.                  */
/** \param Variable de tipo STRUCT.              */
/*************************************************/

/* muestra una persona */
void mostrarUnaPersona(stPersona persona)
{
    printf(" ----------------------- \n");
    printf(" Nombre: %s \n" , persona.nombre);
    printf(" Edad  : %d \n" , persona.edad);
    printf(" ----------------------- \n\n");
}
