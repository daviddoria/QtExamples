#include <iostream>

#include <QDebug>
#include <QStyle>
#include <QMetaEnum>

int main(int, char *[])
{
  // You would do something like this, but this particular enum
  QMetaObject meta = QStyle::staticMetaObject;
  int indexOfEnumerator = meta.indexOfEnumerator("State");
  std::cout << "indexOfEnumerator: " << indexOfEnumerator << std::endl;
  QMetaEnum m = meta.enumerator(indexOfEnumerator);

  qDebug() << m.valueToKey(0);
  qDebug() << m.key(0);
  return 0;
}
