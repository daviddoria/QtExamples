#include <QApplication>
#include <QObject>
#include <QtConcurrentRun>

#include <iostream>

#include "form.h"
#include "LongFunction.h"

int main(int argc, char*argv[])
{
  QApplication app(argc, argv);

  Form form;

  form.show();

  MyClass myClass;
  QObject::connect(&myClass, SIGNAL(Update()), &form, SLOT(slot_Update()));
  QtConcurrent::run ( LongFunction, &myClass );
  
  return app.exec();
}
