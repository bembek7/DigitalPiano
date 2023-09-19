#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QObject>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFocusPolicy( Qt::StrongFocus );
    soundButtons.push_back(ui->CSoundButton);
    soundButtons.push_back(ui->DSoundButton);
    soundButtons.push_back(ui->ESoundButton);
    soundButtons.push_back(ui->FSoundButton);
    soundButtons.push_back(ui->GSoundButton);
    soundButtons.push_back(ui->ASoundButton);
    soundButtons.push_back(ui->BSoundButton);
    soundButtons.push_back(ui->CSharpSoundButton);
    soundButtons.push_back(ui->DSharpSoundButton);
    soundButtons.push_back(ui->FSharpSoundButton);
    soundButtons.push_back(ui->GSharpSoundButton);
    soundButtons.push_back(ui->ASharpSoundButton);
    for( int sound = C; sound <= ASharp; sound++)
    {
        shortcutsButtons.push_back(new QShortcut(this));
        shortcutsButtons[sound]->setAutoRepeat(false);
        PrepareSound(soundButtons[sound], Sound(sound));
    }
    UpdateBindingButtonText(ui->CBindButton, C);
    UpdateBindingButtonText(ui->DBindButton, D);
    UpdateBindingButtonText(ui->EBindButton, E);
    UpdateBindingButtonText(ui->FBindButton, F);
    UpdateBindingButtonText(ui->GBindButton, G);
    UpdateBindingButtonText(ui->ABindButton, A);
    UpdateBindingButtonText(ui->BBindButton, B);
    UpdateBindingButtonText(ui->CSharpBindButton, CSharp);
    UpdateBindingButtonText(ui->DSharpBindButton, DSharp);
    UpdateBindingButtonText(ui->FSharpBindButton, FSharp);
    UpdateBindingButtonText(ui->GSharpBindButton, GSharp);
    UpdateBindingButtonText(ui->ASharpBindButton, ASharp);
    QObject::connect(new QShortcut((Qt::Key_Down), this), &QShortcut::activated, ui->PitchChoose, &QSpinBox::stepDown);
    QObject::connect(new QShortcut((Qt::Key_Up), this), &QShortcut::activated, ui->PitchChoose, &QSpinBox::stepUp);
    ui->KeyBindingInfo->setVisible(false);
    ui->stackedWidget->setCurrentIndex(0);
    QObject::connect(ui->CBindButton, &QPushButton::pressed, &soundsManager, [=]() {WaitForKeyToBind(C);});
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
    BindButtonToKey(soundsManager.GetSoundBindedKey(sound), button, sound);
}

void MainWindow::BindButtonToKey(const Qt::Key& key, QPushButton* button, Sound sound)
{
    if(shortcutsButtons[sound])
    {
        shortcutsButtons[sound]->setKey(key);
        QObject::connect(shortcutsButtons[sound], &QShortcut::activated, button, &QPushButton::click);
    }
}

void MainWindow::on_VolumeSlider_valueChanged(int value)
{
    soundsManager.ChangeVolume(value);
}

void MainWindow::UpdateBindingButtonText(QPushButton* button, Sound sound)
{
    button->setText(QString(QKeySequence(soundsManager.GetSoundBindedKey(sound)).toString()));
}

void MainWindow::on_PitchChoose_valueChanged(int value)
{
    soundsManager.SetPitch(value);
}

void MainWindow::on_SwitchToPlayingButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    for(auto& button : soundButtons)
    {
        button->setEnabled(true);
    }
}

void MainWindow::on_SwitchToKeyBindingButoon_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    for(auto& button : soundButtons)
    {
        button->setEnabled(false);
    }
}

void MainWindow::BindNewKey(const Qt::Key& key)
{
    waitingForKey = false;
    soundsManager.ChangeBinding(soundWaiting, key);
    BindButtonToKey(key, soundButtons[soundWaiting], soundWaiting);
    UpdateBindingButtonText(ui->CBindButton, C);
}

void MainWindow::WaitForKeyToBind(Sound sound)
{
    waitingForKey = true;
    soundWaiting = sound;
}

bool MainWindow::IsWaitingForKey() const
{
    return waitingForKey;
}
