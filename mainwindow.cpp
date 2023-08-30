#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QShortcut>
#include <QObject>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CSound.setSource(QUrl("qrc:/CSound.wav"));
    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Q), this);
    QObject::connect(shortcut, SIGNAL(activated()), ui->CSoundButton, SLOT(click()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CSoundButton_clicked()
{
    CSound.play();
}
