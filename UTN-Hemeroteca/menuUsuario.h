#ifndef MENUUSUARIO_H_INCLUDED
#define MENUUSUARIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

nodoListaUsuario *menuUsuario(nodoListaUsuario *usuarioEncontrado, nodoListaUsuario *listaUsuarios, lista_de_listas *listaPrincipal, fila *fila, char archivoUsuarios[], char archivoRegistros[]);

#endif
