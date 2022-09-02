#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QStandardPaths>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    qint64 m_jb;
    QTimer* m_timer;
    void InitComp();
    void SetTimmer(int interval);
private slots:
    void UpdateJB();
};
#endif // MAINWINDOW_H
