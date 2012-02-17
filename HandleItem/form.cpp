#include <QtGui>

#include "form.h"
#include "HandleItem.h"

#include <iostream>

Form::Form(QWidget *parent) : QWidget(parent)
{
  setupUi(this);
  
  QGraphicsScene* scene = new QGraphicsScene( 0, 0, 200, 200 );

  HandleItem *centerHandle = new HandleItem( QRect( 10, 10, 50, 100 ), scene, Qt::red);

  this->graphicsView->setScene( scene );

}
