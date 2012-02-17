#ifndef COMPUTATIONTHREAD_H
#define COMPUTATIONTHREAD_H

#include <QThread>

#include "itkSquareImageFilter.h"

class FilterComputationThreadNonTemplated : public QThread
{
Q_OBJECT
signals:
  // This signal is emitted to start the progress bar
  void StartProgressSignal();

  // This signal is emitted to stop the progress bar
  void StopProgressSignal();

};

template <typename TFilter>
class FilterComputationThread : public FilterComputationThreadNonTemplated
{
  public:

  FilterComputationThread();
  
  // This function is called when the thread is started
  void run();

  // This function is called when the thread is stopped
  void exit();

  void SetFilter(TFilter* filter);
  
private:
  TFilter* Filter;

};

#include "ComputationThread.hxx"

#endif
