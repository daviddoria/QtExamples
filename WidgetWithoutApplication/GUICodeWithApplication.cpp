#include <iostream>

#include <QApplication>
#include <QPushButton>

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

int main( int argc, char **argv )
{
  QApplication a( argc, argv );
  DrawVisitor visitor;
  for(unsigned int i = 0; i < 1000; ++i)
    {
    visitor.DoSomething();
    }
  return a.exec();
}
