#include "mainwindow.h"
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    temperatureLabel = new QLabel("Temperature: N/A", this);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(temperatureLabel);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTemperature);
    timer->start(1000); // Update every second

    updateTemperature(); // Initial update
}

MainWindow::~MainWindow() {
    delete temperatureLabel;
    delete timer;
}

void MainWindow::updateTemperature() {
    QFile file("/sys/class/thermal/thermal_zone0/temp");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString temp = in.readLine();
        double temperature = temp.toDouble() / 1000.0;
        temperatureLabel->setText(QString("Temperature: %1 °C").arg(temperature));
        file.close();
    }
}
