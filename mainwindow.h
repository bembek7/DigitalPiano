#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <SoundsManager.h>
#include <QShortcut>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void BindSoundToButton(QPushButton* button, QShortcut *shortcut, Sound sound);

    Ui::MainWindow *ui;
    SoundsManager soundsManager;
};
#endif // MAINWINDOW_H
