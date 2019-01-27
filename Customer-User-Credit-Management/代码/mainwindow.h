#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include "SinglyLinkedList.h"
#include "FileOperation.h"

class Widget : public QWidget
{
    Q_OBJECT
public :
    Widget(QWidget *parent=0);
    ~Widget();
private:
    FileOperation FILE1;
    SinglyLinkedList A;
    QLabel *userNameLabel;
    QLabel *passWordLabel;
    QLineEdit *userNameLineEdit;
    QLineEdit *passWordLineEdit;
    QPushButton *login;
    QPushButton *login_1;
private slots:
    void slotLogin();
    void slotLogin_1();
};

#endif // MAINWINDOW_H
