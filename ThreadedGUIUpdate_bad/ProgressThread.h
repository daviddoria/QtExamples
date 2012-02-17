#ifndef PROGRESSTHREAD_H
#define PROGRESSTHREAD_H

#include <QThread>

#include "ComputationClass.h"

class ProgressThreadObject : public QThread
{
Q_OBJECT
public:

signals:
  // This signal is emitted to start the progress bar
  void StartProgressSignal();

  // This signal is emitted to stop the progress bar
  void StopProgressSignal();
};

class ProgressThread : public ProgressThreadObject
{
public:

  // This function is called when the thread is started
  void run();

  // This function is called when the thread is stopped
  void exit();

  void SetObject(ComputationClass*);
private:
  // We need a pointer to this object so we can perform the computations in this thread
  ComputationClass* Computation;
};

#endif