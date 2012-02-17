// Does not run properly : QWidget: Must construct a QApplication before a QPaintDevice

#include <QPushButton>

struct DrawVisitor
{
  void DoSomething()
  {
    QPushButton hello( "Hello world!", 0 );
    hello.resize( 100, 30 );
    hello.show();
  }
};

int main( int argc, char **argv )
{
  DrawVisitor visitor;
  for(unsigned int i = 0; i < 1000; ++i)
    {
    visitor.DoSomething();
    }
  return 0;
}
