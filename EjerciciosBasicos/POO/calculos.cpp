#include "triangulo.h"
#include <iostream>

int main()
{
  double base;
  double altura;
  std::cout<< "Escriba la base del triangulo: ";
  std::cin>> base;
  std::cout<< "Escriba la altura del triangulo: ";
  std::cin>> altura;
  Triangulo *t = new Triangulo();
  std::cout<<"El resultado es: "<< t->calculo(base,altura)<<std::endl;
  delete t;
  return 0;
}
