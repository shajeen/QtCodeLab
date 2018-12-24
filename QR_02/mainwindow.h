#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSvgRenderer>
#include <QPainter>
#include <QImage>
#include <QtDebug>
#include <QFile>
#include <QtNetwork/QtNetwork>

#include <iostream>

#include "QrCode.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_generate_clicked();

private:
    Ui::MainWindow *ui;

    void generateQRCode();
    void saveQRCode(const QString QRCodeData);
    void svgTopngConverter();
};

#endif // MAINWINDOW_H
