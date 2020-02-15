#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_parse_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void Json_obj(QString path,QJsonObject obj);

    //void Json_array(QJsonArray array);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
