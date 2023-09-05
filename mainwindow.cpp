#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QObject>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PrepareSound(ui->CSoundButton, C);
    PrepareSound(ui->DSoundButton, D);
    PrepareSound(ui->ESoundButton, E);
    PrepareSound(ui->FSoundButton, F);
    PrepareSound(ui->GSoundButton, G);
    PrepareSound(ui->ASoundButton, A);
    PrepareSound(ui->BSoundButton, B);
    PrepareSound(ui->CSharpSoundButton, CSharp);
    PrepareSound(ui->DSharpSoundButton, DSharp);
    PrepareSound(ui->FSharpSoundButton, FSharp);
    PrepareSound(ui->GSharpSoundButton, GSharp);
    PrepareSound(ui->ASharpSoundButton, ASharp);
    QObject::connect(new QShortcut((Qt::Key_Down), this), &QShortcut::activated, ui->PitchChoose, &QSpinBox::stepDown);
    QObject::connect(new QShortcut((Qt::Key_Up), this), &QShortcut::activated, ui->PitchChoose, &QSpinBox::stepUp);
    ui->KeyBindingInfo->setVisible(false);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::BindSoundToButton(QPushButton* button, Sound sound)
{
    QObject::connect(button, &QPushButton::pressed, &soundsManager, [=]() {soundsManager.Play(sound);});
}

void MainWindow::PrepareSound(QPushButton* button, Sound sound)
{
    BindSoundToButton(button, sound);
    BindButtonToKey(soundsManager.GetSoundBindedKey(sound), button);
}

void MainWindow::BindButtonToKey(const Qt::Key& key, QPushButton* button)
{
    QShortcut* shortcut = new QShortcut((key), this);
    shortcut->setAutoRepeat(false);
    QObject::connect(shortcut, &QShortcut::activated, button, &QPushButton::click);
}

void MainWindow::on_VolumeSlider_valueChanged(int value)
{
    soundsManager.ChangeVolume(value);
}


void MainWindow::on_PitchChoose_valueChanged(int value)
{
    soundsManager.SetPitch(value);
}


void MainWindow::on_SwitchToPlayingButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_SwitchToKeyBindingButoon_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

