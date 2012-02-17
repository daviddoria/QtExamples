#include <QtGui>
#include <iostream>

#include "form.h"

Form::Form(QWidget *parent) : QWidget(parent)
{
  setupUi(this);
}

void Form::on_horizontalSlider_valueChanged(int value)
{
  SetLabelFromSlider();
}

void Form::SetLabelFromSlider()
{
  this->label->setText(QString::number(this->labeledSlider->value()));
}
