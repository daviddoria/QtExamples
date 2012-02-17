#ifndef LabeledSlider_H
#define LabeledSlider_H

#include <QSlider>
#include <QtDesigner/QDesignerExportWidget>

#include "ui_LabeledSlider.h"

class QDESIGNER_WIDGET_EXPORT LabeledSlider : public QWidget, public Ui::LabeledSlider
{
Q_OBJECT

signals:
  void valueChanged(int);
  
public slots:
  void on_horizontalSlider_valueChanged(int);
  
public:
  LabeledSlider(QWidget *parent = 0);

  unsigned int value();

  void setMinimum(const unsigned int);
  void setMaxmimum(const unsigned int);
protected:

};

#endif
