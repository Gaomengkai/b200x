#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitComp();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitComp(){
    auto homeLoc = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    homeLoc.append("/jinbi.txt");
    QFile file(homeLoc);
    file.open(QIODevice::ReadWrite|QIODevice::Text);
    QByteArray content = file.readAll();
    qint64 jb=0;
    if(content.length()==0){
        file.write(QString::number(jb).toStdString().c_str());
    }
    jb = content.toLongLong();
    this->m_jb=jb;
    QString txt = QString::number(jb);
    file.flush();
    file.close();
    ui->tJinbi->setText(txt);

    // SetTimmer
    this->SetTimmer(1);
}

void MainWindow::UpdateJB() {
    m_jb += 1;
    ui->tJinbi->setText(QString::number(m_jb));

    // save archive
    auto homeLoc = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    homeLoc.append("/jinbi.txt");
    QFile file(homeLoc);
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    file.write(QString::number(m_jb).toStdString().c_str());
}

void MainWindow::SetTimmer(int interval){
    interval *= 1000;
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(UpdateJB()));
    m_timer->start(interval);
}
