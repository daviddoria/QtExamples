#ifndef MyListModel_H
#define MyListModel_H

#include <QAbstractListModel>

#include <vector>

class MyListModel : public QAbstractListModel
{
public:
  MyListModel();

  int rowCount(const QModelIndex& parent) const;

  QVariant data(const QModelIndex& index, int role) const;
  Qt::ItemFlags flags ( const QModelIndex & index ) const;

  void SetRowHeight(const unsigned int rowHeight);

  void AddImage();

  void Refresh();

private:
  unsigned int RowHeight;
  unsigned int NumberOfImages;
};

#endif
