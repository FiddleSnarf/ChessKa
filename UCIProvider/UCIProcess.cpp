#include <QProcess>
#include <QTimer>

#include "UCIProcess.h"
#include "UCICommon.h"

#include <QDebug>

using namespace UCI;

UCIProcess::UCIProcess(bool needping):
    m_UCIProcess(std::make_unique<QProcess>()),
    m_pingTimer(std::make_unique<QTimer>()),
    m_uciTimer(std::make_unique<QTimer>()),
    m_nonConnectTimer(std::make_unique<QTimer>())
{
    // Подписываемся на получение данных от UCI движка
    connect(m_UCIProcess.get(), &QProcess::readyReadStandardOutput, this, [this, needping]()
    {
        const QString answer = QString(m_UCIProcess->readAllStandardOutput()).simplified();
        qDebug() << "rec: " + answer;
        auto answerList = answer.split(QStringLiteral(" "), QString::SkipEmptyParts);
        if (!answerList.isEmpty())
        {
            if (answerList.contains(Answers::uciok_com)) // Ловим ответ на проверку поддержки UCI
            {
                m_uciTimer->stop();
                emit signalUCIConnectChanged(true);
                if (needping)
                {
                    m_pingTimer->start();
                    m_nonConnectTimer->start();
                }
            }
            else if (answerList.contains(Answers::readyok_com)) // Ловим ответ на пинг
            {
                m_isUCIReady = true;
                if (m_nonConnectTimer->isActive())
                    m_nonConnectTimer->start();
            }
            else
                emit signalUCIAnswerReceived(answerList); // Отдаем наверх
        }
    });

    // Настраиваем таймер пинга
    if (needping)
    {
        connect(m_pingTimer.get(), &QTimer::timeout, this, [this]()
        {
            m_isUCIReady = false;
            sendCommand(Commands::isready_com);
        });
        m_pingTimer->setInterval(PING_INTERVAL);
    }

    // Настраиваем таймер проверки на UCI
    connect(m_uciTimer.get(), &QTimer::timeout, this, [this]()
    {
        m_uciTimer->stop();
        stopProcess();
    });
    m_uciTimer->setInterval(UCI_CHECK_INTERVAL);

    // Настраиваем таймер ожидания ответа на пинг
    connect(m_nonConnectTimer.get(), &QTimer::timeout, this, [this]()
    {
        m_nonConnectTimer->stop();
        stopProcess();
    });
    m_nonConnectTimer->setInterval(PING_LIMIT_INTERVAL);
}

UCIProcess::~UCIProcess()
{
    stopProcess();
}

void UCIProcess::startUCIDriver(const QString& path)
{
    stopProcess();

    m_UCIProcess->setProgram(path);
    m_UCIProcess->start();

    // Проверка на UCI
    sendCommand(Commands::uci_com);
    m_uciTimer->start();
}

void UCIProcess::sendCommand(const QString& command)
{
    if (m_UCIProcess->isOpen())
        m_UCIProcess->write(QString(command + endStr).toUtf8());
}

bool UCIProcess::isUCIReady() const
{
    return (m_UCIProcess->isOpen() && m_isUCIReady);
}

void UCIProcess::stopProcess()
{
    if (m_UCIProcess->isOpen())
    {
        m_UCIProcess->close();
        m_isUCIReady = false;
        emit signalUCIConnectChanged(false);
    }
}
