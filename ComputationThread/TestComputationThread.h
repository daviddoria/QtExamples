#ifndef TESTCOMPUTATIONTHREAD_H
#define TESTCOMPUTATIONTHREAD_H

#include <QThread>

#include "ComputationThread.h"

// This class is named 'TestComputationThreadClass' instead of just 'TestComputationThread'
// because we often want to name a member variable 'ComputationThread'
class TestComputationThreadClass : public ComputationThreadClass
{
Q_OBJECT

public:
  TestComputationThreadClass();

  void AllSteps();
  void SingleStep();

};

#endif