#ifndef DrawVisitor_h
#define DrawVisitor_h

#include <iostream>
#include <sstream>

#include <QApplication>
#include <QPushButton>
#include <QThread>
#include <QObject>

#include "Form.h"

class DrawVisitor : public QWidget
{
Q_OBJECT

signals:
  void Refresh(const std::string&);

public:
  DrawVisitor(QWidget *parent = 0) : QWidget(parent), counter(0)
  {
    form = new Form;
    form->show();

    connect(this, SIGNAL(Refresh(std::string)), form, SLOT(SetButtonText(const std::string& text)));
  }

  void DoSomething()
  {
    counter++;
    std::stringstream ss;
    ss << counter;
    emit Refresh(ss.str());
  }

  Form* form;
  unsigned int counter;
};

#endif
