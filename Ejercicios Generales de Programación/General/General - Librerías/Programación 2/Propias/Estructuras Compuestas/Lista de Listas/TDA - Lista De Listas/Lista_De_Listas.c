#include "Lista_De_Listas.h"

nodo_lista_simple * inicSubLista()
{
    return NULL;
}

nodo_lista_simple_principal * inicListaCaja()
{
    return NULL;
}

nodo_lista_simple * crearNodoSublista(persona dato)
{
    nodo_lista_simple * aux = (nodo_lista_simple*)malloc(sizeof(nodo_lista_simple));

    aux->dato= dato;
    aux->siguiente = NULL;

    return aux;
}

nodo_lista_simple_principal * crearNodoCaja(caja dato)
{
    nodo_lista_simple_principal * aux = (nodo_lista_simple_principal*)malloc(sizeof(nodo_lista_simple));

    aux->dato = dato;
    aux->listaClientes = inicListaCaja();
    aux->siguiente = NULL;

    return aux;
}

nodo_lista_simple_principal * buscarCaja(nodo_lista_simple_principal * lista, int nroCaja)
{
    nodo_lista_simple_principal* seg = lista;
    nodo_lista_simple_principal *cajaEncontrada = NULL;
    int flag = 0;

    while((seg!= NULL) && (flag == 0))
    {
        if(seg->dato.nroCaja == nroCaja)
        {
            cajaEncontrada = seg;
            flag=1;
        }

        seg = seg->siguiente;
    }
    return cajaEncontrada;
}

caja ingresarCaja(int nroCaja)
{
    caja dato;

    dato.nroCaja = nroCaja;
    printf("Ingresar Medio de Pago: \n");
    fflush(stdin);
    scanf("%s", dato.medio_Pago);

    return dato;
}

nodo_lista_simple_principal * agregarPpioCaja(nodo_lista_simple_principal * lista, nodo_lista_simple_principal * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}

nodo_lista_simple * agregarFinal(nodo_lista_simple * lista, nodo_lista_simple * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodo_lista_simple *seg = lista;

        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }

        seg->siguiente = nuevoNodo;
    }
    return lista;
}

nodo_lista_simple_principal * alta (nodo_lista_simple_principal *listaCajas, nodo_lista_simple * nuevoCliente, int nroCaja)
{
    nodo_lista_simple_principal *cajaEncontrada = buscarCaja(listaCajas,nroCaja);

    if(cajaEncontrada==NULL)
    {
        caja c = ingresarCaja(nroCaja);
        nodo_lista_simple_principal *nuevaCaja = crearNodoCaja(c);
        listaCajas = agregarPpioCaja(listaCajas, nuevaCaja);
        listaCajas->listaClientes = agregarFinal(listaCajas->listaClientes, nuevoCliente);
    }
    else
    {
        cajaEncontrada->listaClientes = agregarFinal(cajaEncontrada->listaClientes, nuevoCliente);
    }

    return listaCajas;
}

nodo_lista_simple_principal *ingresarCajas(nodo_lista_simple_principal *lista)
{
    char continuar = 's';
    persona p;
    int nroDeCaja;

    while (continuar == 's')
    {
        printf("\nIngresar Nro de Cliente:  ");
        fflush(stdin);
        scanf("%d", &p.nroCliente);

        printf("\nIngresar NOMBRE Y APELLIDO del Cliente:  ");
        fflush(stdin);
        gets(p.nombre_apellido);

        printf("\nIngresar CANTIDAD DE Producto:  ");
        fflush(stdin);
        scanf("%d", &p.cantProductos);

        printf("\nA QUE NUMERO DE CAJA DESEA INGRESAR EL CLIENTE?  \n");
        fflush(stdin);
        scanf("%d", &nroDeCaja);

        nodo_lista_simple *cliente = crearNodoSublista(p);
        lista = alta(lista, cliente, nroDeCaja);

        printf("\n\nDesea continuar presione s:  ");
        fflush(stdin);
        scanf("%c", &continuar);
        printf("\n\n");
    }
    return lista;
}

void recorrerYmostrarCajasClientes(nodo_lista_simple_principal *lista)
{
    nodo_lista_simple_principal *seg = lista;

    while(seg != NULL)
    {
        printf("Numero de caja: %i\n", seg->dato.nroCaja);
        printf("Medio de pago: %s\n", seg->dato.medio_Pago);

        nodo_lista_simple *segAux = seg->listaClientes;

        while(segAux != NULL)
        {
            printf("Nombre: %s\n", segAux->dato.nombre_apellido);
            printf("Cantidad de productos: %i\n", segAux->dato.cantProductos);
            segAux = segAux->siguiente;
        }

        seg = seg->siguiente;
    }
}
