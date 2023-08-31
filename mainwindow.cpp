#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QShortcut>
#include <QObject>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Q), this);
    QObject::connect(shortcut, &QShortcut::activated, ui->CSoundButton, &QPushButton::click);
    QObject::connect(ui->CSoundButton, &QPushButton::clicked, &soundsManager, [=]() {soundsManager.Play(c);});
}

MainWindow::~MainWindow()
{
    delete ui;
}
