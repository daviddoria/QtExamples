#ifndef SimpleVisitor_h
#define SimpleVisitor_h

#include <iostream>

#include "VisitorParent.h"

class SimpleVisitor : public VisitorParent
{
public:

  void DoSomething()
  {
    std::cout << "SimpleVisitor::DoSomething()" << std::endl;
  }

};

#endif
