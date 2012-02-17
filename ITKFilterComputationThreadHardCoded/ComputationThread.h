#ifndef COMPUTATIONTHREAD_H
#define COMPUTATIONTHREAD_H

#include <QThread>

#include "itkSquareImageFilter.h"

class ComputationThread : public QThread
{
Q_OBJECT
signals:
  // This signal is emitted to start the progress bar
  void StartProgressSignal();

  // This signal is emitted to stop the progress bar
  void StopProgressSignal();
public:

  ComputationThread();
  
  // This function is called when the thread is started
  void run();

  // This function is called when the thread is stopped
  void exit();

  typedef itk::Image<float, 2> ImageType;

  void SetFilter(itk::SquareImageFilter <ImageType, ImageType>* filter);
  
private:
  itk::SquareImageFilter <ImageType, ImageType>* Filter;

};

#endif
