#ifndef COMPUTATIONTHREAD_H
#define COMPUTATIONTHREAD_H

#include <QThread>

#include "ComputationObject.h"

// This class is named 'ComputationThreadClass' instead of just 'ComputationThread'
// because we often want to name a member variable 'ComputationThread'
class ComputationThreadClass : public QThread
{
Q_OBJECT

signals:
  // This signal is emitted to start the progress bar
  void StartProgressBarSignal();

  // This signal is emitted to stop the progress bar
  void StopProgressBarSignal();

  void RefreshSignal();
  
  void IterationCompleteSignal();
  void StepCompleteSignal();
  
public:
  ComputationThreadClass();

  // Store the type of operation to perform.
  enum OPERATION {ALLSTEPS, SINGLESTEP};
  OPERATION Operation;

  // This function is called when the thread is started.
  void run();

  virtual void AllSteps() = 0;
  virtual void SingleStep() = 0;

  // This function is called when the thread is stopped.
  void exit();

  void StopComputation();

  // Provide the object with which to do the computation.
  void SetObject(ComputationObject*);
  
protected:
  // We need a pointer to this object so we can perform the computations in this thread
  ComputationObject* Object;
  
  // This flag can be set from another thread (by calling StopInpainting()) to indicate that we want to stop the computation at the next possible opportunity.
  bool Stop;
};

#endif