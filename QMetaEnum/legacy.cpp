#include <iostream>

#include <QDebug>
#include <QStyle>
#include <QCommonStyle>
#include <QMetaEnum>

int main(int, char *[])
{
  QCommonStyle style;
  QStyle::State state;

  if(state == QStyle::State_Selected)
    {
    std::cout << "State is selected." << std::endl;
    }
  else
    {
    std::cout << "State: " << state << std::endl;
    }

  //QMetaObject meta = PixmapDelegate::staticMetaObject;
  QMetaObject meta = style.staticMetaObject;
  QMetaEnum m = meta.enumerator(meta.indexOfEnumerator("State"));

  //qDebug() << m.valueToKey(0);
  qDebug() << m.key(0);
  return 0;
}
