#include "UCIProvider.h"
#include "UCIProcess.h"

using namespace UCI;

UCIProvider::UCIProvider() :
    m_uciProcess(std::make_unique<UCIProcess>())
{
    connect(m_uciProcess.get(), &UCIProcess::signalUCIAnswerReceived, this, &UCIProvider::slotUCIReceived);
    //connect(m_uciProcess.get(), &UCIProcess::signalUCIConnectChanged, this, &UCIProvider::slotUCIConnectedChanged);
}

UCIProvider::~UCIProvider()
{

}

void UCIProvider::startUCI(const QString& UCIpath)
{
    m_uciProcess->startUCIDriver(UCIpath);
}

void UCIProvider::sendCommand(const QString& command)
{
    m_uciProcess->sendCommand(command);
}

void UCIProvider::slotUCIReceived(const QStringList& answer)
{
    // TODO
    Q_UNUSED(answer);
}
