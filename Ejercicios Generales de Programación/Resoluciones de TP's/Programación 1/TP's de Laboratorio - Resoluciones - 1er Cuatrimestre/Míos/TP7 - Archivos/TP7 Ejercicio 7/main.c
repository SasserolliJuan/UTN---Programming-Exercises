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

int cargaDeAlumnosEnArchivo(stAlumnos*);
void mostrarArchivo();

int main()
{
    stAlumnos p;
    FILE* fp;
    Pila a;
    inicpila(&a);
    int edad = 18;
    int validos = 0;
    cargaDeAlumnosEnArchivo(&p);
    mostrarArchivo();

}



int cargaDeAlumnosEnArchivo(stAlumnos* p)
{
    char continuar = 's';
    int i = 0;

    FILE* fp;
    fp = fopen("Archivo4.bin","wb");
    if(fp != NULL)
    {
        while(continuar == 's')
        {
            printf("Ingrese el numero de legajo: \n");
            scanf("%i", &(*p).legajo);
            printf("Ingrese nombre y apellido: \n");
            fflush(stdin);
            gets((*p).nombreYapellido);
            printf("Ingrese la edad: \n");
            scanf("%i",&(*p).edad);
            printf("Ingrese el anio de cursada: \n");
            scanf("%i",&(*p).anio);
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
}


void mostrarArchivo(stAlumnos arregloAlumnos[])
{
    int i = 0;
    stAlumnos p;
    FILE* fp;
    fp = fopen("Archivo4.bin", "rb");
    if(fp != NULL)
    {

        while((fread(&arregloAlumnos,sizeof(stAlumnos),1,fp)) > 0)
        {
            fread(&arregloAlumnos,sizeof(stAlumnos),1,fp);
            printf("LEGAJO: %i \n", p.legajo);
            printf("NOMBRE Y APELLIDO: %s \n", p.nombreYapellido);
            printf("EDAD: %i \n", p.edad);
            printf("ANIO: %i \n\n", p.anio);
            i++;

        }
        fclose(fp);

    }
    else
    {
        printf("No se pudo abrir el archivo. \n");
    }

}

void filtroXEdad(FILE* fp,stAlumnos arregloAlumnos[],int validos,int edad,Pila* a)
{
    int i = 0;
    fp = open("Archivo5.bin", "rb");
    if(fp != NULL)
    {
        while(fread(&arregloAlumnos,sizeof(stAlumnos),1,fp) > 0)
        {
            if(arregloAlumnos[i].edad >= 18)
            {
                apilar(a,arregloAlumnos[i].edad);
                i++;
            }
        }
    }
    fclose(fp);
    mostrar(&a);
}
