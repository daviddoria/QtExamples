#ifndef FORM_H
#define FORM_H

#include "ui_Form.h"

// Qt
#include <QMainWindow>

// Custom
#include "ComputationThread.h"

// ITK
#include "itkSquareImageFilter.h"

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
  
  void slot_ProgressStart();
  void slot_ProgressStop();
  
protected:

  typedef itk::Image<float, 2> ImageType;
  typedef itk::SquareImageFilter <ImageType, ImageType> FilterType;
  
  FilterComputationThread<FilterType> ComputationThread;
  
  FilterType::Pointer Filter;
};

#endif // Form_H
