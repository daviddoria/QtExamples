#include <QtGui>
#include <QImage>

#include "form.h"
#include "MyClass.h"

#include <iostream>
#include <sstream>

Form::Form(QWidget *parent)
    : QWidget(parent), Counter(0)
{
  setupUi(this);
}

void Form::on_btnGo_clicked()
{
  QThread* thread = new QThread;

  MyClass* myClass = new MyClass;
  myClass->moveToThread(thread);
  connect(thread, SIGNAL(started()), myClass, SLOT(start()));
  connect(myClass, SIGNAL(finished()), thread, SLOT(quit()));
  connect(myClass, SIGNAL(Update()), this, SLOT(slot_Update()));
  thread->start();

  std::cout << "exit." << std::endl;
}

void Form::slot_Update()
{
  Counter++;
  std::stringstream ss;
  ss << Counter;
  this->label->setText(ss.str().c_str());
}
