#include "TestComputationThread.h"

TestComputationThreadClass::TestComputationThreadClass() : ComputationThreadClass()
{

}

void TestComputationThreadClass::AllSteps()
{
  emit StartProgressBarSignal();

  // Start the procedure
  this->Stop = false;

  while(!this->Stop)
    {
    this->Object->Step();
    emit IterationCompleteSignal();
    }

  // When the function is finished, end the thread
  exit();
}

void TestComputationThreadClass::SingleStep()
{
  //std::cout << "ProgressThread::run()" << std::endl;
  // When the thread is started, emit the signal to start the marquee progress bar
  emit StartProgressBarSignal();

  this->Object->Step();
  
  emit IterationCompleteSignal();
  emit StepCompleteSignal();

  // When the function is finished, end the thread
  exit();
}
