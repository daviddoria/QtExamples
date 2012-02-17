#include "ComputationThread.h"
#include <iostream>

ComputationThread::ComputationThread()
{
  this->Filter = NULL;
}

void ComputationThread::run()
{
  std::cout << "ProgressThread::run()" << std::endl;
  // When the thread is started, emit the signal to start the marquee progress bar
  emit StartProgressSignal();

  this->Filter->Update();

  // When the function is finished, end the thread
  exit();
}

void ComputationThread::exit()
{
  std::cout << "ProgressThread::exit()" << std::endl;
  
  // When the thread is stopped, emit the signal to stop the marquee progress bar
  emit StopProgressSignal();
}

void ComputationThread::SetFilter(itk::SquareImageFilter <ImageType, ImageType>* filter)
{
  this->Filter = filter;
}
