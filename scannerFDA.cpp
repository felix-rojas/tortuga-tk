// Este programa implementa el algoritmo de reconocimiento de un lenguaje
// (entrada) a trav s de un DFA. 

// Constantes binarias: contienen sólo unos y ceros y terminan con la letra B. Nunca comienzan con cero.
// 1(1|0)*B
// Comentarios: comienzan con /* y terminan con */ 
// \/\*
// conteniendo cualquier caracter entre esos delimitadores.
// Identificadores abecedarios: son todos las palabras aceptadas por la siguiente expresión regular: ((b|c)a(c|d)a)+ # 

#include <iostream>
using namespace std;
//Matriz de transiciones
//                     1, [2-9] +,-   .    B    0   del  otros 
int MT[6][8] = /*0*/{{ 1 ,  2 ,  3 , 200, 200,  2 , 200, 200},
               /*1*/ { 1 ,  2 , 200,  4 ,  5 ,  1 , 102, 200}, //
               /*2*/ { 2 ,  2 , 200,  4 , 200,  2 , 102, 200},
               /*3*/ { 3 ,  3 , 200,  4 , 200,  3 , 101, 200},
               /*4*/ { 4 ,  4 , 200, 200, 200,  4 , 100, 200},
               /*5*/ {200, 200, 200, 200, 200, 200, 111, 200}};

//Matriz de transiciones
// uint = 101
// sint = 102
// float = 103
// bin = 104
// comment = 105
// regex = 106
//                       1    0  [2-9] +,-   .    B    /    *  othrs  a    b    c    d   del
int mt[16][14] =/*0*/{ { 5 ,  1 ,  1 ,  4 , 200, 200,  7 , 200, 200, 200,  11, 12,  200, 200}, //done, first input state
                /*1*/  { 1 ,  1 ,  1 , 200,  2 , 200, 200, 200, 200, 200, 200, 200, 200, 101}, // uint OR float
                /*2*/  { 3 ,  3 ,  3 , 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200}, //done, float solving
                /*3*/  { 3 ,  3 ,  3,  200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 103}, //done float
                /*4*/  { 4 ,  4 ,  4 , 200,  2 , 200, 200, 200, 200, 200, 200, 200, 200, 102}, // signed int
                /*5*/  { 5 ,  5 ,  1 , 200,  2 , 6 ,  200, 200, 200, 200, 200, 200, 200, 200}, //maybe bin?
                /*6*/  {200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 104}, //binary
                /*7*/  {200, 200, 200, 200, 200, 200, 200,  8 , 200, 200, 200, 200, 200, 200}, //begin comment
                /*8*/  { 8 ,  8 ,  8 ,  8 ,  8 ,  8 ,  8 ,  9 ,  8 ,  8 ,  8 ,  8 ,  8 ,  8 }, // at least one *
                /*9*/  { 9 ,  9 ,  9 ,  9 ,  9 ,  9 , 10 ,  9 ,  9 ,  9 ,  9 ,  9 ,  9 ,  9 }, // anything until slash
                /*10*/ {200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 105}, //comment
                /*11*/ {200, 200, 200, 200, 200, 200, 200, 200, 200, 13,  200, 200, 200, 200}, // b first
                /*12*/ {200, 200, 200, 200, 200, 200, 200, 200, 200, 13,  200, 200, 200, 200}, // c first
                /*13*/ {200, 200, 200, 200, 200, 200, 200, 200, 200, 200,  14,  14, 200, 200}, // c || d 
                /*14*/ {200, 200, 200, 200, 200, 200, 200, 200, 200,  15, 200, 200, 200, 200}, // get a
                /*15*/ {200, 200, 200, 200, 200, 200, 200, 200, 200, 200,  11,  12, 200, 106}}; // regex

int filtro (char c)
{ switch (c)
  { 
 case '1': return 0;
 case '0': return 1;
 case '2':
 case '3':
 case '4':
 case '5':
 case '6':
 case '7':
 case '8':
 case '9': return 2;
 case '+':
 case '-': return 3;
 case '.': return 4;
 case 'B': return 5;
 case '/': return 6;
 case '*': return 7;
 case 'a': return 9;
 case 'b': return 10;
 case 'c': return 11;
 case 'd': return 12;
 case ' ':
 case '\0': return 13;
  default: return 8;
  }
 }

 
int main()
{ 
  char entrada[80];
  std::cout << "Dame la entrada a evaluar: ";
  std::cin >> entrada;
  int i = 0;
  char c;
  int estado = 0;
  while (estado < 100) //Menor 100 porque es cualquier estado que si son aceptables 
  { c = entrada[i++];
    estado = mt[estado][filtro(c)];
    std::cout << estado << std::endl;
    if (estado==101) std::cout << "is uint\n";
      else if (estado==102) std::cout << "is sint\n";
      else if (estado==103) std::cout << "is float\n";
      else if (estado==104) std::cout << "is bin\n";
      else if (estado==105) std::cout << "is comment\n";
      else if (estado==106) std::cout << "is regex\n";
  }
  std::cout<<"Fin del analisis"<<endl;
}
