#include <iostream>

#include "FloatSlider.h"

FloatSlider::FloatSlider(QWidget *parent) : QWidget(parent)
{
  setupUi(this);
  this->MinValue = 0.0f;
  this->MaxValue = 1.0f;

  this->lblMin->setText(QString::number(this->MinValue));
  this->lblMax->setText(QString::number(this->MaxValue));
  this->lblCurrent->setText(QString::number(GetValue()));
  
}

float FloatSlider::GetValue()
{
  return this->MinValue + (this->MaxValue - this->MinValue) * static_cast<float>(this->horizontalSlider->value()) / 100.0f;
}

void FloatSlider::on_horizontalSlider_valueChanged(int value) // 'value' is not used
{
  this->lblCurrent->setText(QString::number(GetValue()));
  emit valueChanged(GetValue());
}

void FloatSlider::SetMinValue(const float value)
{
  this->MinValue = value;
  this->lblMin->setText(QString::number(this->MinValue));
  this->lblCurrent->setText(QString::number(GetValue()));
}

void FloatSlider::SetMaxValue(const float value)
{
  this->MaxValue = value;
  this->lblMax->setText(QString::number(this->MaxValue));
  this->lblCurrent->setText(QString::number(GetValue()));
}
