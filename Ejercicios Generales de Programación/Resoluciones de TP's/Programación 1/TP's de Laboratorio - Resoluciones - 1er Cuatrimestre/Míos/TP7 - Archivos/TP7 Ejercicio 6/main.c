#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombreYapellido[30];
    int edad;
    int anio;

}stAlumnos;

int cargaDeAlumnosEnArchivo(FILE* fp,stAlumnos* p,stAlumnos arregloAlumnos[],int* validos);
void mostrarArchivo(FILE* fp,stAlumnos arregloAlumnos[],int validos);

int main()
{
    stAlumnos* p;
    stAlumnos arregloAlumnos[10];
    FILE* fp;
    int validos = 0;
    cargaDeAlumnosEnArchivo(&fp,&p,arregloAlumnos,&validos);
    mostrarArchivo(&fp,arregloAlumnos,validos);
    cargaDeAlumnosExtraEnArchivo(&fp,&p,arregloAlumnos,&validos);
    mostrarArchivo(&fp,arregloAlumnos,validos);

}



int cargaDeAlumnosEnArchivo(FILE* fp,stAlumnos* p,stAlumnos arregloAlumnos[],int* validos)
{
    char continuar = 's';
    int i = 0;

    fp = fopen("Archivo4.bin","wb");
    if(fp != NULL)
    {
        while(continuar == 's')
        {
            printf("Ingrese el numero de legajo: \n");
            scanf("%i", &arregloAlumnos[i].legajo);
            printf("Ingrese nombre y apellido: \n");
            fflush(stdin);
            gets(arregloAlumnos[i].nombreYapellido);
            printf("Ingrese la edad: \n");
            scanf("%i",&arregloAlumnos[i].edad);
            printf("Ingrese el anio de cursada: \n");
            scanf("%i",&arregloAlumnos[i].anio);
            i++;

            fwrite(&arregloAlumnos,sizeof(stAlumnos),1,fp);

            printf("Desea continuar?: \n");
            fflush(stdin);
            scanf("%c",&continuar);
        }
            fclose(fp);
    }
    else
    {
        printf("No se pudo abrir el archivo. \n");
    }
    *validos = i;
    return *validos;
}


int cargaDeAlumnosExtraEnArchivo(FILE* fp,stAlumnos* p,stAlumnos arregloAlumnos[],int* validos)
{
    char continuar = 's';
    int i = 0;

    fp = fopen("Archivo4.bin","ab");
    if(fp != NULL)
    {
        while(continuar == 's')
        {
            printf("Ingrese el numero de legajo: \n");
            scanf("%i", &arregloAlumnos[i].legajo);
            printf("Ingrese nombre y apellido: \n");
            fflush(stdin);
            gets(arregloAlumnos[i].nombreYapellido);
            printf("Ingrese la edad: \n");
            scanf("%i",&arregloAlumnos[i].edad);
            printf("Ingrese el anio de cursada: \n");
            scanf("%i",&arregloAlumnos[i].anio);
            i++;

            fwrite(&arregloAlumnos,sizeof(stAlumnos),1,fp);

            printf("Desea continuar?: \n");
            fflush(stdin);
            scanf("%c",&continuar);
        }
            fclose(fp);
    }
    else
    {
        printf("No se pudo abrir el archivo. \n");
    }
    *validos = i;
    return *validos;
}

void mostrarArchivo(FILE* fp,stAlumnos arregloAlumnos[],int validos)
{
    int i = 0;
    fp = fopen("Archivo4.bin", "rb");
    if(fp != NULL)
    {

        while((fread(&arregloAlumnos,sizeof(stAlumnos),1,fp)) > 0)
        {
            fread(&arregloAlumnos,sizeof(stAlumnos),1,fp);
            printf("LEGAJO: %i \n", arregloAlumnos[i].legajo);
            printf("NOMBRE Y APELLIDO: %s \n", arregloAlumnos[i].nombreYapellido);
            printf("EDAD: %i \n", arregloAlumnos[i].edad);
            printf("ANIO: %i \n\n", arregloAlumnos[i].anio);
            i++;

        }
        fclose(fp);

    }
    else
    {
        printf("No se pudo abrir el archivo. \n");
    }

}
