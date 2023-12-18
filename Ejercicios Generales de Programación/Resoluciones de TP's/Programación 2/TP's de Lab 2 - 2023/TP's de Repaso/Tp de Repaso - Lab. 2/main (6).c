#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX 4

///Un sistema de registro de estudiantes que almacena la información de cada estudiante en una estructura y la guarda en un archivo:

typedef struct
{
    char nombreYapellido[40];
    int edad;
    int nota1C[TAM_MAX];
    int nota2C[TAM_MAX];
    int validos1;
    int validos2;
    float promedio;

} stAlumno;

/// PROTOTIPADO
stAlumno carga();
int sumaNota1c(stAlumno alumnoSuma);
int sumaNota2C(stAlumno alumnoSuma);
float promedioNotas(stAlumno alumnoPromedio);
void mejorPromedio(char[], stAlumno[]);
void cargaAlumno(char nombreArchivo[], stAlumno nuevoAlumno);
int contarDatosIngresados(char[], stAlumno alumno);
float promedioGeneral(char[], float promedios[], int, stAlumno alumno);
void mostrarAlumno(stAlumno a);
void muestraArchivo(char nombreArchivo[], stAlumno a);
void buscarAlumnoXNombre (char nombreArchivo[], char nombreApellidoAlumno[]);
void actualizarAlumno(char[], char[]);


int main()
{
    char nombreArchivo[] = "alumnos.bin";
    stAlumno alumno;
    int opcion;
    int salir = 0;
    int i = 0;
    stAlumno alumnos[TAM_MAX];
    float promedios[TAM_MAX];
    int validosArrPromedios = 0;

    printf("Bienvenido al software de la escuela\n\n");

    do
    {
        system("pause");
        system("cls");

        printf("Seleccione una opcion:\n");
        printf("1. Cargar alumnos.\n");
        printf("2. Mostrar alumnos.\n");
        printf("3. Buscar alumno por nombre.\n");
        printf("4. Actualizar datos.\n");
        printf("5. Buscar el mejor promedio. \n");
        printf("6. Calcular el promedio general del aula. \n");
        printf("7. Ver cuantos datos tiene cargados el archivo. \n");
        printf("8. Borrar datos del archivo. \n");
        printf("9. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            int contador = 0;
            float promedioTotal = 0;

                case 1:
                {
                    int i = 0;
                    char respuesta;

                    do
                    {
                        system("cls");
                        stAlumno alumnoNuevo = carga(); // Carga los datos del alumno
                        int totalSuma = sumaNota1C(alumnoNuevo) + sumaNota2C(alumnoNuevo);
                        float promedioFinal = promedioNotas(alumnoNuevo);
                        alumnoNuevo.promedio = promedioFinal;
                        promedios[i] = promedioFinal;
                        validosArrPromedios++;
                        i++;

                        printf("Suma de notas: %d\n", totalSuma);
                        printf("Promedio de notas: %.2f\n", promedioFinal);

                        cargaAlumno(nombreArchivo, alumnoNuevo);

                        printf("Desea ingresar mas alumnos? (s/n): ");
                        fflush(stdin);
                        scanf(" %c", &respuesta);

                    } while (respuesta == 's');   // Continuar el bucle interno

                    break;
                }
                case 2:
                {
                    system("cls");
                    muestraArchivo(nombreArchivo, alumno);
                    system("pause");
                    break;
                }
                case 3:
                {

                    system("cls");
                    char nombreApellidoAlumno[40];

                    printf("Ingrese el nombre y apellido del alumno a buscar: ");
                    fflush(stdin);
                    gets(nombreApellidoAlumno);

                    buscarAlumnoXNombre(nombreArchivo,nombreApellidoAlumno);
                    break;
                }
                case 4:
                {

                    system("cls");
                    char nombreBusqueda[40];

                    printf("Ingrese el nombre y apellido del alumno a actualizar: ");
                    fflush(stdin);
                    gets(nombreBusqueda);
                    actualizarAlumno(nombreArchivo, nombreBusqueda);
                    break;
                }
                case 5:
                {
                    system("cls");
                    char respuesta;
                    mejorPromedio(nombreArchivo, alumnos);
                    break;
                }
                case 6:
                {
                    system("cls");
                    promedioTotal = promedioGeneral(nombreArchivo, promedios, validosArrPromedios, alumno);
                    printf("El promedio general del aula es: %.2f \n", promedioTotal);
                    break;
                }
                case 7:
                {
                    system("cls");
                    contador = contarDatosIngresados(nombreArchivo, alumno);
                    printf("Hay %i elementos en el archivo. \n", contador);
                    break;
                }
                case 8:
                {
                    system("cls");
                    printf("Borrando datos del archivo. \n");
                    system("pause");
                    vaciarArchivo(nombreArchivo);
                    contador = 0; //Se reinicia el contador de alumnos cargados.
                    promedioTotal = 0; //Se reinicia el promedio general del aula.
                    break;
                }

                case 9:
                {
                    salir = 1;
                    break;
                }
                default:
                {
                    printf("Opcion invalida.\n");
                    break;
                }
                }

            } while (!salir);

    printf("Gracias por utilizar el software de la escuela.\n");

    return 0;
}

