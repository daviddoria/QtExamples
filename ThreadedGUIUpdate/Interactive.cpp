#include <QApplication>
#include <QCleanlooksStyle>

#include "Form.h"

int main( int argc, char** argv )
{
  QApplication app( argc, argv );

  QApplication::setStyle(new QCleanlooksStyle);

  Form myForm;
  myForm.show();

  return app.exec();
}
