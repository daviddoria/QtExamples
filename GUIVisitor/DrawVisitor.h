#ifndef DrawVisitor_h
#define DrawVisitor_h

#include <iostream>
#include <sstream>

#include <QApplication>
#include <QPushButton>
#include <QThread>
#include <QObject>

#include "VisitorParent.h"

class DrawVisitor : public QWidget, public VisitorParent
{
Q_OBJECT

public:
  DrawVisitor(QWidget *parent = 0) : QWidget(parent), counter(0)
  {
    button = new QPushButton( "test", this );
    button->resize( 100, 30 );
    button->show();
  }

  void DoSomething()
  {
    std::cout << "DoSomething()" << std::endl;
    counter++;
    std::stringstream ss;
    ss << counter;
    button->setText(ss.str().c_str());
  }

  QPushButton* button;
  unsigned int counter;
};

#endif
