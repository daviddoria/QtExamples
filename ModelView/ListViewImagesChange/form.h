#ifndef FORM_H
#define FORM_H

#include "ui_form.h"

#include "MyListModel.h"

class Form : public QWidget, public Ui::Form
{
Q_OBJECT

public:

  Form(QWidget *parent = 0);

public slots:
  void on_btnUpdate_clicked();
  void on_listView_clicked(const QModelIndex & index);

private:
  MyListModel* model;
};

#endif
