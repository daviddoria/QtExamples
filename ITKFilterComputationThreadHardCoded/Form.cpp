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

  this->Filter = itk::SquareImageFilter <ImageType, ImageType>::New();
  
  ImageType::Pointer image = ImageType::New();
  this->Filter->SetInput(image);
  
  this->MyThread.SetFilter(this->Filter);
  connect(&MyThread, SIGNAL(StartProgressSignal()), this, SLOT(slot_ProgressStart()));
  connect(&MyThread, SIGNAL(StopProgressSignal()), this, SLOT(slot_ProgressStop()));
};

void Form::slot_ProgressStart()
{
  std::cout << "slot_ProgressStart()" << std::endl;
}

void Form::slot_ProgressStop()
{
  std::cout << "slot_ProgressStop()" << std::endl;
}

void Form::on_pushButton_clicked()
{
  std::cout << "clicked()" << std::endl;
  
  MyThread.start();
}
