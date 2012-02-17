#ifndef FloatSlider_H
#define FloatSlider_H

#include <QSlider>
#include <QtDesigner/QDesignerExportWidget>

#include "ui_FloatSlider.h"

class QDESIGNER_WIDGET_EXPORT FloatSlider : public QWidget, public Ui::FloatSlider
{
Q_OBJECT

signals:
  void valueChanged(float);

public slots:
  void on_horizontalSlider_valueChanged(int);
  
public:
  FloatSlider(QWidget *parent = 0);

  float GetValue();
  void SetMinValue(const float);
  void SetMaxValue(const float);
  
protected:
  float MinValue;
  float MaxValue;
};

#endif
