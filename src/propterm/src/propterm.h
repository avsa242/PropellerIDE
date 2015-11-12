#pragma once

#include <QWidget>
#include <QTimer>
#include <QLoggingCategory>

#include <PropellerSession>
#include "ui_propterm.h"

Q_DECLARE_LOGGING_CATEGORY(terminal)

class Console;

class PropTerm : public QWidget
{
    Q_OBJECT

private:
    Ui::PropTerm ui;
    Console console;
    PropellerManager * manager;
    PropellerSession * session;

    QString title;

    int timeout;
    QTimer rxTimeout;
    QTimer txTimeout;
    QTimer busyTimeout;
    bool busytoggle;

public:
    explicit PropTerm(PropellerManager * manager, QWidget *parent = 0);
    ~PropTerm();

public slots:
    void setFont(const QFont & font);

private slots:
    void open();
    void closed();
    void free();
    void busy();
    void reset();
    void writeData(const QByteArray &data);
    void readData();

    void handleError();
    void handleEnable(bool checked);
    void handleBusy();

    void portChanged();
    void baudRateChanged(const QString & text);

    void sendDataLine();

    void toggleTxLight(bool enabled);
    void toggleRxLight(bool enabled);

    void turnOffTxLight();
    void turnOffRxLight();

    void updatePorts();

};