#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <unistd.h>
#include <QPushButton>
#include <QSignalMapper>
#include <QtDebug>
#include <QTimer>
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
    int button_id;

private slots:
	void clicked(int button_id);
    void verified();
};

#endif // MAINWINDOW_H
