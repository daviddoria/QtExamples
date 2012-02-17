#include <QtGui>

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
