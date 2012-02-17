#include <QtConcurrentRun>

#include <iostream>


// void LongFunction()
// {
//   for( int count = 0; count < 5; count++ )
//   {
//     sleep( 1 );
//     std::cout << "Ping long!" << std::endl;
//   }
// }

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
  //QtConcurrent::run(LongFunction);
  QtConcurrent::run(LongFunctionTemplate);

  return 0;
}