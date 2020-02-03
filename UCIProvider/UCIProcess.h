#pragma once

#include <memory>
#include <QString>
#include <QObject>

namespace UCI
{

class UCIProcess : public QObject
{
    Q_OBJECT

public:
    explicit UCIProcess(bool needping = true);
    virtual ~UCIProcess();

    // Запуск UCI движка
    void startUCIDriver(const QString& path);

    // Проверка готовности UCI движка
    bool isUCIReady() const;

    // Отправка команды UCI движку
    void sendCommand(const QString& command);

signals:
    // Сигнал испускается при получении новых данных от UCI движка
    void signalUCIAnswerReceived(const QStringList& splitAnswer);

    // Сигнал испускается при изменении состояния подключения к UCI движку
    void signalUCIConnectChanged(bool state, const QString& message = QString());

private:
    // Остановка UCI движка
    void stopProcess();

private:
    std::unique_ptr<class QProcess> m_UCIProcess;
    std::unique_ptr<class QTimer> m_pingTimer;
    std::unique_ptr<class QTimer> m_uciTimer;
    std::unique_ptr<class QTimer> m_nonConnectTimer;
    bool m_isUCIReady = false;
};

}
