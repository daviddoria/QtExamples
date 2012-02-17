#include <iostream>

#include <QApplication>
#include <QPushButton>
#include <QThread>
#include <QObject>

#include "DrawVisitor.h"
#include "SimpleVisitor.h"
#include "MainLoopObject.h"

int main( int argc, char **argv )
{
  QApplication a( argc, argv );

  DrawVisitor visitor;
  visitor.show();

//   SimpleVisitor visitor;

  QThread* thread = new QThread;
  MainLoopObject mainLoopObject(visitor);
  (&mainLoopObject)->moveToThread(thread);

  QObject::connect(thread, SIGNAL(started()), &mainLoopObject, SLOT(StartLoop()));
  QObject::connect(thread, SIGNAL(finished()), &a, SLOT(quit()));
  thread->start();

  return a.exec();
}
