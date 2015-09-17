#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <unistd.h>
#include <QPushButton>
#include <QSignalMapper>
#include <QtDebug>
#include <QSoundEffect>
#include <QTimer>
#include <QFileDialog>
#include <QtCore>
#include <QDir>
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
    QSoundEffect select_sound;
    QSoundEffect wrong_sound;
    int question_index;
    QList<Question*> questions;
    void fillText();
    QList<QPushButton*> answers;
    int button_id;
    void renovateColor();
    void gameOver();

private slots:
	void clicked(int button_id);
    void verified();
    void nextQuestion();
    void winGame();
};

#endif // MAINWINDOW_H
