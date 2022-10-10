#include "s21_view.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    s21_view w;
    w.show();
    return a.exec();
}