stAlumno carga()
{
    stAlumno alumno;

    int nota1;
    int nota2;
    int flag = 0;
    int i = 0;
    alumno.validos1 = 0;
    alumno.validos2 = 0;

    printf("Ingrese el nombre y apellido del alumno: ");
    fflush(stdin);
    gets(alumno.nombreYapellido);

    printf("Ingrese la edad: ");
    fflush(stdin);
    scanf("%d", &alumno.edad);

    while(i < TAM_MAX)
    {
        printf("Ingrese las notas de ambos cuatrimestres: \n");

        if(i == 0)
        {
            while(flag == 0)
            {
                printf("Lengua 1: ");
                fflush(stdin);
                scanf("%d", &nota1);

            if (nota1<=10 && nota1>0)
            {
                alumno.nota1C[i] = nota1;
                alumno.validos1++;
                flag = 1;
            }
            else
            {
                printf("El numero no es valido\n");
            }

            }
            flag = 0;

            while(flag == 0)
            {
                printf("Lengua 2: ");
                fflush(stdin);
                scanf("%d", &nota2);

                if (nota2<=10 && nota2>0)
                {
                    alumno.nota2C[i] = nota2;
                    alumno.validos2++;
                    flag = 1;
                }
                else
                {
                    printf("El numero no es valido\n");
                }
            }

            i++;
        }
        else if (i == 1)
        {
            flag = 0;

            while(flag == 0)
            {
                printf("Matematica 1: ");
                fflush(stdin);
                scanf("%d", &nota1);

            if (nota1<=10 && nota1>0)
            {
                alumno.nota1C[i] = nota1;
                alumno.validos1++;
                flag = 1;
            }
            else
            {
                printf("El numero no es valido\n");
            }
            }
              flag = 0;

              while(flag == 0)
              {
                printf("Matematica 2: ");
                fflush(stdin);
                scanf("%d", &nota2);

                if (nota2<=10 && nota2>0)
                {
                    alumno.nota2C[i] = nota2;
                    alumno.validos2++;
                    flag = 1;
                }
                else
                {
                    printf("El numero no es valido\n");
                }
              }

            i++;
        }
        else if(i == 2)
        {
            flag = 0;

            while(flag == 0)
            {
                printf("Biologia 1: ");
                fflush(stdin);
                scanf("%d", &nota1);

            if (nota1<=10 && nota1>0)
            {
                alumno.nota1C[i] = nota1;
                alumno.validos1++;
                flag = 1;
            }
            else
            {
                printf("El numero no es valido\n");
            }

            }
               flag = 0;

               while(flag == 0)
               {
                    printf("Biologia 2: ");
                    fflush(stdin);
                    scanf("%d", &nota2);

                if (nota2<=10 && nota2>0)
                {
                    alumno.nota2C[i] = nota2;
                    alumno.validos2++;
                    flag = 1;
                }
                else
                {
                    printf("El numero no es valido\n");
                }
               }

            i++;
        }
        else if(i == 3)
        {
            flag = 0;

            while(flag == 0)
            {
                printf("Geografia 1: ");
                fflush(stdin);
                scanf("%d", &nota1);

            if (nota1<=10 && nota1>0)
            {
                alumno.nota1C[i] = nota1;
                alumno.validos1++;
                flag = 1;
            }
            else
            {
                printf("El numero no es valido\n");
            }
            }
               flag = 0;

               while(flag == 0)
               {
                printf("Geografia 2: ");
                fflush(stdin);
                scanf("%d", &nota2);

                if (nota2<=10 && nota2>0)
                {
                    alumno.nota2C[i] = nota2;
                    alumno.validos2++;
                    flag = 1;
                }
                else
                {
                    printf("El numero no es valido\n");
                }
               }

            i++;
        }

    }
       return alumno;

}

