#include "keyreceiver.h"
#include "qcoreevent.h"
#include <QKeyEvent>

KeyReceiver::KeyReceiver(MainWindow& window, QObject *parent):
    QObject{parent},
    mainWindow(window)
{
    ;
}

bool KeyReceiver::eventFilter(QObject* obj, QEvent* event)
{
    if(event->type()==QEvent::KeyPress && mainWindow.IsWaitingForKey())
    {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        mainWindow.BindNewKey(Qt::Key(key->key()));
        return true;
    }
    else
    {
        return QObject::eventFilter(obj, event);
    }
    return false;
}
