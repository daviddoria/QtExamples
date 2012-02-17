#include <QApplication>

#include "FloatSlider.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  FloatSlider slider;
  slider.SetMinValue(0.0f);
  slider.SetMaxValue(2.0f);

  slider.show();
  return app.exec();
}
