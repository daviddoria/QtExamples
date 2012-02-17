#include "ComputationClass.h"

#include <iostream>

void ComputationClass::DoComputation()
{
  std::cout << "ComputationClass::DoComputation()" << std::endl;
  // Big computation is done here
  // ...
  emit RefreshSignal();
  // ...
}
