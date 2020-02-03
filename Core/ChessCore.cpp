#include "ChessCore.h"
#include "ChessBoard.h"

using namespace Core;

ChessCore::ChessCore() :
    m_board(std::make_unique<ChessBoard>())
{

}

ChessCore::~ChessCore()
{

}
