#include <QtGui>
#include <iostream>

#include "main.h"

MainWindow::MainWindow(QMainWindow* parent) : QMainWindow(parent)
{
  setupUi(this);
  this->Object = new MyObject;

  this->TestComputationThread.SetObject(this->Object);

  connect(&this->TestComputationThread, SIGNAL(StartProgressBarSignal()), this, SLOT(StartProgressBar()));
  connect(&this->TestComputationThread, SIGNAL(StopProgressBarSignal()), this, SLOT(StopProgressBar()));

  // Marquee mode
  this->progressBar->setMinimum(0);
  this->progressBar->setMaximum(0);
  this->progressBar->hide();
  
}

void MainWindow::on_btnStop_clicked()
{
  this->TestComputationThread.StopComputation();
}

void MainWindow::on_btnCompute_clicked()
{
  this->TestComputationThread.Operation = ComputationThreadClass::ALLSTEPS;
  this->TestComputationThread.start();
}

void MainWindow::on_btnStep_clicked()
{
  this->TestComputationThread.Operation = ComputationThreadClass::SINGLESTEP;
  this->TestComputationThread.start();
}

void MainWindow::StartProgressBar()
{
  this->progressBar->show();
}

void MainWindow::StopProgressBar()
{
  this->progressBar->hide();
}
