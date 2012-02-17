struct Visitor
{
  void DoSomething(){};
};

int main( int argc, char **argv )
{

  Visitor visitor;
  for(unsigned int i = 0; i < 1000; ++i)
    {
    visitor.DoSomething();
    }
  return 0;
}
