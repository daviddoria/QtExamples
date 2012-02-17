#ifndef MainLoopObject_h
#define MainLoopObject_h

#include <iostream>

#include <QObject>
#include <QThread>

#include "VisitorParent.h"

struct MainLoopObject : public QObject
{
Q_OBJECT
public:
  MainLoopObject(VisitorParent& vis) : visitor(vis)
  {

  }

public slots:
  void StartLoop()
  {
  std::cout << "StartLoop()" << std::endl;
  for(unsigned int i = 0; i < 10; ++i)
    {
    for(int delay = 0; delay < 1e8; ++delay)
      {
      }
    visitor.DoSomething();
    }

  this->thread()->quit();
  }

private:
  VisitorParent& visitor;
};

#endif
