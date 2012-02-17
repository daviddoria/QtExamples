#include <iostream>

template<typename TFilter>
FilterComputationThread<TFilter>::FilterComputationThread()
{
  this->Filter = NULL;
}

template<typename TFilter>
void FilterComputationThread<TFilter>::run()
{
  std::cout << "ProgressThread::run()" << std::endl;
  // When the thread is started, emit the signal to start the marquee progress bar
  emit StartProgressSignal();

  this->Filter->Update();

  // When the function is finished, end the thread
  exit();
}

template<typename TFilter>
void FilterComputationThread<TFilter>::exit()
{
  std::cout << "ProgressThread::exit()" << std::endl;
  
  // When the thread is stopped, emit the signal to stop the marquee progress bar
  emit StopProgressSignal();
}

template<typename TFilter>
void FilterComputationThread<TFilter>::SetFilter(TFilter* filter)
{
  this->Filter = filter;
}
