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

// --- USUARIO --- //

Usuario cargarDatosUnUsuario()
{
    Usuario aux;
    char contraProhibida[12] = "admin";

    printf("Ingrese su nombre completo: ");
    fflush(stdin);
    fgets(aux.nombreCompleto, sizeof(aux.nombreCompleto), stdin);
    aux.nombreCompleto[strcspn(aux.nombreCompleto, "\r\n")] = '\0';

    printf("Ingrese su e-mail: ");
    fflush(stdin);
    fgets(aux.mail, sizeof(aux.mail), stdin);
    aux.mail[strcspn(aux.mail, "\r\n")] = '\0';

    printf("Ingrese su genero preferido: ");
    fflush(stdin);
    fgets(aux.generoPreferido, sizeof(aux.generoPreferido), stdin);
    aux.generoPreferido[strcspn(aux.generoPreferido, "\r\n")] = '\0';

    printf("Ingrese su contrase%ca: ", 164);
    fflush(stdin);
    fgets(aux.contrasenia, sizeof(aux.contrasenia), stdin);
    aux.contrasenia[strcspn(aux.contrasenia, "\r\n")] = '\0'; // Elimina el caracter de nueva linea

    while (strcmpi(aux.contrasenia, contraProhibida) == 0)
    {
        printf("Error: contrase%ca no valida. Elija otra. \n", 164);
        fflush(stdin);
        fgets(aux.contrasenia, sizeof(aux.contrasenia), stdin);
        aux.contrasenia[strcspn(aux.contrasenia, "\r\n")] = '\0'; // Elimina el caracter de nueva linea
    }

    return aux;
}

Usuario cargarDatosUnAdmin(char contraAdmin[])
{
    Usuario admin;

    printf("Ingrese su nombre completo: ");
    fflush(stdin);
    fgets(admin.nombreCompleto, sizeof(admin.nombreCompleto), stdin);
    admin.nombreCompleto[strcspn(admin.nombreCompleto, "\r\n")] = '\0';

    printf("Ingrese su e-mail: ");
    fflush(stdin);
    fgets(admin.mail, sizeof(admin.mail), stdin);
    admin.mail[strcspn(admin.mail, "\r\n")] = '\0';

    printf("Ingrese su genero preferido: ");
    fflush(stdin);
    fgets(admin.generoPreferido, sizeof(admin.generoPreferido), stdin);
    admin.generoPreferido[strcspn(admin.generoPreferido, "\r\n")] = '\0';

    fflush(stdin);
    strcpy(admin.contrasenia, contraAdmin);
    printf("Ingrese su contrase%ca: *****\n", 164);

    return admin;
}

int comprobarExistenciaIDUsuario(FILE *archivo, int i)
{
    int iVer = 0;
    int ids[100]; // Asume que hay un maximo de 100 usuarios
    int numUsuarios = 0;
    int idUnico = 0;

    fseek(archivo, 0, SEEK_SET);

    // Lee todos los IDs existentes en el archivo
    while (fread(&iVer, sizeof(int), 1, archivo) > 0)
    {
        ids[numUsuarios] = iVer;
        numUsuarios++;
    }

    // Genera un nuevo ID y verifica si ya existe
    do
    {
        idUnico = 1;
        i = (rand() % 100) + 1;

        for (int j = 0; j < numUsuarios; j++)
        {
            if (i == ids[j])
            {
                idUnico = 0;
                break;
            }
        }
    } while (!idUnico);

    return i;
}

