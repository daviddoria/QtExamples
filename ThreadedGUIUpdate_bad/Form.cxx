#include "ui_Form.h"
#include "Form.h"

#include <iostream>
#include <sstream>

// Qt
#include <QFileDialog>
#include <QIcon>
#include <QTextEdit>


// Constructor
Form::Form()
{
  this->setupUi(this);
  
  connect(&Computation, SIGNAL(RefreshSignal()), this, SLOT(RefreshSlot()), Qt::QueuedConnection);
  
  ComputationThread.SetObject(&(this->Computation));
  
};


void Form::RefreshSlot()
{
  std::cout << "Form::RefreshSlot()" << std::endl;
  Refresh();
}

void Form::Refresh()
{
  std::cout << "Refresh()" << std::endl;
  float newValue = this->lineEdit->text().toFloat() + 1.;
  std::stringstream ss;
  ss << newValue;
  this->lineEdit->setText(ss.str().c_str());
}

void Form::on_pushButton_clicked()
{
  std::cout << "on_btnInpaint_clicked()" << std::endl;
  
  ComputationThread.start();
}
