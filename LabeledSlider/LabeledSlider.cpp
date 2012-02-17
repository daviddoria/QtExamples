#include <iostream>

#include "LabeledSlider.h"

LabeledSlider::LabeledSlider(QWidget *parent) : QWidget(parent)
{
  setupUi(this);
  
  this->lblMinimum->setText(QString::number(this->horizontalSlider->minimum()));
  this->lblMaximum->setText(QString::number(this->horizontalSlider->maximum()));
  this->lblCurrent->setText(QString::number(this->horizontalSlider->value()));
}

unsigned int LabeledSlider::value()
{
  return this->horizontalSlider->value();
}

void LabeledSlider::setMinimum(const unsigned int value)
{
  this->horizontalSlider->setMinimum(value);
}

void LabeledSlider::setMaxmimum(const unsigned int value)
{
  this->horizontalSlider->setMaximum(value);
}

void LabeledSlider::on_horizontalSlider_valueChanged(int value)
{
  this->lblCurrent->setText(QString::number(value));
}
