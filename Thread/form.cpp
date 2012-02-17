#include <QtGui>

#include "form.h"

#include <iostream>
#include <sstream>

Form::Form(QWidget *parent)
    : QWidget(parent), Counter(0)
{
  setupUi(this);
}

void Form::slot_Update()
{
  Counter++;
  std::stringstream ss;
  ss << Counter;
  this->label->setText(ss.str().c_str());
}
