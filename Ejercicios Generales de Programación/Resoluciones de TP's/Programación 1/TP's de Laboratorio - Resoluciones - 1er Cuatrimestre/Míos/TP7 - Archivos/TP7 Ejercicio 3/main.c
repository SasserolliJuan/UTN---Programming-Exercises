#include <stdio.h>
#include <stdlib.h>

void cargaNumeroEnArchivo(int numero,int*);
void mostrarNumero(int numero);
void cantElementosEnArchivo();

int main()
{
    int cantElementos = 0;
    int validos = 0;
    int numero;
    cargaNumeroEnArchivo(numero,&validos);
    mostrarNumero(numero);
    cantElementosEnArchivo();

}

void cargaNumeroEnArchivo(int numero,int* validos)
{
    int i = 0;
    FILE* fp;
    fp = fopen("Archivo2.bin", "wb");
    if(fp != NULL)
    {
        char continuar = 's';
        while(continuar == 's')
        {
           printf("Ingrese un numero: \n");
           scanf("%i",&numero);
           fwrite(&numero,sizeof(int),1,fp);
           i++;

           printf("Desea continuar?: \n");
           fflush(stdin);
           scanf("%c",&continuar);
        }
        fclose(fp);

    }
    else
    {
        printf("El archivo no se pudo abrir. \n");
    }

}

void mostrarNumero(int numero)
{

    FILE* fp;
    fp = fopen("Archivo2.bin", "rb");
    if(fp != NULL)
    {

        while(fread(&numero,sizeof(int),1,fp) > 0)
        {

           printf("%i \n",numero);

        }
        fclose(fp);

    }
    else
    {
        printf("El archivo no se pudo abrir. \n");
    }
}

void cantElementosEnArchivo()
{
    int cant = 0, numero = 0;
    FILE* fp;
    fp = fopen("Archivo2.bin", "rb");
    if(fp != NULL)
    {

        fseek(fp,sizeof(int)*0,SEEK_END);
        cant = ftell(fp) / sizeof(int);
        printf("Elementos del archivo %i",cant);
    }
    else
    {
        printf("No se pudo abrir el archivo. \n");
    }
    fclose(fp);
}
