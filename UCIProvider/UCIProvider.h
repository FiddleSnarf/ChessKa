#pragma once

#include <QProcess>
#include <QTimer>
#include <memory>

namespace UCI
{

class UCIProvider : public QObject
{
    Q_OBJECT

public:
    explicit UCIProvider();
    virtual ~UCIProvider();

    void startUCI(const QString& UCIpath);
    void sendCommand(const QString& command);

private slots:
    void slotUCIReceived(const QStringList& answer);

private:
    std::unique_ptr<class UCIProcess> m_uciProcess;
};

using UCIProviderPtr = std::shared_ptr<UCIProvider>;

}
