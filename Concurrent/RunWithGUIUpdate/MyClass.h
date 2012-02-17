#ifndef MyClass_H
#define MyClass_H

#include <QObject>

#include <iostream>

class MyClass : public QObject
{
Q_OBJECT
public:
  MyClass(QObject* parent = 0){}

public:
  void DoSomething()
  {
    emit Update();
  }
  
signals:
   void Update();
};

#endif
