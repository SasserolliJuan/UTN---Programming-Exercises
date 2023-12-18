#ifndef NODOALUMNO_H_INCLUDED
#define NODOALUMNO_H_INCLUDED

typedef struct
{
	char nombre[50];
	int nota;
	int legajo;
}alumno;

typedef struct
{
	alumno mialumno;
	struct nodo*sig;
}nodo;

nodo*crearnodoAlumno();
alumno cargaralumno();
nodo*iniclista();
nodo*agregarppio(nodo*lista,nodo*na);
void mostrarlistaAlumno(nodo*lista);
void mostrarnodoAlumno(nodo*lista);
nodo*agregarordenado(nodo*lista,nodo*na);
nodo*agregaralfinal(nodo*lista,nodo*na);
nodo*buscarultimo(nodo*lista);
nodo*buscarnodo(int dato,nodo*lista);


#endif // NODOALUMNO_H_INCLUDED
