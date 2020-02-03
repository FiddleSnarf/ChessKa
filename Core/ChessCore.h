#pragma once

#include <memory>

namespace Core
{

class ChessCore
{
public:
    explicit ChessCore();
    virtual ~ChessCore();

private:
    std::unique_ptr<class ChessBoard> m_board;
};

}
