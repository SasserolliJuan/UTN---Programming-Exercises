#include <stdio.h>
#include <stdlib.h>


int main()
{
    int numero = 1;
    FILE* fp;
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



