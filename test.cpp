#include <iostream>

class MyClass
{
public:
   MyClass()
   {
      std::cout << "Costruttore MyClass" << std::endl;
   }

   ~MyClass()
   {
      std::cout << "Distruttore MyClass" << std::endl;
   }
};

int main(void)
{
   MyClass myInstance;

   std::cout << "Fine programma" << std::endl;

   return 0;
}
