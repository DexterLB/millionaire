#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QtDebug>
#include "question.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QList<Question*> questions;
    void fillText(Question* question);
    QList<QPushButton*> answers;

private slots:
	void a_clicked();
	void b_clicked();
	void c_clicked();
	void d_clicked();

};

#endif // MAINWINDOW_H
