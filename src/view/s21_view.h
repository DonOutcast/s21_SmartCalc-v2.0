#ifndef S21_VIEW_H
#define S21_VIEW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtGui>
#include <QtCore>
#include <vector>
#include <iostream>
//#include "../controller/controller.h"
#include <string>
#include "s21_credit.h"
#include "qcustomplot.h"
#include "s21_deposit.h"

QT_BEGIN_NAMESPACE
namespace Ui { class s21_view; }
QT_END_NAMESPACE

class s21_view : public QMainWindow
{
    Q_OBJECT

public:
    s21_view(QWidget *parent = nullptr);
    ~s21_view();

private slots:
    void connecting_buttons();
    void output_label();
    void clear_label();
    void calculate_finally();
    void on_button_clear_clicked();
    void output_functions();
    void openCalcHandler();
    void closeCalcHandler();

    void on_button_graph_clicked();
    void autoBtnClickHandler(int state);
    void on_pushButton_clicked();

private:
    void connectSignals();
    s21_credit *s21_credit_;
    s21_deposit *s21_deposit_;
    s21::Controller s21_calc_;
    Ui::s21_view *ui;
    QList<QPushButton *> buttons_digits_;
    QList<QPushButton *> buttons_lexems_;
    QList<QPushButton *> buttons_functions_;
    void connection_function();
    void execWidget(QWidget *widget);
    void changeRangeState(QSpinBox *spin, int state, int startValue);
    double x_min_begin = -10;
    double x_min_end = 10;
    double y_min_begin = -10;
    double y_min_end = 10;

    std::pair<std::vector<double>, std::vector<double>> tmp_;

    void event_loop();

};
#endif // S21_VIEW_H
