#include <QtGui>
#include <QImage>

#include "form.h"

#include <iostream>

Form::Form(QWidget *parent)
    : QWidget(parent)
{
  setupUi(this);
}

void LongFunction()
{
  for( int count = 0; count < 5; count++ )
  {
    sleep( 1 );
    std::cout << "Ping long!" << std::endl;
  }
}

void Form::on_btnOpen_clicked()
{
  QFuture<void> result = QtConcurrent::run ( LongFunction );
  //result.waitForFinished();
  
  std::cout << "exit." << std::endl;
}
