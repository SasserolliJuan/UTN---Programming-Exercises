#include <stdio.h>
#include <stdlib.h>
#define FIL 1
#define COL 4

void impresionTabla();
void cargaVotosDs(int[FIL][COL],int[FIL][COL],int[FIL][COL],int[FIL][COL],int[FIL][COL]);
int calculoTotalVotos(int[FIL][COL],int[FIL][COL],int[FIL][COL],int[FIL][COL],int[FIL][COL]);
void votosTotalXC(int[FIL][COL],int[FIL][COL],int[FIL][COL],int[FIL][COL],int[FIL][COL],int);

int main()
{
    int distrito1[FIL][COL];
    int distrito2[FIL][COL];
    int distrito3[FIL][COL];
    int distrito4[FIL][COL];
    int distrito5[FIL][COL];
    float cantidadTotalVotos = 0;
    impresionTabla();
    cargaVotosDs(distrito1,distrito2,distrito3,distrito4,distrito5);
    cantidadTotalVotos = calculoTotalVotos(distrito1,distrito2,distrito3,distrito4,distrito5);
    votosTotalXC(distrito1,distrito2,distrito3,distrito4,distrito5,cantidadTotalVotos);

}
void impresionTabla()
{
    printf("Tabla de candidatos: \n");
    printf("Distrito   Candidato A   Candidato B   Candidato C   Candidato D \n");
    printf("    1          194           48           206            45 \n");
    printf("    2          180           20           320            16 \n");
    printf("    3          221           90           140            20 \n");
    printf("    4          432           51           821            14 \n");
    printf("    5          820           61           946            18 \n");
    printf("\n");
}

void cargaVotosDs(int distrito1[FIL][COL],int distrito2[FIL][COL],int distrito3[FIL][COL],int distrito4[FIL][COL],int distrito5[FIL][COL])
{
     //CANDIDATO A          //CANDIDATO B         //CANDIDATO C          //CANDIDATO D
    distrito1[0][0] = 194, distrito1[0][1] = 48, distrito1[0][2] = 206, distrito1[0][3] = 45;
    distrito2[0][0] = 180, distrito2[0][1] = 20, distrito2[0][2] = 320, distrito2[0][3] = 16;
    distrito3[0][0] = 221, distrito3[0][1] = 90, distrito3[0][2] = 140, distrito3[0][3] = 20;
    distrito4[0][0] = 432, distrito4[0][1] = 51, distrito4[0][2] = 821, distrito4[0][3] = 14;
    distrito5[0][0] = 820, distrito5[0][1] = 61, distrito5[0][2] = 946, distrito5[0][3] = 18;
}

int calculoTotalVotos(int distrito1[FIL][COL],int distrito2[FIL][COL],int distrito3[FIL][COL],int distrito4[FIL][COL],int distrito5[FIL][COL])
{
   int cantidadTotalVotos = 0;
   int totalVotosD1 = 0, totalVotosD2 = 0, totalVotosD3 = 0, totalVotosD4 = 0, totalVotosD5 = 0;
   for(int i = 0; i < FIL; i++)
   {
       for(int j = 0; j < COL; j++)
       {
          totalVotosD1 += distrito1[i][j];
          totalVotosD2 += distrito2[i][j];
          totalVotosD3 += distrito3[i][j];
          totalVotosD4 += distrito4[i][j];
          totalVotosD5 += distrito5[i][j];
       }
    }
    cantidadTotalVotos = totalVotosD1 + totalVotosD2 + totalVotosD3 + totalVotosD4 + totalVotosD5;
    printf("Hay un total de %i votos. \n\n", cantidadTotalVotos);
    return cantidadTotalVotos;
}

void votosTotalXC(int distrito1[FIL][COL],int distrito2[FIL][COL],int distrito3[FIL][COL],int distrito4[FIL][COL],int distrito5[FIL][COL],int cantidadTotalVotos)
{
    int votosTotalCA = 0, votosTotalCB = 0, votosTotalCC = 0, votosTotalCD = 0;
    float porcentajeVotosCA = 0, porcentajeVotosCB = 0, porcentajeVotosCC = 0, porcentajeVotosCD = 0;
    for(int i = 0; i < FIL; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            if(j == 0)
        {
            votosTotalCA = distrito1[i][j] + distrito2[i][j] + distrito3[i][j] + distrito4[i][j] + distrito5[i][j];
            printf("El Candidato A tiene %i votos. \n", votosTotalCA);
            porcentajeVotosCA = (float) (votosTotalCA * 100) / cantidadTotalVotos;
            printf("El Candidato A cuenta con el %.3f porciento de los votos. \n\n", porcentajeVotosCA);
        }
        else if(j == 1)
        {
            votosTotalCB = distrito1[i][j] + distrito2[i][j] + distrito3[i][j] + distrito4[i][j] + distrito5[i][j];
            printf("El Candidato B tiene %i votos. \n", votosTotalCB);
            porcentajeVotosCB = (float) (votosTotalCB * 100) / cantidadTotalVotos;
            printf("El Candidato B cuenta con el %.3f porciento de los votos. \n\n", porcentajeVotosCB);
        }
        else if(j == 2)
        {
            votosTotalCC = distrito1[i][j] + distrito2[i][j] + distrito3[i][j] + distrito4[i][j] + distrito5[i][j];
            printf("El Candidato C tiene %i votos. \n", votosTotalCC);
            porcentajeVotosCC = (float) (votosTotalCC * 100) / cantidadTotalVotos;
            printf("El Candidato C cuenta con el %.3f porciento de los votos. \n\n", porcentajeVotosCC);
        }
        else if(j == 3)
        {
            votosTotalCD = distrito1[i][j] + distrito2[i][j] + distrito3[i][j] + distrito4[i][j] + distrito5[i][j];
            printf("El Candidato D tiene %i votos. \n", votosTotalCD);
            porcentajeVotosCD = (float) (votosTotalCD * 100) / cantidadTotalVotos;
            printf("El Candidato D cuenta con el %.3f porciento de los votos. \n\n", porcentajeVotosCD);
        }
        }
     }

      if((votosTotalCA > votosTotalCB && votosTotalCA > votosTotalCC && votosTotalCA > votosTotalCD) || porcentajeVotosCA > 50)
        {
            printf("El Candidato A es el mas votado. \n");
        }
        else if((votosTotalCB > votosTotalCA && votosTotalCB > votosTotalCC && votosTotalCB > votosTotalCD) || porcentajeVotosCB > 50)
        {
            printf("El Candidato B es el mas votado. \n");
        }
        else if((votosTotalCC > votosTotalCA && votosTotalCC > votosTotalCB && votosTotalCC > votosTotalCD) || porcentajeVotosCC > 50)
        {
            printf("El Candidato C es el mas votado. \n");
        }
        else if((votosTotalCD > votosTotalCA && votosTotalCD > votosTotalCB && votosTotalCD > votosTotalCC) || porcentajeVotosCD > 50)
        {
            printf("El Candidato D es el mas votado. \n");
        }

        if(porcentajeVotosCA > porcentajeVotosCD && porcentajeVotosCC > porcentajeVotosCD)
        {
            printf("Los Candidatos A y B pasan a la siguiente ronda. \n");
        }
        else if(porcentajeVotosCB > porcentajeVotosCA && porcentajeVotosCD > porcentajeVotosCA)
        {
            printf("Los Candidatos B y D pasan a la siguiente ronda. \n");
        }
        else if(porcentajeVotosCA > porcentajeVotosCB && porcentajeVotosCD > porcentajeVotosCB)
        {
            printf("Los Candidatos A y D pasan a la siguiente ronda. \n");
        }


}
