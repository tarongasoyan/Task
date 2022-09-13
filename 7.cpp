#include <iostream>

class Base {
public:
  void play() {}
};

class Derived: public Base {
public:
  void go(){}
};

int main( ) 
{ 
  Base obj1;
  Derived obj2;

  //upcast
  Base *ptrBase = &obj2; 

  //downcast
  Derived *ptrDerived = (Derived*)&obj1;

  ptrBase -> play();
  ptrDerived -> go();
    
  return 0; 
}