#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <unistd.h>
#include <QPushButton>
#include <QSignalMapper>
#include <QtDebug>
#include <QTimer>
#include <QtCore>
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
    int question_index;
    QList<Question*> questions;
    void fillText();
    QList<QPushButton*> answers;
    int button_id;
    void renovateColor();
    void gameOver();
    void nextQuestion();
    void winGame();
    
private slots:
	void clicked(int button_id);
    void verified();
};

#endif // MAINWINDOW_H
