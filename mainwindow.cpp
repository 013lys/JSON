#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_parse_clicked()
{
    QJsonParseError Error;
    QJsonDocument Document = QJsonDocument::fromJson(ui->plainTextEdit_JSON->toPlainText().toUtf8(),&Error);
//    qDebug() <<ui->plainTextEdit_JSON->toPlainText();

    if(Error.error!=QJsonParseError::NoError) //error
    {
        qDebug() << Error.errorString();
        return;
    }

    Json_obj("/",Document.object());


}



void MainWindow::Json_obj(QString path, QJsonObject obj)
{
    foreach(QString key,obj.keys())
    {
       QString keystring = key;
       keystring.prepend("/");
       qDebug() << keystring;
       if(obj[key].isObject())
       {
           Json_obj("abc",obj[key].toObject());
       }
    }

}
