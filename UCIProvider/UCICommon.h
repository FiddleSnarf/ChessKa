#pragma once

#include <QString>

namespace UCI
{
    const int PING_INTERVAL = 500;
    const int UCI_CHECK_INTERVAL = 1000;
    const int PING_LIMIT_INTERVAL = 2000;
    const QString endStr("\n");

    namespace Commands
    {
        const QString uci_com("uci");
        const QString isready_com("isready");
    }

    namespace Answers
    {
        const QString uciok_com("uciok");
        const QString readyok_com("readyok");
    }
}
