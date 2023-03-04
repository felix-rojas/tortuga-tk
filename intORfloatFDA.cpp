// Este programa implementa el algoritmo de reconocimiento de un lenguaje
// (entrada) a trav s de un DFA. 

// Constantes binarias: contienen sólo unos y ceros y terminan con la letra B. Nunca comienzan con cero.
// 1(1|0)*B
// Comentarios: comienzan con /* y terminan con */ 
// \/\*
// conteniendo cualquier caracter entre esos delimitadores.
// Identificadores abecedarios: son todos las palabras aceptadas por la siguiente expresión regular: ((b|c)a(c|d)a)+ # 


using namespace std;
#include <iostream>
//Matriz de transiciones
//                     1, [2-9] +,-   .    B    0   del  otros 
int MT[6][8] = /*0*/{{ 1 ,  2 ,  3 , 200, 200,  2 , 200, 200},
               /*1*/ { 1 ,  2 , 200,  4 ,  5 ,  1 , 102, 200}, //
               /*2*/ { 2 ,  2 , 200,  4 , 200,  2 , 102, 200},
               /*3*/ { 3 ,  3 , 200,  4 , 200,  3 , 101, 200},
               /*4*/ { 4 ,  4 , 200, 200, 200,  4 , 100, 200},
               /*5*/ {200, 200, 200, 200, 200, 200, 111, 200}};
                
int filtro (char c)
{ switch (c)
  { 
 case '0':
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