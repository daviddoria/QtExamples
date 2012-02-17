#include <QApplication>
#include <QObject>
#include <QThread>

#include <iostream>

#include "form.h"
#include "MyClass.h"

int main(int argc, char*argv[])
{
  QApplication app(argc, argv);

  Form form;

  form.show();

  QThread* thread = new QThread;

  MyClass* myClass = new MyClass;
  myClass->moveToThread(thread);
  QObject::connect(thread, SIGNAL(started()), myClass, SLOT(start()));
  QObject::connect(myClass, SIGNAL(finished()), thread, SLOT(quit()));
  QObject::connect(myClass, SIGNAL(Update()), &form, SLOT(slot_Update()));
  
  thread->start();
  
  return app.exec();
}