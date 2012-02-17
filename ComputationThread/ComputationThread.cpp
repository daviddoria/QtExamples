#include "ComputationThread.h"

ComputationThreadClass::ComputationThreadClass() : Operation(ALLSTEPS), Stop(false)
{

}

void ComputationThreadClass::StopComputation()
{
  this->Stop = true;
}

void ComputationThreadClass::run()
{
  if(this->Operation == ALLSTEPS)
    {
    AllSteps();
    }
  else if(this->Operation == SINGLESTEP)
    {
    SingleStep();
    }
}

void ComputationThreadClass::exit()
{
  // When the thread is stopped, emit the signal to stop the marquee progress bar
  emit StopProgressBarSignal();
}

void ComputationThreadClass::SetObject(ComputationObject* object)
{
  this->Object = object;
}
