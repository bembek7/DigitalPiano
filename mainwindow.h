#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "SoundsManager.h"
#include <QShortcut>
#include <QPushButton>
#include "Recorder.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void BindNewKey(const Qt::Key& key);
    bool IsWaitingForKey() const;


private slots:
    void on_VolumeSlider_valueChanged(int value);

    void on_PitchChoose_valueChanged(int value);

    void on_SwitchToPlayingButton_clicked();

    void on_SwitchToKeyBindingButoon_clicked();

    void on_StartRecordingButton_clicked();

    void on_StopRecordingButton_clicked();

private:
    void BindSoundToButton(QPushButton* button, Sound sound);
    void BindButtonToKey(const Qt::Key& key, QPushButton* button, Sound sound);
    void PrepareSound(QPushButton* button, Sound sound);
    void UpdateBindingButtonText(QPushButton* button, Sound sound);
    void WaitForKeyToBind(Sound sound);

    bool isRecording = false;
    bool waitingForKey = false;
    Sound soundWaiting;
    std::vector<QPushButton*> soundButtons;
    std::vector<QPushButton*> bindingButtons;
    std::vector<QShortcut*> shortcutsButtons;
    Ui::MainWindow *ui;
    SoundsManager soundsManager;
    Recorder recorder;
};
#endif // MAINWINDOW_H
