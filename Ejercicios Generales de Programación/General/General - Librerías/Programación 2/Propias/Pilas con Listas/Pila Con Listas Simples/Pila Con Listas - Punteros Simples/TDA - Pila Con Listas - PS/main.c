#include "Pila_Con_Listas_PS.h"

int main()
{
   Pila * p;
   inicpila(&p);

   int dato = 0;

   apilar(&p, 10);
   apilar(&p, 20);
   apilar(&p, 30);
   desapilar(&p);
   leer(&p);

   mostrar(&p);
   dato = tope(&p);
   printf("Tope de la pila: %i \n", dato);

   pilavacia(&p);
   mostrar(&p);
}
