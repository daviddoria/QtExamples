#include <QtGui>
#include <QStringListModel>

#include <iostream>

#include "form.h"

Form::Form(QWidget *parent)
    : QMainWindow(parent)
{
  setupUi(this);

  this->model = new QStringListModel;
  QStringList stringList;
  stringList.append("test0");
  stringList.append("test1");
  stringList.append("test2");
  this->model->setStringList(stringList);

  this->listView->setModel(model);

}

void Form::on_listView_clicked(const QModelIndex & index)
{
  std::cout << index.row() << std::endl;
  //QModelIndexList indexList = this->listView->selectedIndexes();
}
