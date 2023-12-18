#include "nodoAlumno.h"
#include <stdio.h>
#include <stdlib.h>

nodo*crearnodoAlumno()
{
    nodo*aux=(nodo*)malloc(sizeof(nodo));
    alumno auxAlumno = cargaralumno();
    aux->mialumno=auxAlumno;
    aux->sig=NULL;
    return aux;
}

alumno cargaralumno()
{
    alumno mialumno;
    printf("Ingrese el nombre: \n");
    fflush(stdin);
    gets(mialumno.nombre);
    printf("Ingrese legajo: \n");
    scanf("%i",&mialumno.legajo);
    printf("Ingrese nota: \n");
    scanf("%i",&mialumno.nota);

    return mialumno;
}

nodo*iniclista()
{
    return NULL;
}

nodo*agregarppio(nodo*lista,nodo*na)
{
    if (lista==NULL)
    {
        lista=na;
    }
    else
    {
        na->sig=lista;
        lista=na;
    }
    return lista;
}

void mostrarlistaAlumno(nodo*lista)
{
    nodo*seg=lista;
    while(seg!=NULL)
    {
        printf("Nombre: ");
        puts(seg->mialumno.nombre);
        printf("Legajo: %i\n", seg->mialumno.legajo);
        printf("Nota: %i\n", seg->mialumno.nota);
        seg=seg->sig;
    }
}

void mostrarnodoAlumno(nodo*lista)
{
    nodo*seg=lista;
    while(seg!=NULL)
    {
        alumno auxAlumno=seg->mialumno;
        printf("%i", auxAlumno.nota);
    }
    seg->mialumno.nota;
}

nodo*agregarordenado(nodo*lista,nodo*na)
{
    if (lista==NULL)
    {
        lista=na;
    }
    else if (lista->mialumno.legajo > na->mialumno.legajo)
    {
        lista=agregarppio(lista,na);
    }
    else
    {
        nodo*ante=lista;
        nodo*seg=lista;
        while((seg!=NULL) && (seg->mialumno.legajo < na->mialumno.legajo))
        {
            ante=seg;
            seg=seg->sig;
        }
        ante->sig=na;
        na->sig=seg;
    }
    return lista;
}

//nodo*agregaralfinal(nodo*lista,nodo*na)
//{
//    if (lista==NULL)
//    {
//        lista=na;
//    }
//    else
//    {
//        nodo*ulti=buscarultimo(lista);
//        ulti->sig=na;
//    }
//    return lista;
//
//}

//nodo*buscarultimo(nodo*lista)
//{
//    nodo*seg=lista;
//    if(lista!=NULL)
//    {
//        while(seg->sig!=NULL && seg->dato!=dato)
//        {
//            seg=seg->sig;
//        }
//        ulti=seg;
//    }
//    if (seg->dato!=dato)
//	{
//		seg=NULL;
//	}
//    return seg;
//}


nodo*buscarnodo(int dato,nodo*lista)
{
	nodo*ulti=lista;
    nodo*seg=lista;
    if(lista!=NULL)
    {
        while((seg->sig!=NULL) && (seg->mialumno.legajo!=dato))
        {
            seg=seg->sig;
        }
    }
    if (seg->mialumno.legajo!=dato)
	{
		seg=NULL;
	}
	else
	{
		printf("Se encontro\n");
		printf("Nombre: ");
        puts(seg->mialumno.nombre);
        printf("Legajo: %i\n", seg->mialumno.legajo);
        printf("Nota: %i\n", seg->mialumno.nota);
        seg=seg->sig;
	}

    return seg;
}


