#include "MyTableModel.h"

#include <iostream>
#include <sstream>

#include <QLabel>
#include <QPainter>
#include <QPixmap>
#include <QStyledItemDelegate>



MyTableModel::MyTableModel() : QAbstractTableModel()
{
  
}

int MyTableModel::rowCount(const QModelIndex& parent) const
{
  return 5;
}

int MyTableModel::columnCount(const QModelIndex& parent) const
{
  return 2;
}

QVariant MyTableModel::data(const QModelIndex& index, int role) const
{
  if(role == Qt::DisplayRole)
    {
    if(index.column() == 0)
      {
      return index.row();
      }
    else if(index.column() == 1)
      {
      //std::cout << "Creating image." << std::endl;
      QPixmap pixmap(20,20);
      QColor black(0,0,0);
      pixmap.fill(black);
      return pixmap;
      }
    }

  return QVariant::Invalid;
}

Qt::ItemFlags MyTableModel::flags(const QModelIndex & index ) const
{
  return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}
