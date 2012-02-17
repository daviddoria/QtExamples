#include <iostream>

#include <QApplication>
#include <QPushButton>
#include <QThread>
#include <QObject>

#include "DrawVisitor.h"

struct MainLoopObject : public QObject
{
  void StartLoop(DrawVisitor& visitor)
  {
  for(unsigned int i = 0; i < 10; ++i)
    {
    for(int delay = 0; delay < 1e8; ++delay)
      {
      }
    visitor.DoSomething();
    }
  }
};

int main( int argc, char **argv )
{
  QApplication a( argc, argv );

  DrawVisitor visitor;

  QThread* thread = new QThread;

  MainLoopObject mainLoopObject;
  (&mainLoopObject)->moveToThread(thread);
  mainLoopObject.StartLoop(visitor);
  return a.exec();
}
