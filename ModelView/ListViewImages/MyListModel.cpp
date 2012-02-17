#include "MyListModel.h"

#include <iostream>

#include <QPixmap>

MyListModel::MyListModel() : QAbstractListModel(), RowHeight(50)
{

}

int MyListModel::rowCount(const QModelIndex& parent) const
{
  return 5;
}

QVariant MyListModel::data(const QModelIndex& index, int role) const
{
  if(role == Qt::DisplayRole)
    {
    QPixmap pixmap(20,20);
    //QColor color(rand()%255,rand()%255,rand()%255);
    QColor color(index.row() * 20, index.row() * 10, index.row() * 5);
    pixmap.fill(color);
    return pixmap;
    }
  else if(role == Qt::SizeHintRole)
    {
    QSize size;
    size.setHeight(RowHeight);
    return size;
    }

  return QVariant::Invalid;
}

Qt::ItemFlags MyListModel::flags(const QModelIndex & index ) const
{
  return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

void MyListModel::SetRowHeight(const unsigned int rowHeight)
{
  this->RowHeight = rowHeight;
}
