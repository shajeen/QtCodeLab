#include "mainwindow.h"
#include "ui_mainwindow.h"

#define COLOR_WHITE "black"
#define COLOR_BLACK "white"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(100,100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *pEventPainter)
{
    if (pEventPainter)
    {
        QString qrCodeMessage = "hello World how are you???";

        if (qrCodeMessage.isEmpty()) {
            qDebug() << "no qrcode message to decode";
            return;
        }

        QPainter paintDevice(this);
        QRcode *pQRCodeDecoder = QRcode_encodeString(qrCodeMessage.toStdString().c_str(), 1, QR_ECLEVEL_L, QR_MODE_8, 0);

        if (pQRCodeDecoder) {
            QColor colorForground(COLOR_BLACK);
            QColor colorBackground(COLOR_WHITE);

            paintDevice.setBrush(colorBackground);
            paintDevice.setPen(Qt::NoPen);
            paintDevice.drawRect(0, 0, width(), height());

            paintDevice.setBrush(colorForground);
            const int iScaleDiv = (pQRCodeDecoder->width > 0) ? (pQRCodeDecoder->width):(1);
            const double dQRWidget = width();
            const double dQRHeight = height();
            const double dAspectRatio = (dQRWidget/dQRHeight);
            const double dScale = (((dAspectRatio > (1.0)) ? (dQRWidget) : (dQRHeight))/iScaleDiv);

            for (int iY = 0; iY < iScaleDiv; ++iY)
            {
                const int iY2 = iY * iScaleDiv;

                for (int iX = 0; iX < iScaleDiv; ++iX)
                {
                    const int iX2 = iY2 + iX;
                    const unsigned char cData = pQRCodeDecoder->data[iX2];

                    if (cData & 0x01) {
                        const double dQRx = iX * dScale, dQRy = iY * dScale;
                        QRectF qrCodeRect(dQRx, dQRy, dScale, dScale);
                        paintDevice.drawRects(&qrCodeRect, 1);
                    }
                }
            }

            QRcode_free(pQRCodeDecoder);

        } else {
            qDebug() << "unable to encode qrcode string";
        }
    }
    else
    {
        qDebug() << "failed to paint.";
    }
}