int sumaNota1C(stAlumno alumnoSuma)
{
    int i = 0;
    int sumaTotal1C = 0;

    for(i = 0; i < alumnoSuma.validos1; i++)
    {
       sumaTotal1C += alumnoSuma.nota1C[i];
    }

    return sumaTotal1C;
}

int sumaNota2C(stAlumno alumnoSuma)
{
    int i = 0;
    int sumaTotal2C = 0;

    for(i = 0; i < alumnoSuma.validos2; i++)
    {
       sumaTotal2C += alumnoSuma.nota2C[i];
    }

    return sumaTotal2C;
}

//Calculo del promedio de notas de un alumno.

float promedioNotas(stAlumno alumnoPromedio)
{
    int sumaNotas = sumaNota1C(alumnoPromedio) + sumaNota2C(alumnoPromedio);
    float promedio = (float)sumaNotas / (alumnoPromedio.validos1 * 2);

    return promedio;
}

void mejorPromedio(char nombreArchivo[], stAlumno alumnos[])
{
    char respuesta;

    FILE* archivito;
    archivito = fopen(nombreArchivo, "rb");

    if (archivito != NULL)
    {
        int i = 0;
        float mejorProm = 0;
        int indiceMejorProm = -1;

        while (fread(&alumnos[i], sizeof(stAlumno), 1, archivito) == 1) //Recorre todo el archivo.
        {
            if (alumnos[i].promedio > mejorProm)
            {
                mejorProm = alumnos[i].promedio;  //Almacena el nuevo mejor promedio, junto con el indice que indica en qué posicion se encuntra. O sea, a qué alumno pertenece dicho promedio.
                indiceMejorProm = i;
            }
            i++;
        }

        if (indiceMejorProm != -1)
        {
            printf("El mejor promedio es: %.2f \n\n", mejorProm);

            printf("Quiere ver los datos del alumno? (s/n) \n");
            fflush(stdin);
            scanf(" %c", &respuesta);

            if (respuesta == 's')
            {
                mostrarAlumno(alumnos[indiceMejorProm]);
            }
        }
        else
        {
            printf("No se encontraron alumnos cargados.\n");
        }

       fclose(archivito);
    }
    else
    {
        printf("No se pudo abrir el archivo. \n");
    }
}

//Calcular promedio general de todos los alumnos.

float promedioGeneral(char nombreArchivo[], float promedios[], int validosArrPromedios, stAlumno alumno)
{
    int i = 0;
    float promedioGeneral = 0, promedioTotal = 0;
    int confirmador = 0;

    confirmador = contarDatosIngresados(nombreArchivo, alumno);  //Variable auxiliar que confirma si el Archivo tiene al menos un alumno cargado.

    if(confirmador != 0)
    {
          while(i < validosArrPromedios)
         {
            promedioGeneral += promedios[i]; //Calculo del promedio general. A medida que se fueron cargando los alumnos, se fueron guardando los respectivos promedios en un arreglo de promedios.
            i++;
         }

        promedioTotal = promedioGeneral / validosArrPromedios;
    }
    else
    {
        printf("No hay alumnos cargados el archivo. \n");
        promedioTotal = 0;
    }

    return promedioTotal;
}

