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
    bindingButtons.push_back(ui->CBindButton);
    bindingButtons.push_back(ui->DBindButton);
    bindingButtons.push_back(ui->EBindButton);
    bindingButtons.push_back(ui->FBindButton);
    bindingButtons.push_back(ui->GBindButton);
    bindingButtons.push_back(ui->ABindButton);
    bindingButtons.push_back(ui->BBindButton);
    bindingButtons.push_back(ui->CSharpBindButton);
    bindingButtons.push_back(ui->DSharpBindButton);
    bindingButtons.push_back(ui->FSharpBindButton);
    bindingButtons.push_back(ui->GSharpBindButton);
    bindingButtons.push_back(ui->ASharpBindButton);
    for( int sound = C; sound <= ASharp; sound++)
    {
        UpdateBindingButtonText(bindingButtons[sound], Sound(sound));
    }
    QObject::connect(new QShortcut((Qt::Key_Down), this), &QShortcut::activated, ui->PitchChoose, &QSpinBox::stepDown);
    QObject::connect(new QShortcut((Qt::Key_Up), this), &QShortcut::activated, ui->PitchChoose, &QSpinBox::stepUp);
    ui->KeyBindingInfo->setVisible(false);
    ui->stackedWidget->setCurrentIndex(0);
    for( int sound = C; sound <= ASharp; sound++)
    {
        QObject::connect(bindingButtons[sound], &QPushButton::pressed, &soundsManager, [=]() {WaitForKeyToBind(Sound(sound));});
    }
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
    if(soundWaiting >= C && soundWaiting <= ASharp)UpdateBindingButtonText(bindingButtons[soundWaiting], soundWaiting);
    waitingForKey = false;
    ui->KeyBindingInfo->setVisible(false);
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
    UpdateBindingButtonText(bindingButtons[soundWaiting], soundWaiting);
    ui->KeyBindingInfo->setVisible(false);
}

void MainWindow::WaitForKeyToBind(Sound sound)
{
    if(soundWaiting >= C && soundWaiting <= ASharp)UpdateBindingButtonText(bindingButtons[soundWaiting], soundWaiting);
    waitingForKey = true;
    soundWaiting = sound;
    bindingButtons[soundWaiting]->setText("");
    ui->KeyBindingInfo->setVisible(true);
}

bool MainWindow::IsWaitingForKey() const
{
    return waitingForKey;
}
