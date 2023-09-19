#ifndef KEYRECEIVER_H
#define KEYRECEIVER_H

#include "mainwindow.h"
#include <QObject>

class KeyReceiver : public QObject
{
    Q_OBJECT

public:
    KeyReceiver(MainWindow& window, QObject *parent = nullptr);
protected:
    bool eventFilter(QObject* obj, QEvent* event);

private:
    MainWindow& mainWindow;

};

#endif // KEYRECEIVER_H
