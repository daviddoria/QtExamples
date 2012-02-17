#include <QFileInfo>

#include <iostream>

int main(int argc, char *argv[])
{

  QFileInfo myFile("CMakeLists.txt");
  std::cout << "extension: " << myFile.suffix().toStdString() << std::endl;

  return 0;
}
