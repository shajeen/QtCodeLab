#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSvgWidget>
#include <QProcess>

using namespace qrcodegen;

#define SVG_IMAGE "VectorImage.svg"
#define PNG_IMAGE "OriginalQRCode.png"
#define PROCESS_PARAMETER "rsvg -w %1 -h %2 %3 %4"
#define LABEL_STYLESHEET "QLabel { border-image: url(%1);}"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_generate_clicked()
{
    generateQRCode();
    svgTopngConverter();
    ui->lbl_qrcode_displau->setStyleSheet(QString(LABEL_STYLESHEET).arg(PNG_IMAGE));
}

void MainWindow::generateQRCode()
{
    QString qrCodeText = "";

    QList<QHostAddress> listOfAddress = QNetworkInterface::allAddresses();
    qrCodeText = listOfAddress.at(2).toString();

    if (!qrCodeText.isEmpty()) {
        qrcodegen::QrCode QRCodeGenerator = qrcodegen::QrCode::encodeText(qrCodeText.toStdString().c_str(), qrcodegen::QrCode::Ecc::QUARTILE);
        saveQRCode(QString::fromStdString(QRCodeGenerator.toSvgString(4)));
    }
}

void MainWindow::saveQRCode(const QString QRCodeData)
{
    if (!QRCodeData.isEmpty()) {

        QFile file(SVG_IMAGE);

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            return;
        }

        QTextStream fileWritter(&file);
        fileWritter << QRCodeData;
    }
}

void MainWindow::svgTopngConverter()
{
    QPointer<QProcess> pConverter = (new QProcess(this));
    pConverter->start(QString(PROCESS_PARAMETER).arg(ui->lbl_qrcode_displau->width())
                      .arg(ui->lbl_qrcode_displau->width()).arg(SVG_IMAGE).arg(PNG_IMAGE));
}
