#include "mainwindow.h"
#include "keyreceiver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    KeyReceiver* keyReceiver = new KeyReceiver(w);
    w.installEventFilter(keyReceiver);
    w.show();
    w.setFocus();
    return a.exec();
}
