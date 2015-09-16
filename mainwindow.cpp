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
    
    this->answers << ui->a;
    this->answers << ui->b;
    this->answers << ui->c;
    this->answers << ui->d;

	connect(ui->a, SIGNAL(clicked()), this, SLOT(a_clicked()));
	connect(ui->b, SIGNAL(clicked()), this, SLOT(b_clicked()));
	connect(ui->c, SIGNAL(clicked()), this, SLOT(c_clicked()));
	connect(ui->d, SIGNAL(clicked()), this, SLOT(d_clicked()));

}


void MainWindow::fillText(Question* question){
	ui->question->setText(question->question);
	ui->a->setText(question->answers[0]);
	ui->b->setText(question->answers[1]);
	ui->c->setText(question->answers[2]);
	ui->d->setText(question->answers[3]);
}

void MainWindow::a_clicked(){
	ui->a->setStyleSheet(ui->a->styleSheet() + "border-image:url(:/images/selected.png);");
	this->answers[this->questions[0]->correct_index]->setStyleSheet(this->answers[this->questions[0]->correct_index] + "border-image:url(:/images/correct.png);");
}

void MainWindow::b_clicked(){
	ui->b->setStyleSheet(ui->b->styleSheet() + "border-image:url(:/images/selected.png);");
}

void MainWindow::c_clicked(){
	ui->c->setStyleSheet(ui->c->styleSheet() + "border-image:url(:/images/selected.png);");
}

void MainWindow::d_clicked(){
	ui->d->setStyleSheet(ui->d->styleSheet() + "border-image:url(:/images/selected.png);");
}

MainWindow::~MainWindow()
{
    delete ui;
}
