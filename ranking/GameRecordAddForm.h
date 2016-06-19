#ifndef GAMERECORDADDFORM_H
#define GAMERECORDADDFORM_H

#include <QWidget>

namespace Ui {
class GameRecordAddForm;
}

class GameRecordAddForm : public QWidget
{
    Q_OBJECT

public:
    explicit GameRecordAddForm(QString theLabelString = "None",QWidget *parent = 0);
    ~GameRecordAddForm();

private:
    Ui::GameRecordAddForm *ui;
    QString m_LabelString;
};

#endif // GAMERECORDADDFORM_H
