/* i: 12:36 pm - f: 12:40 pm Dom 23-Nov-2014 HN Programa hecho en Dev-C++ v5.8.3 como Source File, en lenguaje C.
																Y probado con exito en Code::Blocks v13.12.

   i: 5:26 pm Mar 25-Nov-2014 HN antes: Controlar teclas especiales con C (Listo-Dev-C++) 2 - copia.c, ahora: Que tecla es....c
   f: 5:52 pm Mar 25-Nov-2014 HN - Ya le borre todos lo comentarios de abajo y lineas de código omitidas, ahora 5 KB, antes 15 KB.

   Autor: Fer.Mx (fer.mx@hotmail.com)

   Modificado por Sergio Garguir;

*/

#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main()
{
	SetConsoleTitle("Que tecla es... v1.0 por Fer.Mx [24-Nov-2014]");
	char Tecla;
   int i = 9;
   printf("\n Presiona una Tecla...");
   printf("\n Presione <Enter> para restablecer los valores iniciales y limpiar pantalla.");
   printf("\n Para Salir presione 9 veces la tecla <Esc> (Presiona <Esc> por un ratito).\n");
   do
   {
      Tecla = getch();
      printf("%i - ",Tecla);
      if (Tecla == 0)
      {
		   Tecla = getch();
         switch (Tecla)
			{
         case 59:
            printf(" Presionaste: F1 - 0 %i \n",Tecla);
            break;
         case 60:
            printf(" Presionaste: F2 - 0 %i \n",Tecla);
            break;
         case 61:
            printf(" Presionaste: F3 - 0 %i \n",Tecla);
            break;
         case 62:
            printf(" Presionaste: F4 - 0 %i \n",Tecla);
            break;
         case 63:
            printf(" Presionaste: F5 - 0 %i \n",Tecla);
            break;
         case 64:
            printf(" Presionaste: F6 - 0 %i \n",Tecla);
            break;
         case 65:
            printf(" Presionaste: F7 - 0 %i \n",Tecla);
            break;
         case 66:
            printf(" Presionaste: F8 - 0 %i \n",Tecla);
            break;
         case 67:
            printf(" Presionaste: F9 - 0 %i \n",Tecla);
            break;
         case 68:
            printf(" Presionaste: F10 - 0 %i \n",Tecla);
            break;
         case 72:
            printf(" Presionaste: Flecha Arriba [Numpad] - 0 %i \n",Tecla);
            break;
         case 75:
            printf(" Presionaste: Flecha Izquierda [Numpad] - 0 %i \n",Tecla);
            break;
         case 77:
            printf(" Presionaste: Flecha Derecha [Numpad] - 0 %i \n",Tecla);
            break;
         case 80:
            printf(" Presionaste: Flecha Abajo [Numpad] - 0 %i \n",Tecla);
            break;
         case 71:
            printf(" Presionaste: Inicio [Numpad] - 0 %i \n",Tecla);
            break;
         case 73:
            printf(" Presionaste: Re P%cg [Numpad] - 0 %i \n",160,Tecla);
            break;
         case 79:
            printf(" Presionaste: Fin [Numpad] - 0 %i \n",Tecla);
            break;
         case 81:
            printf(" Presionaste: Av P%cg [Numpad] - 0 %i \n",160,Tecla);
            break;
         case 82:
            printf(" Presionaste: Insert [Numpad] - 0 %i \n",Tecla);
            break;
         case 83:
            printf(" Presionaste: Supr [Numpad] - 0 %i \n",Tecla);
            break;
			}
		}
      else if (Tecla == -32)
      {
		   Tecla = getch();
         switch (Tecla)
         {
         case 72:
            printf(" Presionaste: Flecha Arriba - -32 %i \n",Tecla);
            break;
         case 75:
            printf(" Presionaste: Flecha Izquierda - -32 %i \n",Tecla);
            break;
         case 77:
            printf(" Presionaste: Flecha Derecha - -32 %i \n",Tecla);
            break;
         case 80:
            printf(" Presionaste: Flecha Abajo - -32 %i \n",Tecla);
            break;
         case 71:
            printf(" Presionaste: Inicio - -32 %i \n",Tecla);
            break;
         case 73:
            printf(" Presionaste: Re P%cg - -32 %i \n",160,Tecla);
            break;
         case 79:
            printf(" Presionaste: Fin - -32 %i \n",Tecla);
            break;
         case 81:
            printf(" Presionaste: Av P%cg - -32 %i \n",160,Tecla);
            break;
         case 82:
            printf(" Presionaste: Insert - -32 %i \n",Tecla);
            break;
         case 83:
            printf(" Presionaste: Supr - -32 %i \n",Tecla);
            break;
         case -123:
            printf(" Presionaste: F11 - -32 %i \n",Tecla);
            break;
         case -122:
            printf(" Presionaste: F12 - -32 %i \n",Tecla);
            break;
			}
		}
      else
      {
         switch (Tecla)
         {
			case -128 ... 127:
         	switch (Tecla)
				{
         	case 8:
            	printf(" Presionaste: RETROCESO - -128 a 127 %i \n",Tecla);
            	break;
         	case 9:
            	printf(" Presionaste: TABULADOR - -128 a 127  %i \n",Tecla);
            	break;
         	case 13:
            	i = 9;
            	//system("CLS");
            	printf(" Presionaste: ENTER - -128 a 127  %i \n",Tecla);
            	break;
         	case 27:
            	printf(" Presionaste: ESC - -128 a 127  %i \n",Tecla);
            	i--;
            	break;
         	case 32:
            	printf(" Presionaste: BARRA ESPACIADORA - -128 a 127  %i \n",Tecla);
            	break;
         	default:
			   	printf(" Presionaste: %c  - -128 a 127 %i \n",Tecla, Tecla);
            	break;
				}
			}
		}
	} while (i);
   return 0;
}
