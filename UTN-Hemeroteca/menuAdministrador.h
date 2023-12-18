#ifndef MENUADMINISTRADOR_H_INCLUDED
#define MENUADMINISTRADOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "usuarios.h"

nodoListaUsuario *menuDeAdministradores(nodoListaUsuario *usuarioEncontrado, nodoListaUsuario *listaUsuarios, lista_de_listas *listaPrincipal, fila *fila, char archivoUsuarios[], char archivoRegistros[]);
#endif
