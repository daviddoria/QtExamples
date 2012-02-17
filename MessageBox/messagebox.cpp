#include "messagebox.h"

#include <QMessageBox>

#include <iostream>

MyForm::MyForm(QWidget *parent)
    : QWidget(parent)
{
  setupUi(this);
  connect( this->btnClickMe, SIGNAL( clicked() ), this, SLOT(btnClickMe_clicked()) );
}

void Standard()
{
  QMessageBox msgBox;
  msgBox.setText("Test Text");
  msgBox.exec(); // This works, but doesn't care about the value
}

void MyForm::btnClickMe_clicked()
{
  QMessageBox msgBox;
  msgBox.addButton(QMessageBox::Yes);
  msgBox.addButton(QMessageBox::No);
  msgBox.setText("My Message Box");

  int selection = msgBox.exec();
  if(selection == QMessageBox::Yes)
  {
    std::cout << "yes" << std::endl;
  }
  else if(selection == QMessageBox::No)
  {
    std::cout << "no" << std::endl;
  }
}
