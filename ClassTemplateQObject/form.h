#ifndef FORM_H
#define FORM_H

#include "ui_form.h"

#include <QMainWindow>

// Error: Template classes not supported by Q_OBJECT
// template <typename T>
// class Form : public QMainWindow, private Ui::MainWindow
// {
//     Q_OBJECT
// 
// public:
//     Form(QWidget *parent = 0);
// 
//   public slots:
// 
// };

class FormParent : public QMainWindow, private Ui::MainWindow
{
Q_OBJECT
public:
  FormParent(QWidget *parent): QMainWindow(parent)
  {
    setupUi(this);
  }
public slots:
  virtual void Test() = 0;
};

template <typename T>
class Form : public FormParent
{
public:
  Form(QWidget *parent = 0);

  public:
    void Test();
};

#include "form.hpp"

#endif
