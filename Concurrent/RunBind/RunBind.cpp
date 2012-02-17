#include <QtConcurrentRun>

#include <iostream>

#include <boost/bind.hpp>

struct MyClass1 {};
struct MyClass2 {};
struct MyClass3 {};
struct MyClass4 {};
struct MyClass5 {};
struct MyClass6 {};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
void SixArgsTemplated(T1 input1, T2 input2, T3 input3, T4 input4, T5 input5, T6 input6)
{
  for( int count = 0; count < 5; count++ )
  {
    sleep( 1 );
    std::cout << "Ping long!" << std::endl;
  }
}

void FiveArgs(MyClass1 input1, MyClass2 input2, MyClass3 input3, MyClass4 input4, MyClass5 input5)
{
  for( int count = 0; count < 5; count++ )
  {
    sleep( 1 );
    std::cout << "Ping long!" << std::endl;
  }
}

void SixArgs(MyClass1 input1, MyClass2 input2, MyClass3 input3, MyClass4 input4, MyClass5 input5, MyClass6 input6)
{
  for( int count = 0; count < 5; count++ )
  {
    sleep( 1 );
    std::cout << "Ping long!" << std::endl;
  }
}


int main(int argc, char*argv[])
{
  MyClass1 myClass1;
  MyClass2 myClass2;
  MyClass3 myClass3;
  MyClass4 myClass4;
  MyClass5 myClass5;
  QtConcurrent::run(FiveArgs, myClass1, myClass2, myClass3, myClass4, myClass5);
  
  MyClass6 myClass6;
  // Note: this does not work - a page full of errors is produced. The documentation states that you cannot call a function with more than 5 arguments with this method (use bind() instead)
  //QtConcurrent::run(SixArgs, myClass1, myClass2, myClass3, myClass4, myClass5, myClass6);
  QtConcurrent::run(boost::bind(SixArgs, myClass1, myClass2, myClass3, myClass4, myClass5, myClass6));
  //QtConcurrent::run(SixArgs<MyClass1, MyClass2, MyClass3, MyClass4, MyClass5, MyClass6>, myClass1, myClass2, myClass3, myClass4, myClass5, myClass6); // Can't pass 6 params without bind()
  QtConcurrent::run(boost::bind(SixArgsTemplated<MyClass1, MyClass2, MyClass3, MyClass4, MyClass5, MyClass6>, myClass1, myClass2, myClass3, myClass4, myClass5, myClass6));
  //QtConcurrent::run(boost::bind(SixArgsTemplated, myClass1, myClass2, myClass3, myClass4, myClass5, myClass6)); // Must specify template params

  return 0;
}