void cargaAlumno(char nombreArchivo[], stAlumno alumno)
{
    int alumnosCargados = 0;
    FILE *archivito;
    archivito = fopen(nombreArchivo, "ab");

    if (archivito != NULL)
    {
        fwrite(&alumno, sizeof(stAlumno), 1, archivito);  //Escribe en el Archivo los datos del alumno cargado. Dicho datos se cargan en forma de estructura.
        fclose(archivito);
    }

}

//Contar cantidad de datos cargados al Archivo.

int contarDatosIngresados(char nombreArchivo[], stAlumno alumno)
{
    int contador = 0;
    FILE* archivito;
    archivito = fopen(nombreArchivo, "rb");

    if (archivito != NULL)
    {
       while(fread(&alumno, sizeof(stAlumno), 1, archivito) == 1)  //Lee el Archivo de principio a fin, y va sumando en 1 a meida que va leyendo los datos del mismo.
       {
           contador++;
       }

       fclose(archivito);
    }
    else
    {
        printf("No se pudo abrir el archivo para escritura.\n");
    }

    return contador;
}

//Borrar todos los datos del Archivo.

void vaciarArchivo(char nombreArchivo[])
{
    FILE* archivito;
    archivito = fopen(nombreArchivo, "wb");

    if (archivito != NULL)
    {
        fclose(archivito);  //Borra todos los datos del Archivo.
        printf("Datos del archivo borrados satisfactoriamente. \n");
    }
    else
    {
        printf("No se pudo abrir el archivo para escritura.\n");
    }
}

void mostrarAlumno(stAlumno a)
{
    int i = 0;
    puts("\n----------------------------------------------------");
    printf("Nombre y apellido del alumno: %s\n", a.nombreYapellido);
    printf("Edad el alumno: %d\n", a.edad);
    for(i = 0; i < a.validos1; i++)           //Muestra las respectivas notas de cada materia.
    {
        if(i == 0)
        {
            printf("Lengua 1: %d\n", a.nota1C[i]);
            printf("Lengua 2: %d\n", a.nota2C[i]);
        }
        else if(i == 1)
        {
            printf("Matematica 1: %d\n", a.nota1C[i]);
            printf("Matematica 2: %d\n", a.nota2C[i]);
        }
        else if(i == 2)
        {
            printf("Biologia 1: %d\n", a.nota1C[i]);
            printf("Biologia 2: %d\n", a.nota2C[i]);
        }
        else
        {
            printf("Geografia 1: %d\n", a.nota1C[i]);
            printf("Geografia 2: %d\n", a.nota2C[i]);
        }
    }
    printf("Promedio del alumno: %.2f\n", a.promedio);
}

//Mostrar todos los datos del Archivo.

void muestraArchivo(char nombreArchivo[], stAlumno a)
{
    FILE *archi;
    archi = fopen(nombreArchivo, "rb");

    if(archi != NULL)
    {

        while(!feof(archi))
        {

            fread(&a, sizeof(stAlumno),1,archi);   //Abre, lee y muestra el Archivo completo.

            if(!feof(archi))
            {
                mostrarAlumno(a);
            }

        }
        fclose(archi);
    }

}

///Buscar estudiantes por nombre o identificación.

void buscarAlumnoXNombre (char nombreArchivo[], char nombreApellidoAlumno[])
{
    FILE *archi;
    archi = fopen(nombreArchivo, "rb");
    stAlumno alumno;

    int flag = 0;
    char respuesta;

    if (archi != NULL)
    {
        while ((fread(&alumno, sizeof(stAlumno), 1, archi) == 1) && flag == 0)  //Recorre el Archivo completo. "Mientras aún haya elementos dentro del Archivo..."
        {
            if (strcmp(nombreApellidoAlumno, alumno.nombreYapellido) == 0)  //Busca el nombre del alumno comparandolo con los nombres de alumnos cargados en el Archivo.
            {
                printf("\n El alumno se encuentra en la lista\n\n");
                flag = 1;

                printf("Quiere ver los datos del alumno? (s/n)");
                fflush(stdin);
                scanf(" %c", &respuesta);

                if (respuesta == 's')
                {
                    mostrarAlumno(alumno);
                }
            }
        }
        fclose(archi);

        if (flag == 0)
        {
            printf("\n El alumno no se encuentra en la lista.\n\n");
        }
    }
    else
    {
        printf("No se pudo abrir el archivo para lectura.\n");
    }
}

