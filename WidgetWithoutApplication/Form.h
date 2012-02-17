#ifndef Form_h
#define Form_h

#include <iostream>
#include <sstream>

#include <QApplication>
#include <QPushButton>
#include <QThread>
#include <QObject>

class Form : public QWidget
{
Q_OBJECT

public slots:

  void SetButtonText(const std::string& text)
  {
    button->setText(text.c_str());
  }
  
public:
  Form(QWidget *parent = 0) : QWidget(parent)
  {
    button = new QPushButton( "test", this );
    button->resize( 100, 30 );
    button->show();
  }

  QPushButton* button;
};

#endif
