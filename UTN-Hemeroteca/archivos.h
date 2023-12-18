#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// Usuario
Usuario cargarDatosUnUsuario();
Usuario cargarDatosUnAdmin(char contraAdmin[]);
void cargarArchivoUsuarios(char archivoUsuarios[]);
int comprobarExistenciaIDUsuario(FILE *archivo, int i);
void cargarArchivoUsuariosAdmins(char archivoUsuarios[], char contraAdmin[]);
void mostrarArchivoUsuarios(char archivoUsuarios[]);
void mostrarUnUsuario(Usuario dato);

// Registro musical
datosCadaPublicacion pedirDatosRegistro();
void cargarArchivoPublicacion(char archivoRegistros[]);
void mostrarUnaPublicacion(datosCadaPublicacion dato);
void mostrarUnaPublicacion2(datosCadaPublicacion dato);
void mostrarArchivoPublicacion(char archivoRegistros[]);

// Funciones de mostrado
lista_de_listas *mostrarPublicacionXTitulo(lista_de_listas *listaPublicaciones, char tituloABuscar[]);
lista_de_listas *mostrarPublicacionXAutor(lista_de_listas *listaPublicaciones, char autorABuscar[]);
lista_de_listas *mostrarPublicacionXFecha(lista_de_listas *listaPublicaciones, int anio1, int anio2);
lista_de_listas *mostrarPublicacionXPalabraClave(lista_de_listas *listaPublicaciones, char palabraClave[]);
void actualizarInformacionPublicacion(char registroArchivos[], int posicion);
int buscarRegistro(char nombreArchivo[], char tituloBuscar[]);
void imprimirAutor(datosCadaPublicacion autor);
void mostrarDatosAutorXNacionalidad(char archivoRegistros[], char nacionalidad[]);
void mostrarDatosAutorXNombre(char archivoRegistros[], char autorABuscar[]);
int borrarUnaPublicacionXAutor(char archivoRegistros[], char autorABorrar[]);
int borrarUnaPublicacionXTitulo(char archivoRegistros[], char tituloABorrar[]);
void agregarOpinion(datosCadaPublicacion *registro);
void buscarParaComentar(char archivoRegistros[], char tituloBuscado[]);
void conocerOpiniones(datosCadaPublicacion registro);

#endif