/// Actualizar datos del alumno.

void actualizarAlumno(char nombreArchivo[], char nombreBuscar[])
{
    FILE *archi;
    archi = fopen(nombreArchivo, "r+b");
    int flag = 0;
    int nota1;
    int nota2;
    int i = 0;

    if (archi != NULL)
    {
        stAlumno alumno;
        int encontrado = 0;

        while (fread(&alumno, sizeof(stAlumno), 1, archi) == 1)
        {
            if (strcmp(alumno.nombreYapellido, nombreBuscar) == 0)
            {
                encontrado = 1;
                printf("Alumno encontrado:\n");
                mostrarAlumno(alumno);

                printf("Seleccione el dato que desea cambiar:\n");
                printf("1. Edad.\n");
                printf("2. Notas del primer cuatrimestre.\n");
                printf("3. Notas del segundo cuatrimestre.\n");
                printf("4. Salir. \n");
                int opcion;
                scanf("%d", &opcion);

                switch (opcion)
                {
                            case 1:                                       //Actualiza la edad.
                                printf("Ingrese la nueva edad: ");
                                fflush(stdin);
                                scanf("%d", &alumno.edad);
                                printf("Edad actualizada: %d \n", alumno.edad);
                                break;

                            case 2:                //Actualiza las notas de todas las materias del 1er cuatrimestre.
                            {
                                printf("Ingrese las nuevas notas del 1er cuatrimestre:\n");
                                for (i = 0; i < TAM_MAX; i++)
                                {
                                    do
                                    {
                                        printf("Ingrese nota %d: ", i + 1);
                                        scanf("%d", &nota1);
                                        if (nota1 >= 0 && nota1 <= 10)
                                        {
                                            alumno.nota1C[i] = nota1;
                                            flag = 1;
                                        }
                                        else
                                        {
                                            printf("Nota inválida. Debe estar entre 0 y 10.\n");
                                        }
                                    }
                                    while (!flag);
                                    flag = 0;
                                }
                                break;
                            }

                            case 3:       //Actualiza las notas de todas las materias del 2do cuatrimestre.
                                {
                                    printf("Ingrese las nuevas notas del 2do cuatrimestre:\n");
                                    for (i = 0; i < TAM_MAX; i++)
                                    {
                                        do
                                        {
                                            printf("Ingrese nota %d: ", i + 1);
                                            scanf("%d", &nota2);
                                            if (nota2 >= 0 && nota2 <= 10)
                                            {
                                                alumno.nota2C[i] = nota2;
                                                flag = 1;
                                            }
                                            else
                                            {
                                                printf("Nota inválida. Debe estar entre 0 y 10.\n");
                                            }
                                        }
                                        while (!flag);
                                        flag = 0;
                                    }
                                    break;
                                }


                            case 4:
                            {
                                break;
                            }


                            default:
                                {
                                    printf("Opción inválida.\n");
                                    break;
                                }

            }

            // Recalcular promedio
            float promedioFinal = promedioNotas(alumno);
            alumno.promedio = promedioFinal;

            // Regresar a la posición de lectura/escritura para actualizar el registro
            fseek(archi, -sizeof(stAlumno), SEEK_CUR);
            fwrite(&alumno, sizeof(stAlumno), 1, archi);
            fflush(archi); // Forzar la escritura inmediata en el archivo
            printf("Datos actualizados y promedio recalculado: %.2f\n", promedioFinal);
            break; // Salir del bucle después de actualizar

        }
    }

    if (!encontrado)
    {
        printf("Alumno no encontrado.\n");
    }

    fclose(archi);
}
else
{
    printf("No se pudo abrir el archivo para lectura/escritura.\n");
}
}
