// FDA language recognition 
// Modified by Félix Javier Rojas Gallardo


//Matriz de transiciones
// uint =    101  -> integer without a sign
// sint =    102  -> integer with a + or - sign
// float =   103  -> float with a + or - sign or no sign
// bin =     104  -> any string of 1's and 0's that begins with a 1 and ends with a B
// comment = 105  -> /*asjkdaslkd*/ any characters in between EXCEPT spaces or newline
// regex =   106  -> ((b|c)a(c|d)a)+ #

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

// file testing
// text file requires a blank space and return at the end of each instruction

int ReadFile(std::string filename) {
   std::ifstream datafile(filename);
   if(!datafile) {
    std::cerr << "Could not open file" << std::endl;
    std::cerr << "Error code: " << strerror(errno) << std::endl;
    return -1;
   }

   std::string data = "";
   while (getline(datafile, data))
   {
    std::cout << data << std::endl;
   }
   datafile.close();
   return 0;
}
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
                /*13*/ {200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200,  14,  14, 200}, // c || d 
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
  std::string filename = "./tests.txt";
  std::ifstream datafile(filename);
   if(!datafile) {
    std::cerr << "Could not open file" << std::endl;
    std::cerr << "Error code: " << strerror(errno) << std::endl;
    return -1;
   }

   std::string data = "";
   while (getline(datafile, data))
   {
  int i = 0;
  char c;
  int estado = 0;
  while (estado < 100) //Menor 100 porque es cualquier estado que si son aceptables 
  { c = data[i++];
    estado = mt[estado][filtro(c)];
    // std::cout << estado << std::endl; in case you need to see how it moves through states
    if (estado==101) std::cout << "is uint\n";
      else if (estado==102) std::cout << "is sint\n";
      else if (estado==103) std::cout << "is float\n";
      else if (estado==104) std::cout << "is bin\n";
      else if (estado==105) std::cout << "is comment\n";
      else if (estado==106) std::cout << "is regex\n";
      else if (estado==200) std::cout << "is error \n";
  }

   }
   datafile.close();
   std::cout<<"Fin del analisis"<< std::endl;
   return 0;
}
