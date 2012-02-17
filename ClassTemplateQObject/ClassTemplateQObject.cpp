#include <QApplication>

#include "form.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  Form<int> form;
  
  form.show();
  return app.exec();
}
