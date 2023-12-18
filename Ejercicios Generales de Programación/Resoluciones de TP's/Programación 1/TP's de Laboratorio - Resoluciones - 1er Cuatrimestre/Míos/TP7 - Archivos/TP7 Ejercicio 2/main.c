#include <stdio.h>
#include <stdlib.h>

void cargaNumeroEnArchivo(FILE* fp,int numero);
void mostrarNumero(FILE* fp,int numero);

int main()
{

    int numero = 1;
    FILE* fp;
    cargaNumeroEnArchivo(&fp,numero);
    mostrarNumero(&fp,numero);

}

void cargaNumeroEnArchivo(FILE* fp,int numero)
{
    fp = fopen("Archivo1.bin", "wb");
    if(fp != NULL)
    {
        fwrite(&numero,sizeof(int),1,fp);
        fclose(fp);
    }
    else
    {
        printf("El archivo no se pudo abrir. \n");
    }

}

void mostrarNumero(FILE* fp,int numero)
{
    fp = fopen("Archivo1.bin", "rb");
    if(fp != NULL)
    {
        fread(&numero,sizeof(int),1,fp);
        printf("%i",numero);
        fclose(fp);
    }
    else
    {
        printf("El archivo no se pudo abrir. \n");
    }

}
