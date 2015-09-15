#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Question* q = new Question;
    q->question = "Gs";
    QString text = "edno";
    q->answers << text;
    q->answers << text;
    q->answers << text;
    q->answers << text;
    q->correct_index = 0;
    this->questions << q;
    fillText(q);
}


void MainWindow::fillText(Question* question){
	ui->question->setText(question->question);
	ui->a->setText(question->answers[0]);
	ui->b->setText(question->answers[1]);
	ui->c->setText(question->answers[2]);
	ui->d->setText(question->answers[3]);
}


MainWindow::~MainWindow()
{
    delete ui;
}
