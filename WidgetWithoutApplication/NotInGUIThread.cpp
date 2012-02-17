#include <iostream>

#include <QApplication>
#include <QPushButton>
#include <QThread>

struct DrawVisitor
{
  void DoSomething()
  {
    std::cout << "DoSomething()" << std::endl;
    QPushButton hello( "Hello world!", 0 );
    hello.resize( 100, 30 );
    hello.show();
  }
};

struct MainLoopObject : public QObject
{
  void StartLoop(DrawVisitor& visitor)
  {
  for(unsigned int i = 0; i < 10; ++i)
    {
    visitor.DoSomething();
    }
  }
};

int main( int argc, char **argv )
{
  QApplication a( argc, argv );

  DrawVisitor visitor;

  QThread* thread = new QThread;

  MainLoopObject mainLoopObject;
  (&mainLoopObject)->moveToThread(thread);
  mainLoopObject.StartLoop(visitor);
  return a.exec();
}
