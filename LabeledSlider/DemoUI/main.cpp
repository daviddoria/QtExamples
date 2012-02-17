#include <QApplication>

#include <LabeledSlider.h>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  LabeledSlider slider;

  slider.show();
  return app.exec();
}
