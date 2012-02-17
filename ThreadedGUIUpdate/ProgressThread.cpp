#include "ProgressThread.h"
#include <iostream>

void ProgressThread::run()
{
  std::cout << "ProgressThread::run()" << std::endl;
  // When the thread is started, emit the signal to start the marquee progress bar
  emit StartProgressSignal();

  this->Computation->DoComputation();

  // When the function is finished, end the thread
  exit();
}

void ProgressThread::exit()
{
  std::cout << "ProgressThread::exit()" << std::endl;
  
  // When the thread is stopped, emit the signal to stop the marquee progress bar
  emit StopProgressSignal();
}

void ProgressThread::SetObject(ComputationClass* computation)
{
  this->Computation = computation;
}
