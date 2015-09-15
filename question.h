#ifndef QUESTION_H
#define QUESTION_H
#include <QObject>

class Question: public QObject{
	    Q_OBJECT
	public:
		QString question;
		QList<QString> answers;
		int correct_index;
};

#endif // MAINWINDOW_H
