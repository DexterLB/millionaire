#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->question_index = 0;

    this->select_sound.setSource(QUrl("qrc:/sounds/select.wav"));
    this->wrong_sound.setSource(QUrl("qrc:/sounds/wrong.wav"));
    this->right_sound.setSource(QUrl("qrc:/sounds/right.wav"));


    this->answers << ui->a;
    this->answers << ui->b;
    this->answers << ui->c;
    this->answers << ui->d;

    this->blank_button_stylesheet = ui->a->styleSheet();

    QSignalMapper* answerMapper = new QSignalMapper(this);
    for(int i = 0; i < 4; i++){
    	connect(this->answers[i], SIGNAL(clicked()), answerMapper, SLOT(map()));
    	answerMapper->setMapping(this->answers[i], i);
	}
    connect(answerMapper, SIGNAL(mapped(int)), this, SLOT(clicked(int)));

    QTimer::singleShot(0, this, SLOT(startGame()));
}

void MainWindow::startGame() {
    QString filename = QFileDialog::getOpenFileName(
        this, "Select questions file"
    );
    if (filename.isNull()) {
        qApp->exit();
        return;
    }

    QFile file(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString line;
    QTextStream in(&file);
    in.setCodec("UTF-8");

    while(!in.atEnd()){
        Question* current_question = new Question;
        line = in.readLine();
        current_question->question = line;
        for(int i = 0; i < 4; i++) {
            line = in.readLine();
            current_question->answers << line;
        }
        line = in.readLine();
        current_question->correct_index = line.toInt();

        this->questions << current_question;
    }

    this->fillText();
}

void MainWindow::renovateColor(){
    for(int i = 0; i < 4; i++){
        this->answers[i]->setStyleSheet(this->blank_button_stylesheet);
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
	this->answers[button_id]->setStyleSheet(
        ui->a->styleSheet() + "border-image:url(:/images/selected.png);"
    );
    this->button_id = button_id;
    for(int i = 0; i < 4; i++) {
        if(this->button_id != i) {
            this->answers[i]->setEnabled(false);
        }
    }

    QTimer::singleShot(3000, this, SLOT(verified()));
}

void MainWindow::verified() {
    int correct_index = this->questions[question_index]->correct_index;
    this->answers[correct_index]->setStyleSheet(
        this->answers[correct_index]->styleSheet()
            + "border-image:url(:/images/correct.png);"
    );

    if (this->button_id == correct_index) {
        this->right_sound.play();
    } else {
        this->wrong_sound.play();
    }

    QTimer::singleShot(3000, this, SLOT(nextQuestion()));
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
    QMessageBox::information(this, "Yay!", "You win!");
    this->startGame();
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    switch(event->key()) {
        case Qt::Key_A: this->clicked(0); break;
        case Qt::Key_B: this->clicked(1); break;
        case Qt::Key_C: this->clicked(2); break;
        case Qt::Key_D: this->clicked(3); break;
        default: QMainWindow::keyPressEvent(event);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
