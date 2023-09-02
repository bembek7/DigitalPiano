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

private slots:
    void on_VolumeSlider_valueChanged(int value);

    void on_PitchChoose_valueChanged(int value);

private:
    void BindSoundToButton(QPushButton* button, Sound sound);
    void BindButtonToKey(QKeySequence keySequence, QPushButton* button);

    Ui::MainWindow *ui;
    SoundsManager soundsManager;
};
#endif // MAINWINDOW_H
