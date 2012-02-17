#ifndef ComputationClass_H
#define ComputationClass_H

// QT
#include <QObject>

class ComputationClass : public QObject
{
  Q_OBJECT
signals:
  void RefreshSignal();
  
public:

  // The real work is done here.
  void DoComputation();

private:

  
};

#endif