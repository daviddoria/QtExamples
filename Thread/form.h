#ifndef FORM_H
#define FORM_H

#include "ui_form.h"

class Form : public QWidget, private Ui::Form
{
Q_OBJECT

public slots:

  void slot_Update();

public:
  Form(QWidget *parent = 0);

private:
  unsigned int Counter;
};

#endif