void cargarArchivoUsuarios(char archivoUsuarios[])
{
    Usuario aux;
    char seguir = 's';

    FILE *archivo = fopen(archivoUsuarios, "ab");

    if (archivo != NULL)
    {
        while (seguir == 's')
        {
            aux = cargarDatosUnUsuario();
            fflush(stdin);
            aux.id = comprobarExistenciaIDUsuario(archivo, aux.id);

            fwrite(&aux, sizeof(Usuario), 1, archivo);

            printf("Desea seguir cargando usuarios? (s/n): ");
            fflush(stdin);
            scanf(" %c", &seguir);
            system("cls");
        }

        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

void cargarArchivoUsuariosAdmins(char archivoUsuarios[], char contraAdmin[])
{
    Usuario aux;
    char seguir = 's';

    FILE *archivo = fopen(archivoUsuarios, "ab");

    if (archivo != NULL)
    {
        while (seguir == 's')
        {
            aux = cargarDatosUnAdmin(contraAdmin);
            fflush(stdin);
            aux.id = comprobarExistenciaIDUsuario(archivo, aux.id);

            fwrite(&aux, sizeof(Usuario), 1, archivo);

            printf("Desea seguir cargando admins? (s/n): ");
            fflush(stdin);
            scanf(" %c", &seguir);
            system("cls");
        }

        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

void mostrarUnUsuario(Usuario dato)
{
    printf("\n ------------------------------- \n");
    printf(" ID: %d \n", dato.id);
    printf(" Nombre y apellido: %s\n", dato.nombreCompleto);
    printf(" E-mail: %s ", dato.mail);
    printf("\n ------------------------------- \n");
}

void mostrarArchivoUsuarios(char archivoUsuarios[])
{
    Usuario auxiliar;

    FILE *archivo = fopen(archivoUsuarios, "rb");

    if (archivo != NULL)
    {
        while (fread(&auxiliar, sizeof(Usuario), 1, archivo) > 0)
        {
            mostrarUnUsuario(auxiliar);
        }

        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

// --- PUBLICACION MUSICAL --- //

datosCadaPublicacion pedirDatosRegistro()
{
    datosCadaPublicacion nuevoRegistro;

    printf("---- Carga de Datos de la Publicacion: ----\n");

    printf("- Ingrese el titulo: ");
    fflush(stdin);
    fgets(nuevoRegistro.datosPublicacion.titulo, sizeof(nuevoRegistro.datosPublicacion.titulo), stdin);
    nuevoRegistro.datosPublicacion.titulo[strcspn(nuevoRegistro.datosPublicacion.titulo, "\r\n")] = '\0';

    printf("- Ingrese el genero: ");
    fflush(stdin);
    fgets(nuevoRegistro.datosPublicacion.genero, sizeof(nuevoRegistro.datosPublicacion.genero), stdin);
    nuevoRegistro.datosPublicacion.genero[strcspn(nuevoRegistro.datosPublicacion.genero, "\r\n")] = '\0';

    printf("- Ingrese el dia de publicacion: ");
    nuevoRegistro.datosPublicacion.dia = ingresarDia();

    printf("- Ingrese el mes de publicacion: ");
    nuevoRegistro.datosPublicacion.mes = ingresarMes();

    printf("- Ingrese el anio de publicacion: ");
    nuevoRegistro.datosPublicacion.anio = ingresarAnio();

    printf("- Ingrese el nombre y apellido del autor: ");
    fflush(stdin);
    fgets(nuevoRegistro.datosAutor.nombreYapellido, sizeof(nuevoRegistro.datosAutor.nombreYapellido), stdin);
    nuevoRegistro.datosAutor.nombreYapellido[strcspn(nuevoRegistro.datosAutor.nombreYapellido, "\r\n")] = '\0';

    printf("- Ingrese la nacionalidad del autor: ");
    fgets(nuevoRegistro.datosAutor.nacionalidad, sizeof(nuevoRegistro.datosAutor.nacionalidad), stdin);
    nuevoRegistro.datosAutor.nacionalidad[strcspn(nuevoRegistro.datosAutor.nacionalidad, "\r\n")] = '\0';

    printf("\n- Ingrese la biografia del autor: ");
    fflush(stdin);
    fgets(nuevoRegistro.datosAutor.biografia, sizeof(nuevoRegistro.datosAutor.biografia), stdin);
    nuevoRegistro.datosAutor.biografia[strcspn(nuevoRegistro.datosAutor.biografia, "\r\n")] = '\0';

    printf("\n- Ingrese la descripcion: ");
    fflush(stdin);
    fgets(nuevoRegistro.datosPublicacion.descripcion, sizeof(nuevoRegistro.datosPublicacion.descripcion), stdin);
    nuevoRegistro.datosPublicacion.descripcion[strcspn(nuevoRegistro.datosPublicacion.descripcion, "\r\n")] = '\0';

    printf("\n- Ingrese la primera palabra clave: ");
    fflush(stdin);
    fgets(nuevoRegistro.palabraClave1, sizeof(nuevoRegistro.palabraClave1), stdin);
    nuevoRegistro.palabraClave1[strcspn(nuevoRegistro.palabraClave1, "\r\n")] = '\0';

    printf("- Ingrese la segunda palabra clave: ");
    fflush(stdin);
    fgets(nuevoRegistro.palabraClave2, sizeof(nuevoRegistro.palabraClave2), stdin);
    nuevoRegistro.palabraClave2[strcspn(nuevoRegistro.palabraClave2, "\r\n")] = '\0';

    // Inicializa otros campos si es necesario

    nuevoRegistro.opiniones = NULL; // Inicializa la lista de opiniones como vacia
    nuevoRegistro.prestado = 0;     // Por defecto, no prestado
    nuevoRegistro.cantVecesLeida = 0;
    strcpy(nuevoRegistro.fuente, "Hemeroteca");

    return nuevoRegistro;
}

void cargarArchivoPublicacion(char archivoRegistros[])
{
    datosCadaPublicacion aux;
    char seguir = 's';

    FILE *archivo = fopen(archivoRegistros, "ab");

    if (archivo != NULL)
    {
        while (seguir == 's')
        {
            aux = pedirDatosRegistro();

            fwrite(&aux, sizeof(datosCadaPublicacion), 1, archivo);

            printf("\nDesea seguir cargando publicaciones? (s/n): ");
            fflush(stdin);
            scanf("%c", &seguir);
            system("cls");
        }

        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

// --- FUNCIONES DE MOSTRADO --- //
void mostrarUnaPublicacion(datosCadaPublicacion dato)
{
    printf("\n ------------------------------- \n");
    printf("- Titulo: %s\n", dato.datosPublicacion.titulo);
    printf("- Genero: %s\n", dato.datosPublicacion.genero);
    mostrarFecha(dato);
    printf("- Descripcion: %s \n\n", dato.datosPublicacion.descripcion);
    printf("- Nombre completo del autor: %s\n", dato.datosAutor.nombreYapellido);
    printf("- Nacionalidad: %s \n", dato.datosAutor.nacionalidad);
    printf("- Biografia: %s \n\n", dato.datosAutor.biografia);
    printf("- Primer palabra clave: %s\n", dato.palabraClave1);
    printf("- Segunda palabra clave: %s\n", dato.palabraClave2);
    // printf("- Prestado (1 = si | 0 = no): %d \n", dato.prestado);
    printf("- Fuente de informacion: %s \n", dato.fuente);
    // printf("- Veces leidas: %d", dato.cantVecesLeida);
    printf("\n ------------------------------- \n");
}

void mostrarUnaPublicacion2(datosCadaPublicacion dato)
{
    printf("\n ------------------------------- \n");
    printf("- Titulo: %s\n", dato.datosPublicacion.titulo);
    printf("- Genero: %s\n", dato.datosPublicacion.genero);
    mostrarFecha(dato);
    printf("- Descripcion: %s \n\n", dato.datosPublicacion.descripcion);
    printf("- Nombre completo del autor: %s\n", dato.datosAutor.nombreYapellido);
    printf("- Nacionalidad: %s \n", dato.datosAutor.nacionalidad);
    printf("- Biografia: %s \n\n", dato.datosAutor.biografia);
    printf("- Primer palabra clave: %s\n", dato.palabraClave1);
    printf("- Segunda palabra clave: %s\n", dato.palabraClave2);
    printf("- Prestado (1 = si | 0 = no): %d \n", dato.prestado);
    printf("- Fuente de informacion: %s \n", dato.fuente);
    printf("- Veces leidas: %d", dato.cantVecesLeida);
    printf("\n ------------------------------- \n");
}

void mostrarArchivoPublicacion(char archivoRegistros[])
{
    datosCadaPublicacion aux;
    FILE *archivo = fopen(archivoRegistros, "rb");

    if (archivo != NULL)
    {
        fseek(archivo, 0, SEEK_SET);

        while (fread(&aux, sizeof(datosCadaPublicacion), 1, archivo) > 0)
        {
            mostrarUnaPublicacion(aux);
        }

        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

// --- FUNCIONES DE BUSQUEDA --- //
// Funcion para buscar por titulo
lista_de_listas *mostrarPublicacionXTitulo(lista_de_listas *listaPublicaciones, char tituloABuscar[])
{
    lista_de_listas *seg = listaPublicaciones;

    while (seg != NULL)
    {
        nodo_sublista_simple *nodoActual = seg->listaDatosPublicaciones;

        while (nodoActual != NULL)
        {
            if (strcmpi(nodoActual->miRegistro.datosPublicacion.titulo, tituloABuscar) == 0)
            {
                mostrarUnaPublicacion(nodoActual->miRegistro);
                nodoActual->miRegistro.cantVecesLeida++;
            }

            nodoActual = nodoActual->siguiente;
        }

        seg = seg->siguiente;
    }

    return listaPublicaciones;
}

// Funcion para buscar por autor
lista_de_listas *mostrarPublicacionXAutor(lista_de_listas *listaPublicaciones, char autorABuscar[])
{
    lista_de_listas *seg = listaPublicaciones;

    while (seg != NULL)
    {
        nodo_sublista_simple *nodoActual = seg->listaDatosPublicaciones;

        while (nodoActual != NULL)
        {
            if (strcmpi(nodoActual->miRegistro.datosAutor.nombreYapellido, autorABuscar) == 0)
            {
                mostrarUnaPublicacion(nodoActual->miRegistro);
                nodoActual->miRegistro.cantVecesLeida++;
            }

            nodoActual = nodoActual->siguiente;
        }

        seg = seg->siguiente;
    }

    return listaPublicaciones;
}

// Funcion para buscar por fecha
lista_de_listas *mostrarPublicacionXFecha(lista_de_listas *listaPublicaciones, int anio1, int anio2)
{
    lista_de_listas *seg = listaPublicaciones;

    while (seg != NULL)
    {
        nodo_sublista_simple *nodoActual = seg->listaDatosPublicaciones;

        while (nodoActual != NULL)
        {
            if ((nodoActual->miRegistro.datosPublicacion.anio >= anio1) && (nodoActual->miRegistro.datosPublicacion.anio <= anio2))
            {
                mostrarUnaPublicacion(nodoActual->miRegistro);
                nodoActual->miRegistro.cantVecesLeida++;
            }

            nodoActual = nodoActual->siguiente;
        }

        seg = seg->siguiente;
    }
    return listaPublicaciones;
}

// Funcion para buscar por palabra clave
lista_de_listas *mostrarPublicacionXPalabraClave(lista_de_listas *listaPublicaciones, char palabraClave[])
{
    lista_de_listas *seg = listaPublicaciones;

    while (seg != NULL)
    {
        nodo_sublista_simple *nodoActual = seg->listaDatosPublicaciones;

        while (nodoActual != NULL)
        {
            if ((strcmpi(nodoActual->miRegistro.palabraClave1, palabraClave) == 0) || (strcmpi(nodoActual->miRegistro.palabraClave2, palabraClave) == 0))
            {
                mostrarUnaPublicacion(nodoActual->miRegistro);
                nodoActual->miRegistro.cantVecesLeida++;
            }

            nodoActual = nodoActual->siguiente;
        }

        seg = seg->siguiente;
    }
    return listaPublicaciones;
}

// Funciones para actualizar informacion en el archivo
int buscarRegistro(char nombreArchivo[], char tituloBuscar[])
{
    datosCadaPublicacion aux;
    int posicion = 0;
    int flag = -1;

    FILE *archivo = fopen(nombreArchivo, "rb");

    if (archivo != NULL)
    {
        while (fread(&aux, sizeof(datosCadaPublicacion), 1, archivo) == 1)
        {
            if (strcmpi(aux.datosPublicacion.titulo, tituloBuscar) == 0)
            {
                flag = posicion;
            }

            posicion++;
        }

        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }

    return flag; // Retorna -1 si no se encontro el registro
}

void actualizarInformacionPublicacion(char archivoRegistros[], int posicion)
{
    int opcion = 0;
    datosCadaPublicacion aux;

    FILE *archivo = fopen(archivoRegistros, "r+b");

    if (archivo != NULL)
    {
        fseek(archivo, posicion * sizeof(datosCadaPublicacion), SEEK_SET); // Mueve el puntero al inicio del registro a actualizar
        fread(&aux, sizeof(datosCadaPublicacion), 1, archivo);             // Lee el registro actual

        printf("\n\nQue informacion desea actualizar? \n");
        printf("1. Titulo. \n");
        printf("2. Autor. \n");
        printf("3. Descripcion. \n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
        {
            printf("Ingrese el nuevo titulo: ");
            fflush(stdin);
            fgets(aux.datosPublicacion.titulo, sizeof(aux.datosPublicacion.titulo), stdin);
            aux.datosPublicacion.titulo[strcspn(aux.datosPublicacion.titulo, "\r\n")] = '\0';
            break;
        }
        case 2:
        {
            printf("Ingrese el nuevo autor: ");
            fflush(stdin);
            fgets(aux.datosAutor.nombreYapellido, sizeof(aux.datosAutor.nombreYapellido), stdin);
            aux.datosAutor.nombreYapellido[strcspn(aux.datosAutor.nombreYapellido, "\r\n")] = '\0';
            break;
        }
        case 3:
        {
            printf("Ingrese la nueva descripcion: ");
            fflush(stdin);
            fgets(aux.datosPublicacion.descripcion, sizeof(aux.datosPublicacion.descripcion), stdin);
            aux.datosPublicacion.descripcion[strcspn(aux.datosPublicacion.descripcion, "\r\n")] = '\0';
            break;
        }
        default:
        {
            printf("Opcion no valida.\n");
            break;
        }
        }

        fseek(archivo, posicion * sizeof(datosCadaPublicacion), SEEK_SET); // Mover el puntero al inicio del registro a actualizar en el archivo
        fwrite(&aux, sizeof(datosCadaPublicacion), 1, archivo);            // Escribir el registro actualizado en el archivo
        fclose(archivo);

        printf("Informacion de la publicacion actualizada exitosamente. \n");
    }
    else
    {
        printf("Error: no se pudo abrir el archivo.\n");
    }
}

/// --- FUNCIONES PARA MOSTRAR UN AUTOR --- ///

void imprimirAutor(datosCadaPublicacion autor)
{
    printf("--------------------------\n");
    printf("Nombre: %s \n", autor.datosAutor.nombreYapellido);
    printf("Nacionalidad: %s \n", autor.datosAutor.nacionalidad);
    printf("Biografia: %s \n", autor.datosAutor.biografia);
    printf("Publicacion(es): %s \n", autor.datosPublicacion.titulo);
    printf("---------------------------\n");
    printf("\n");
}

// Funcion de buscar un autor por nacionalidad
void mostrarDatosAutorXNacionalidad(char archivoRegistros[], char nacionalidad[])
{
    datosCadaPublicacion data;

    FILE *archivo = fopen(archivoRegistros, "rb");

    if (archivo != NULL)
    {
        fseek(archivo, 0, SEEK_SET);

        while (fread(&data, sizeof(datosCadaPublicacion), 1, archivo) > 0)
        {
            if (strcmpi(data.datosAutor.nacionalidad, nacionalidad) == 0)
            {
                imprimirAutor(data);
            }
        }
        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

// Funcion de buscar un autor por nombre
void mostrarDatosAutorXNombre(char archivoRegistros[], char autorABuscar[])
{
    datosCadaPublicacion data;

    FILE *archivo = fopen(archivoRegistros, "rb");

    if (archivo != NULL)
    {
        fseek(archivo, 0, SEEK_SET);

        while (fread(&data, sizeof(datosCadaPublicacion), 1, archivo))
        {
            if (strcmpi(data.datosAutor.nombreYapellido, autorABuscar) == 0)
            {
                imprimirAutor(data);
            }
        }
        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

// --- FUNCIONES PARA BORRAR UNA PUBLICACION --- //
// Funcion para borrar una publicacion por el nombre del autor
int borrarUnaPublicacionXAutor(char archivoRegistros[], char autorABorrar[])
{
    int rta = 0;
    datosCadaPublicacion dataAux;
    FILE *archivo = fopen(archivoRegistros, "rb");
    FILE *archAux = fopen("copiaArchRegistros.bin", "wb");

    if (archivo != NULL && archAux != NULL)
    {
        while (fread(&dataAux, sizeof(datosCadaPublicacion), 1, archivo) > 0)
        {
            if (strcmpi(dataAux.datosAutor.nombreYapellido, autorABorrar) != 0)
            {
                fwrite(&dataAux, sizeof(datosCadaPublicacion), 1, archAux);
                rta = 1;
            }
        }

        fclose(archivo);
        fclose(archAux);

        remove(archivoRegistros);                           // Se borra el archivo viejo
        rename("copiaArchRegistros.bin", archivoRegistros); // Se renombra al nuevo archivo como al archivo original pero conservando los datos sin borrar
    }
    else
    {
        printf("Error: no se pudieron abrir los archivos. \n");
    }
    return rta;
}

// Funcion para borrar una publicacion por el nombre del titulo de la misma
int borrarUnaPublicacionXTitulo(char archivoRegistros[], char tituloABorrar[])
{
    int rta2 = 0;
    datosCadaPublicacion dataAux;
    FILE *archivo = fopen(archivoRegistros, "rb");
    FILE *archAux = fopen("copiaArchRegistros.bin", "wb");

    if (archivo != NULL && archAux != NULL)
    {
        while (fread(&dataAux, sizeof(datosCadaPublicacion), 1, archivo) > 0)
        {
            if (strcmpi(dataAux.datosPublicacion.titulo, tituloABorrar) != 0)
            {
                fwrite(&dataAux, sizeof(datosCadaPublicacion), 1, archAux);
                rta2 = 1;
            }
        }

        fclose(archivo);
        fclose(archAux);

        remove(archivoRegistros);                           // Se borra el archivo viejo
        rename("copiaArchRegistros.bin", archivoRegistros); // Se renombra al nuevo archivo como al archivo original pero conservando los datos sin borrar
    }
    else
    {
        printf("Error: no se pudieron abrir los archivos. \n");
    }
    return rta2;
}

// --- AGREGAR OPINIONES Y COMENTARIOS --- //
// Funcion para que los usuarios agreguen comentarios y calificaciones
void agregarOpinion(datosCadaPublicacion *registro)
{
    if (registro->opiniones == NULL)
    {
        registro->opiniones = (nodo_lista_comentarios *)malloc(sizeof(nodo_lista_comentarios));
        registro->opiniones->siguiente = NULL;
    }
    else
    {
        // Se agrega una nueva opinion al final de la lista
        nodo_lista_comentarios *nuevaOpinion = (nodo_lista_comentarios *)malloc(sizeof(nodo_lista_comentarios));
        nuevaOpinion->siguiente = NULL;

        // Se solicita comentarios y calificaciones al usuario
        printf("Ingrese sus comentarios: ");
        fflush(stdin);
        fgets(nuevaOpinion->comentarios, sizeof(nuevaOpinion->comentarios), stdin);
        nuevaOpinion->comentarios[strcspn(nuevaOpinion->comentarios, "\r\n")] = '\0';

        printf("Ingrese su calificacion (0 to 5): ");
        fflush(stdin);
        scanf("%i", &nuevaOpinion->calificacion);

        printf("Comentario(s) y calificacion agregados con exito.\n");

        // Se enlaza la nueva opinion al final de la lista
        nodo_lista_comentarios *actual = registro->opiniones;

        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }

        actual->siguiente = nuevaOpinion;
    }
}

// Funcion para buscar una publicacion por titulo en el archivo
void buscarParaComentar(char archivoRegistros[], char tituloBuscado[])
{
    int encontrado = 0;
    datosCadaPublicacion registro;

    FILE *archivo = fopen(archivoRegistros, "rb");

    if (archivo != NULL)
    {
        while (fread(&registro, sizeof(datosCadaPublicacion), 1, archivo) > 0)
        {
            if (strcmpi(registro.datosPublicacion.titulo, tituloBuscado) == 0)
            {
                printf("Registro encontrado:\n");
                printf("Titulo: %s\n", registro.datosPublicacion.titulo);
                printf("Autor: %s\n", registro.datosAutor.nombreYapellido);
                system("pause");
                system("cls");

                encontrado = 1;

                agregarOpinion(&registro);
            }
        }

        if (!encontrado)
        {
            printf("Registro no encontrado.\n");
        }

        fclose(archivo);
    }
    else
    {
        printf("Error: no se pudo abrir el archivo. \n");
    }
}

// --- MOSTRAR OPINIONES --- //
//  Funcion para que los usuarios conozcan las opiniones de la comunidad
void conocerOpiniones(datosCadaPublicacion registro)
{
    // Verificar si hay opiniones
    if (registro.opiniones == NULL)
    {
        printf("No hay opiniones disponibles para esta publicacion.\n");
    }

    // Mostrar comentarios y calificaciones
    printf("Opiniones de la comunidad:\n");

    nodo_lista_comentarios *actual = registro.opiniones;

    while (actual != NULL)
    {
        printf("Comentarios: %s\n", actual->comentarios);
        printf("Calificacion: %d\n", actual->calificacion);
        printf("\n");

        actual = actual->siguiente;
    }
}
