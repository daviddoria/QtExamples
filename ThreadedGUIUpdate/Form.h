#ifndef FORM_H
#define FORM_H

#include "ui_Form.h"

// Qt
#include <QMainWindow>

// Custom
#include "ComputationClass.h"
#include "ProgressThread.h"


class Form : public QMainWindow, public Ui::Form
{
  Q_OBJECT
public:

  // Constructor/Destructor
  Form();
  ~Form() {};
  
  void Refresh();
  
public slots:
  
  void on_pushButton_clicked();
  
  void RefreshSlot();
  
protected:
  
  ComputationClass Computation;
  
  ProgressThread ComputationThread;
};

#endif // Form_H
