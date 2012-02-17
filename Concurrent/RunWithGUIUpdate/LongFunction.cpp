#include "LongFunction.h"

void LongFunction(MyClass* myClass)
{
  for( int count = 0; count < 5; count++ )
  {
    sleep( 1 );
    std::cout << "Ping long!" << std::endl;
    myClass->DoSomething();
  }
}
