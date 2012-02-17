#include <QtConcurrentRun>

#include <iostream>

template <typename T>
void LongFunctionTemplate()
{
  for( T count = 0; count < 5; count++ )
  {
    sleep( 1 );
    std::cout << "Ping long!" << std::endl;
  }
}

int main(int argc, char*argv[])
{
  //QtConcurrent::run(LongFunctionTemplate);
  QtConcurrent::run(LongFunctionTemplate<int>);

  return 0;
}