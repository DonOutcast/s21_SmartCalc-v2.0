#ifndef S21_CREDIT_H
#define S21_CREDIT_H

#include <QWidget>

namespace Ui {
class s21_credit;
}

class s21_credit : public QWidget
{
    Q_OBJECT

public:
    explicit s21_credit(QWidget *parent = nullptr);
    ~s21_credit();

private slots:
    void on_pushButton_clicked();

private:

    Ui::s21_credit *ui;
};

#endif // S21_CREDIT_H
