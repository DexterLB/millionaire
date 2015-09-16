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
    q->correct_index = 1;
    this->questions << q;
    fillText(q);

    this->answers << ui->a;
    this->answers << ui->b;
    this->answers << ui->c;
    this->answers << ui->d;

	QSignalMapper* signalMapper = new QSignalMapper(this);
    for(int i = 0; i < 4; i++){
    	connect(this->answers[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
    	signalMapper->setMapping(this->answers[i], i);
	}
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(clicked(int)));
}


void MainWindow::fillText(Question* question){
	ui->question->setText(question->question);
	ui->a->setText(question->answers[0]);
	ui->b->setText(question->answers[1]);
	ui->c->setText(question->answers[2]);
	ui->d->setText(question->answers[3]);
}

void MainWindow::clicked(int button_id){
	this->answers[button_id]->setStyleSheet(ui->a->styleSheet() + "border-image:url(:/images/selected.png);");
	for(int i = 0; i < 4; i++){
        if(button_id != i){
            this->answers[i]->setEnabled(false);
        }
    }
    this->answers[this->questions[0]->correct_index]->setStyleSheet(this->answers[this->questions[0]->correct_index]->styleSheet() + "border-image:url(:/images/correct.png);");

}


MainWindow::~MainWindow()
{
    delete ui;
}
