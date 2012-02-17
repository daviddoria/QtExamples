#ifndef TENUMS_H
#define TENUMS_H

#include <QDebug>
#include <QMetaEnum>

class TEnums
{
    Q_GADGET
    Q_ENUMS(State)


public:
    enum State { ST1, ST2 };

    static QString ValueForKey(const char* enumName, int value)
    {
        QMetaEnum m = TEnums::staticMetaObject.enumerator(TEnums::staticMetaObject.indexOfEnumerator(enumName));
        QString key = m.valueToKey(value);
        qDebug() << key;

        return key;
    }


};
#endif // TENUMS_H

//
//
//
#include <QtCore/QCoreApplication>
#include "tenums.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TEnums::ValueForKey("State",TEnums::ST1);
    TEnums::ValueForKey("State",0);


    return a.exec();
}