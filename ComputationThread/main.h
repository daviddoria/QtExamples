#ifndef MAIN_H
#define MAIN_H

#include <QMainWindow>

#include "ui_main.h"

#include "MyObject.h"
#include "TestComputationThread.h"

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QMainWindow *parent = 0);

public slots:

    void on_btnStop_clicked();
    void on_btnCompute_clicked();
    void on_btnStep_clicked();

    void StartProgressBar();
    void StopProgressBar();
    
protected:
  MyObject* Object;
  TestComputationThreadClass TestComputationThread;
};

#endif
