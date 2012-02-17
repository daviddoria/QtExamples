#include <QtConcurrentRun>

#include <iostream>

struct MyClass {};

template <typename T>
void LongFunctionTemplate(T input)
{
  for( int count = 0; count < 5; count++ )
  {
    sleep( 1 );
    std::cout << "Ping long!" << std::endl;
  }
}

struct MyClass1 {};
struct MyClass2 {};
struct MyClass3 {};
struct MyClass4 {};
struct MyClass5 {};
struct MyClass6 {};

template <typename T1, typename T2>
void TwoArgs(T1 input1, T2 input2)
{
  for( int count = 0; count < 5; count++ )
  {
    sleep( 1 );
    std::cout << "Ping long!" << std::endl;
  }
}

template <typename T1, typename T2, typename T3>
void ThreeArgs(T1 input1, T2 input2, T3 input3)
{
  for( int count = 0; count < 5; count++ )
  {
    sleep( 1 );
    std::cout << "Ping long!" << std::endl;
  }
}

template <typename T1, typename T2, typename T3, typename T4, typename T5>
void FiveArgs(T1 input1, T2 input2, T3 input3, T4 input4, T5 input5)
{
  for( int count = 0; count < 5; count++ )
  {
    sleep( 1 );
    std::cout << "Ping long!" << std::endl;
  }
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
void SixArgs(T1 input1, T2 input2, T3 input3, T4 input4, T5 input5, T6 input6)
{
  for( int count = 0; count < 5; count++ )
  {
    sleep( 1 );
    std::cout << "Ping long!" << std::endl;
  }
}


int main(int argc, char*argv[])
{
//   MyClass myClass;
//   QtConcurrent::run(LongFunctionTemplate<MyClass>, myClass);

  MyClass1 myClass1;
  MyClass2 myClass2;
  QtConcurrent::run(TwoArgs<MyClass1, MyClass2>, myClass1, myClass2);
  
  MyClass3 myClass3;
  QtConcurrent::run(ThreeArgs<MyClass1, MyClass2, MyClass3>, myClass1, myClass2, myClass3);
  
  MyClass4 myClass4;
  MyClass5 myClass5;
  QtConcurrent::run(FiveArgs<MyClass1, MyClass2, MyClass3, MyClass4, MyClass5>, myClass1, myClass2, myClass3, myClass4, myClass5);
  
  MyClass6 myClass6;
  // Note: this does not work - a page full of errors is produced. The documentation states that you cannot call a function with more than 5 arguments with this method (use bind() instead)
  //QtConcurrent::run(SixArgs<MyClass1, MyClass2, MyClass3, MyClass4, MyClass5, MyClass6>, myClass1, myClass2, myClass3, myClass4, myClass5, myClass6);

  return 0;
}
