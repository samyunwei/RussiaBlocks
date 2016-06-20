#ifndef GAMERECORDADDFORM_H
#define GAMERECORDADDFORM_H

#include <QDialog>

namespace Ui {
class GameRecordAddForm;
}

class GameRecordAddForm : public QDialog
{
    Q_OBJECT

public:
    explicit GameRecordAddForm(QString theLabelString = "None",QWidget *parent = 0);
    ~GameRecordAddForm();
    void GuiSetting();
    QString GetUserName();
private slots:
    void on_pushButton_OK_clicked();

private:
    Ui::GameRecordAddForm *ui;
    QString m_LabelString;
    QString m_UserName;
};

#endif // GAMERECORDADDFORM_H
