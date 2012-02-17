#include <QtGui>

#include <iostream>

#include "form.h"
#include "PixmapDelegate.h"

Form::Form(QWidget *parent) : QWidget(parent)
{
  setupUi(this);

  this->model = new MyListModel;
  this->listView->setModel(model);

  PixmapDelegate* pixmapDelegate = new PixmapDelegate;
  this->listView->setItemDelegateForColumn(0, pixmapDelegate);

}

void Form::on_btnUpdate_clicked()
{
  std::cout << "Clicked update." << std::endl;
  this->model->AddImage();
}


void Form::on_listView_clicked(const QModelIndex & index)
{
  std::cout << index.row() << std::endl;
}
