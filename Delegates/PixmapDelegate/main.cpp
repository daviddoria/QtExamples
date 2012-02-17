#include <QApplication>
#include <QHeaderView>
#include <QItemSelectionModel>
#include <QStandardItemModel>
#include <QListView>

#include <iostream>

#include "PixmapDelegate.h"


int main(int argc, char *argv[])
{
  std::cout << "Enter." << std::endl;
  QApplication app(argc, argv);

  QStandardItemModel model(4, 1);
  QListView listView;
  listView.setModel(&model);

  PixmapDelegate delegate;

  listView.setItemDelegate(&delegate);
  //listView.setItemDelegateForColumn(0, &delegate);

//   for (int row = 0; row < 4; ++row)
//     {
//     for (int column = 0; column < 2; ++column)
//       {
//       QModelIndex index = model.index(row, column, QModelIndex());
//       int value = (row+1) * (column+1);
//       std::cout << "Setting (" << row << ", " << column << ") to " << value << std::endl;
//       model.setData(index, QVariant(value));
//       }
//     }

  listView.show();
  return app.exec();
}
