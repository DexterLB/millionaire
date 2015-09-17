#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->question_index = 0;

    this->select_sound.setSource(QUrl::fromLocalFile(":/sounds/select.mp3"));
    this->select_sound.setVolume(0.25f);
    
    QFile file(QFileDialog::getOpenFileName(this, "Select a file to open..."));
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString line;
    QTextStream in(&file);
    while(!in.atEnd()){
        Question* current_question = new Question;
        line = in.readLine();
        current_question->question = line;
        for(int i = 0; i < 4; i++){
            line = in.readLine();
            current_question->answers << line;
        }
        line = in.readLine();
        current_question->correct_index = line.toInt();

        this->questions << current_question;
    }

    this->answers << ui->a;
    this->answers << ui->b;
    this->answers << ui->c;
    this->answers << ui->d;

    fillText();
	
    QSignalMapper* signalMapper = new QSignalMapper(this);
    for(int i = 0; i < 4; i++){
    	connect(this->answers[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
    	signalMapper->setMapping(this->answers[i], i);
	}
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(clicked(int)));
}

void MainWindow::renovateColor(){
    for(int i = 0; i < 4; i++){
        this->answers[i]->setStyleSheet("border:none; border-image:url(:/images/button.png); color:white; font: 75 11pt \"STIXIntegralsSm\"; font-weight:bold;");
        this->answers[i]->setEnabled(true);
    }
}

void MainWindow::fillText(){
    this->renovateColor();
	ui->question->setText(this->questions[question_index]->question);
	ui->a->setText(this->questions[question_index]->answers[0]);
	ui->b->setText(this->questions[question_index]->answers[1]);
	ui->c->setText(this->questions[question_index]->answers[2]);
	ui->d->setText(this->questions[question_index]->answers[3]);
}

void MainWindow::clicked(int button_id){
    this->select_sound.play();
	this->answers[button_id]->setStyleSheet(ui->a->styleSheet() + "border-image:url(:/images/selected.png);");
    this->button_id = button_id;
    for(int i = 0; i < 4; i++){
        if(this->button_id != i){
            this->answers[i]->setEnabled(false);
        }
    }
    QTimer::singleShot(1000, this, SLOT(verified()));
}

void MainWindow::verified() {
    this->answers[this->questions[question_index]->correct_index]->setStyleSheet(this->answers[this->questions[question_index]->correct_index]->styleSheet() + "border-image:url(:/images/correct.png);");
    QTimer::singleShot(1000, this, SLOT(nextQuestion()));
}

void MainWindow::nextQuestion(){
    if(question_index >= this->questions.size() - 1){
        QTimer::singleShot(1000, this, SLOT(winGame()));
    } else {
        this->question_index += 1;
        fillText();
    }
}

void MainWindow::winGame(){
    
}

MainWindow::~MainWindow()
{
    delete ui;
}
