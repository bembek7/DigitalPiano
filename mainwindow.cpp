#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QObject>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    BindSoundToButton(ui->CSoundButton, new QShortcut(QKeySequence(Qt::Key_Q), this), C);
    BindSoundToButton(ui->DSoundButton, new QShortcut(QKeySequence(Qt::Key_W), this), D);
    BindSoundToButton(ui->ESoundButton, new QShortcut(QKeySequence(Qt::Key_E), this), E);
    BindSoundToButton(ui->FSoundButton, new QShortcut(QKeySequence(Qt::Key_O), this), F);
    BindSoundToButton(ui->GSoundButton, new QShortcut(QKeySequence(Qt::Key_P), this), G);
    BindSoundToButton(ui->ASoundButton, new QShortcut(QKeySequence(Qt::Key_BracketLeft), this), A);
    BindSoundToButton(ui->pushButton_7, new QShortcut(QKeySequence(Qt::Key_BracketRight), this), B);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::BindSoundToButton(QPushButton* button, QShortcut *shortcut, Sound sound)
{
    QObject::connect(shortcut, &QShortcut::activated, button, &QPushButton::click);
    QObject::connect(button, &QPushButton::clicked, &soundsManager, [=]() {soundsManager.Play(sound);});
}
