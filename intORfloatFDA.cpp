// Este programa implementa el algoritmo de reconocimiento de un lenguaje
// (entrada) a trav s de un DFA. 
using namespace std;
#include <iostream>
//Matriz de transiciones
//              dig +,-   .   del  otro
int MT[5][5] = {{1,   2, 200, 200, 200},
                {1, 200,   3, 101, 200}, //
                {1, 200, 200, 200, 200},
                {4, 200, 200, 200, 200},
                {4, 200, 200, 100, 200}};
                
int filtro (char c)
{ switch (c)
  { case    '0':
 case '1':
 case '2':
 case '3':
 case '4':
 case '5':
 case '6':
 case '7':
 case '8':
 case '9': return 0;
 case '+':
 case '-': return 1;
 case '.': return 2;
 case ' ':
   case '\0': return 3;
 default: return 4;
  }
 }
 
int main(int argc, char** argv)
{ 
  while (argc != 0) {
  char entrada[80];
  cout << "Dame la entrada a evaluar: ";
  cin >> entrada;
  int i = 0;
  char c;
  int estado = 0;
  while (estado < 100) //Menor 100 porque es cualquier estado que si son aceptables 
  { c = entrada[i++];
    estado = MT[estado][filtro(c)];
    if (estado == 100)
      cout << "Flotante aceptado.\n";
    else if (estado == 101)
      cout<<"Entero aceptado"<<endl;  
    else
      if (estado == 200)
        cout << "ERROR en la entrada.\n";
  }
  cout<<"Fin del analisis"<<endl;
  }
}