#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "animaciones.h"
#include "arboles.h"
#include "archivos.h"
#include "Filas.h"
#include "Lista_De_Listas.h"
#include "menuAdministrador.h"
#include "menuPrincipal.h"
#include "menuUsuario.h"
#include "Pila_Con_Listas_PS.h"
#include "publicacionMusical.h"
#include "usuarios.h"

int main()
{
    // Constantes para los archivos
    char archivoUsuarios[20] = "Usuarios.bin";
    char archivoRegistros[20] = "Registros.bin";

    animacionCargando();
    logos();
    logo6();
    system("pause");
    system("cls");
    menuPrincipal(archivoUsuarios, archivoRegistros);

    return 0;
}
