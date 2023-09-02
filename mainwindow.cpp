#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QObject>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    BindSoundToButton(ui->CSoundButton, C);
    BindButtonToKey(QKeySequence(Qt::Key_Q), ui->CSoundButton);
    BindSoundToButton(ui->DSoundButton, D);
    BindButtonToKey(QKeySequence(Qt::Key_W), ui->DSoundButton);
    BindSoundToButton(ui->ESoundButton, E);
    BindButtonToKey(QKeySequence(Qt::Key_E), ui->ESoundButton);
    BindSoundToButton(ui->FSoundButton, F);
    BindButtonToKey(QKeySequence(Qt::Key_O), ui->FSoundButton);
    BindSoundToButton(ui->GSoundButton, G);
    BindButtonToKey(QKeySequence(Qt::Key_P), ui->GSoundButton);
    BindSoundToButton(ui->ASoundButton, A);
    BindButtonToKey(QKeySequence(Qt::Key_BracketLeft), ui->ASoundButton);
    BindSoundToButton(ui->BSoundButton, B);
    BindButtonToKey(QKeySequence(Qt::Key_BracketRight), ui->BSoundButton);
    BindSoundToButton(ui->CSharpSoundButton, CSharp);
    BindButtonToKey(QKeySequence(Qt::Key_2), ui->CSharpSoundButton);
    BindSoundToButton(ui->DSharpSoundButton, DSharp);
    BindButtonToKey(QKeySequence(Qt::Key_3), ui->DSharpSoundButton);
    BindSoundToButton(ui->FSharpSoundButton, FSharp);
    BindButtonToKey(QKeySequence(Qt::Key_0), ui->FSharpSoundButton);
    BindSoundToButton(ui->GSharpSoundButton, GSharp);
    BindButtonToKey(QKeySequence(Qt::Key_Minus), ui->GSharpSoundButton);
    BindSoundToButton(ui->ASharpSoundButton, ASharp);
    BindButtonToKey(QKeySequence(Qt::Key_Equal), ui->ASharpSoundButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::BindSoundToButton(QPushButton* button, Sound sound)
{
    QObject::connect(button, &QPushButton::pressed, &soundsManager, [=]() {soundsManager.Play(sound); soundsManager.SetSoundReady(false, sound);});
    QObject::connect(button, &QPushButton::released, &soundsManager, [=]() {soundsManager.SetSoundReady(true, sound);});
}

void MainWindow::BindButtonToKey(QKeySequence keySequence, QPushButton* button)
{
    QObject::connect(new QShortcut((keySequence), this), &QShortcut::activated, button, &QPushButton::click);
}

void MainWindow::on_VolumeSlider_valueChanged(int value)
{
    soundsManager.ChangeVolume(value);
}

