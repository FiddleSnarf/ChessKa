#include "ChessBoard.h"

using namespace Core;

ChessBoard::ChessBoard()
{
    resetBoard();
}

ChessBoard::~ChessBoard()
{

}

void ChessBoard::resetBoard()
{

    auto setCell = [this](const EnXCoord& x, const EnYCoord& y, const Cell& cell)
    {
        m_board[toInt8(x)][toInt8(y)] = cell;
    };

    // Начальная расстановка белых фигур
    setCell(EnXCoord::en_A, EnYCoord::en_1, { EnCellColor::en_Black, Figure(EnFigure::en_Rook, EnPlayer::en_White) });      // Ладья  (1-A)
    setCell(EnXCoord::en_B, EnYCoord::en_1, { EnCellColor::en_White, Figure(EnFigure::en_Knight, EnPlayer::en_White) });    // Конь   (1-B)
    setCell(EnXCoord::en_C, EnYCoord::en_1, { EnCellColor::en_Black, Figure(EnFigure::en_Bishop, EnPlayer::en_White) });    // Слон   (1-C)
    setCell(EnXCoord::en_D, EnYCoord::en_1, { EnCellColor::en_White, Figure(EnFigure::en_Queen, EnPlayer::en_White) });     // Ферзь  (1-D)
    setCell(EnXCoord::en_E, EnYCoord::en_1, { EnCellColor::en_Black, Figure(EnFigure::en_King, EnPlayer::en_White) });      // Король (1-E)
    setCell(EnXCoord::en_F, EnYCoord::en_1, { EnCellColor::en_White, Figure(EnFigure::en_Bishop, EnPlayer::en_White) });    // Слон   (1-F)
    setCell(EnXCoord::en_G, EnYCoord::en_1, { EnCellColor::en_Black, Figure(EnFigure::en_Knight, EnPlayer::en_White) });    // Конь   (1-G)
    setCell(EnXCoord::en_H, EnYCoord::en_1, { EnCellColor::en_White, Figure(EnFigure::en_Rook, EnPlayer::en_White) });      // Ладья  (1-H)

    setCell(EnXCoord::en_A, EnYCoord::en_2, { EnCellColor::en_White, Figure(EnFigure::en_Pawn, EnPlayer::en_White) });      // Пешка (2-A)
    setCell(EnXCoord::en_B, EnYCoord::en_2, { EnCellColor::en_Black, Figure(EnFigure::en_Pawn, EnPlayer::en_White) });      // Пешка (2-B)
    setCell(EnXCoord::en_C, EnYCoord::en_2, { EnCellColor::en_White, Figure(EnFigure::en_Pawn, EnPlayer::en_White) });      // Пешка (2-C)
    setCell(EnXCoord::en_D, EnYCoord::en_2, { EnCellColor::en_Black, Figure(EnFigure::en_Pawn, EnPlayer::en_White) });      // Пешка (2-D)
    setCell(EnXCoord::en_E, EnYCoord::en_2, { EnCellColor::en_White, Figure(EnFigure::en_Pawn, EnPlayer::en_White) });      // Пешка (2-E)
    setCell(EnXCoord::en_F, EnYCoord::en_2, { EnCellColor::en_Black, Figure(EnFigure::en_Pawn, EnPlayer::en_White) });      // Пешка (2-F)
    setCell(EnXCoord::en_G, EnYCoord::en_2, { EnCellColor::en_White, Figure(EnFigure::en_Pawn, EnPlayer::en_White) });      // Пешка (2-G)
    setCell(EnXCoord::en_H, EnYCoord::en_2, { EnCellColor::en_Black, Figure(EnFigure::en_Pawn, EnPlayer::en_White) });      // Пешка (2-H)

    // Начальная расстановка черных фигур
    setCell(EnXCoord::en_A, EnYCoord::en_8, { EnCellColor::en_White, Figure(EnFigure::en_Rook, EnPlayer::en_Black) });      // Ладья  (8-A)
    setCell(EnXCoord::en_B, EnYCoord::en_8, { EnCellColor::en_Black, Figure(EnFigure::en_Knight, EnPlayer::en_Black) });    // Конь   (8-B)
    setCell(EnXCoord::en_C, EnYCoord::en_8, { EnCellColor::en_White, Figure(EnFigure::en_Bishop, EnPlayer::en_Black) });    // Слон   (8-C)
    setCell(EnXCoord::en_D, EnYCoord::en_8, { EnCellColor::en_Black, Figure(EnFigure::en_Queen, EnPlayer::en_Black) });     // Ферзь  (8-D)
    setCell(EnXCoord::en_E, EnYCoord::en_8, { EnCellColor::en_White, Figure(EnFigure::en_King, EnPlayer::en_Black) });      // Король (8-E)
    setCell(EnXCoord::en_F, EnYCoord::en_8, { EnCellColor::en_Black, Figure(EnFigure::en_Bishop, EnPlayer::en_Black) });    // Слон   (8-F)
    setCell(EnXCoord::en_G, EnYCoord::en_8, { EnCellColor::en_White, Figure(EnFigure::en_Knight, EnPlayer::en_Black) });    // Конь   (8-G)
    setCell(EnXCoord::en_H, EnYCoord::en_8, { EnCellColor::en_Black, Figure(EnFigure::en_Rook, EnPlayer::en_Black) });      // Ладья  (8-H)

    setCell(EnXCoord::en_A, EnYCoord::en_7, { EnCellColor::en_Black, Figure(EnFigure::en_Pawn, EnPlayer::en_Black) });      // Пешка (7-A)
    setCell(EnXCoord::en_B, EnYCoord::en_7, { EnCellColor::en_White, Figure(EnFigure::en_Pawn, EnPlayer::en_Black) });      // Пешка (7-B)
    setCell(EnXCoord::en_C, EnYCoord::en_7, { EnCellColor::en_Black, Figure(EnFigure::en_Pawn, EnPlayer::en_Black) });      // Пешка (7-C)
    setCell(EnXCoord::en_D, EnYCoord::en_7, { EnCellColor::en_White, Figure(EnFigure::en_Pawn, EnPlayer::en_Black) });      // Пешка (7-D)
    setCell(EnXCoord::en_E, EnYCoord::en_7, { EnCellColor::en_Black, Figure(EnFigure::en_Pawn, EnPlayer::en_Black) });      // Пешка (7-E)
    setCell(EnXCoord::en_F, EnYCoord::en_7, { EnCellColor::en_White, Figure(EnFigure::en_Pawn, EnPlayer::en_Black) });      // Пешка (7-F)
    setCell(EnXCoord::en_G, EnYCoord::en_7, { EnCellColor::en_Black, Figure(EnFigure::en_Pawn, EnPlayer::en_Black) });      // Пешка (7-G)
    setCell(EnXCoord::en_H, EnYCoord::en_7, { EnCellColor::en_White, Figure(EnFigure::en_Pawn, EnPlayer::en_Black) });      // Пешка (7-H)

    // Сбрасываем историю
    m_history.clear();
}

Cell ChessBoard::getCellInfo(const CellCoords& coords) const
{
    if (!coords.isValid())
        return Cell();

    return m_board[coords.xi()][coords.yi()];
}

const BoardModel& ChessBoard::getBoardInfo() const
{
    return m_board;
}

CoordsList ChessBoard::getMovesForFigure(const CellCoords& coords) const
{
    const auto& cell = getCellInfo(coords);
    if (!cell.isFigureOn())
        return CoordsList();

    const auto player = cell.figure.player();
    switch(cell.figure.type())
    {
        case EnFigure::en_Pawn: return getMovesForPawn(coords, player);
        case EnFigure::en_Rook: return getMovesForRook(coords, player);
        case EnFigure::en_Bishop: return getMovesForBishop(coords, player);
        case EnFigure::en_Knight: return getMovesForKnight(coords, player);
        case EnFigure::en_Queen: return getMovesForQueen(coords, player);
        case EnFigure::en_King: return getMovesForKing(coords, player);
        default: return CoordsList();
    }
}

CoordsList ChessBoard::getMovesForPawn(const CellCoords& coords, const EnPlayer& player) const
{
    /* Особенности пешек:
     * - ходят и бьют по разному
     * - только в одну сторону
     * - превращаются в любую фигуру при достижении конца доски
     * - возможен первый ход через одну клетку
     * - для пешек работает правило "взятие на проходе"
     */

    CoordsList moves;
    if (coords.y() != EnYCoord::en_1 && coords.y() != EnYCoord::en_8)
    {
        auto checkAttack = [this, player](int8_t x, int8_t y)
        {
            auto c = m_board[x][y];
            return c.isFigureOn() && (c.figure.player() != player);
        };

        if (player == EnPlayer::en_White) // белая пешка
        {
            // Проверяем на одинарный шаг
            if (!m_board[coords.xi()][coords.yi() + 1].isFigureOn())
                moves.emplace_back(coords.x(), static_cast<EnYCoord>(coords.yi() + 1));

            // Проверяем на двойной шаг
            if (coords.y() == EnYCoord::en_2 && !m_board[coords.xi()][coords.yi() + 1].isFigureOn() && !m_board[coords.xi()][coords.yi() + 2].isFigureOn())
                moves.emplace_back(coords.x(), static_cast<EnYCoord>(coords.yi() + 2));

            // Проверяем возможность бить влево
            const int8_t y = coords.yi() + 1;
            const int8_t xl = coords.xi() - 1;
            if (coords.x() != EnXCoord::en_A && checkAttack(xl, y))
                moves.emplace_back(static_cast<EnXCoord>(xl), static_cast<EnYCoord>(y));

            // Проверяем возможность бить вправо
            const int8_t xr = coords.xi() + 1;
            if (coords.x() != EnXCoord::en_H && checkAttack(xr, y))
                moves.emplace_back(static_cast<EnXCoord>(xr), static_cast<EnYCoord>(y));
        }
        else
        {
            // Проверяем на одинарный шаг
            if (!m_board[coords.xi()][coords.yi() - 1].isFigureOn())
                moves.emplace_back(coords.x(), static_cast<EnYCoord>(coords.yi() - 1));

            // Проверяем на двойной шаг
            if (coords.y() == EnYCoord::en_7 && !m_board[coords.xi()][coords.yi() - 1].isFigureOn() && !m_board[coords.xi()][coords.yi() - 2].isFigureOn())
                moves.emplace_back(coords.x(), static_cast<EnYCoord>(coords.yi() - 2));

            // Проверяем возможность бить влево
            const int8_t y = coords.yi() - 1;
            const int8_t xl = coords.xi() - 1;
            if (coords.x() != EnXCoord::en_A && checkAttack(xl, y))
                moves.emplace_back(static_cast<EnXCoord>(xl), static_cast<EnYCoord>(y));

            // Проверяем возможность бить вправо
            const int8_t xr = coords.xi() + 1;
            if (coords.x() != EnXCoord::en_H && checkAttack(xr, y))
                moves.emplace_back(static_cast<EnXCoord>(xr), static_cast<EnYCoord>(y));
        }

        // Проверяем "взятие на проходе"
        const EnYCoord needY = (player == EnPlayer::en_White) ? EnYCoord::en_5 : EnYCoord::en_4;
        if (!m_history.empty() && coords.y() == needY)
        {
            auto last = m_history.back(); // Последний ход партии
            if (last.moveInfo.figure.type() == EnFigure::en_Pawn &&                 // Если ходила пешка
                last.moveInfo.figure.player() != player &&                          // Если это была пешка другого игрока
                (std::abs(last.moveInfo.to.yi() - last.moveInfo.from.yi()) == 2))   // Если она сделала двойной ход
            {
                const EnYCoord targetY = (player == EnPlayer::en_White) ? EnYCoord::en_6 : EnYCoord::en_3;
                const int8_t xl = coords.xi() - 1;
                if (coords.x() != EnXCoord::en_A && last.moveInfo.to.xi() == xl)
                    moves.emplace_back(static_cast<EnXCoord>(xl), targetY);

                const int8_t xr = coords.xi() + 1;
                if (coords.x() != EnXCoord::en_H && last.moveInfo.to.xi() == xr)
                    moves.emplace_back(static_cast<EnXCoord>(xr), targetY);
            }
        }
    }
    return moves;
}

CoordsList ChessBoard::getMovesForKnight(const CellCoords& coords, const EnPlayer& player) const
{
    CoordsList moves;
    auto checkMove = [this, player, &moves](int8_t _x, int8_t _y)
    {
        if(!outOfRange(_x, _y) && (m_board[_x][_y].isFigureOn() && m_board[_x][_y].figure.player() != player))
            moves.emplace_back(static_cast<EnXCoord>(_x), static_cast<EnYCoord>(_y));
    };

    const int8_t x = coords.xi();
    const int8_t y = coords.yi();
    checkMove(x - 1, y + 2);
    checkMove(x + 1, y + 2);
    checkMove(x - 1, y - 2);
    checkMove(x + 1, y - 2);
    checkMove(x + 2, y + 1);
    checkMove(x + 2, y - 1);
    checkMove(x - 2, y + 1);
    checkMove(x - 2, y - 1);
    return moves;
}

CoordsList ChessBoard::getMovesForBishop(const CellCoords& coords, const EnPlayer& player) const
{
    CoordsList moves;
    enum class EnDirection : int8_t
    {
        enTopLeft,
        enTopRight,
        enBottomLeft,
        enBottomRight
    };

    auto addMovesForDir = [this, coords, player, &moves](const EnDirection& dir)
    {
        int8_t x = coords.xi();
        int8_t y = coords.yi();
        for(;;)
        {
            switch(dir)
            {
                case EnDirection::enTopLeft: ++y; --x; break;
                case EnDirection::enTopRight: ++y; ++x; break;
                case EnDirection::enBottomLeft: --y; --x; break;
                case EnDirection::enBottomRight: --y; ++x; break;
                default: return;
            }

            // Если вышли за пределы доски или если встретилась союзная фигура, то дальше идти нельзя
            if(outOfRange(x, y) || (m_board[x][y].isFigureOn() && m_board[x][y].figure.player() == player))
                return;
            // Если встретили фигуру противника, то ее бить можно, но дальше не идем
            else if (const auto& cell = m_board[x][y]; cell.isFigureOn() && cell.figure.player() != player)
            {
                moves.emplace_back(static_cast<EnXCoord>(x), static_cast<EnYCoord>(y));
                return;
            }
            // Иначе сюда можно ходить, смотрим дальше
            else
                moves.emplace_back(static_cast<EnXCoord>(x), static_cast<EnYCoord>(y));
        }
    };

    addMovesForDir(EnDirection::enTopLeft);
    addMovesForDir(EnDirection::enTopRight);
    addMovesForDir(EnDirection::enBottomLeft);
    addMovesForDir(EnDirection::enBottomRight);
    return moves;
}

CoordsList ChessBoard::getMovesForRook(const CellCoords& coords, const EnPlayer& player) const
{
    CoordsList moves;
    enum class EnDirection : int8_t
    {
        enTop,
        enLeft,
        enRight,
        enBottom
    };

    auto addMovesForDir = [this, coords, player, &moves](const EnDirection& dir)
    {
        int8_t x = coords.xi();
        int8_t y = coords.yi();
        for(;;)
        {
            switch(dir)
            {
                case EnDirection::enTop: ++y; break;
                case EnDirection::enLeft: --x; break;
                case EnDirection::enRight: ++x; break;
                case EnDirection::enBottom: --y; break;
                default: return;
            }

            // Если вышли за пределы доски или если встретилась союзная фигура, то дальше идти нельзя
            if(outOfRange(x, y) || (m_board[x][y].isFigureOn() && m_board[x][y].figure.player() == player))
                return;
            // Если встретили фигуру противника, то ее бить можно, но дальше не идем
            else if (const auto& cell = m_board[x][y]; cell.isFigureOn() && cell.figure.player() != player)
            {
                moves.emplace_back(static_cast<EnXCoord>(x), static_cast<EnYCoord>(y));
                return;
            }
            // Иначе сюда можно ходить, смотрим дальше
            else
                moves.emplace_back(static_cast<EnXCoord>(x), static_cast<EnYCoord>(y));
        }
    };

    addMovesForDir(EnDirection::enTop);
    addMovesForDir(EnDirection::enLeft);
    addMovesForDir(EnDirection::enRight);
    addMovesForDir(EnDirection::enBottom);
    return moves;
}

CoordsList ChessBoard::getMovesForQueen(const CellCoords& coords, const EnPlayer& player) const
{
    auto moves1 = getMovesForBishop(coords, player);
    auto moves2 = getMovesForRook(coords, player);
    moves1.splice(moves1.end(), moves2);
    return moves1;
}

CoordsList ChessBoard::getMovesForKing(const CellCoords& coords, const EnPlayer& player) const
{
    CoordsList moves;
    auto checkMove = [this, player, &moves](int8_t _x, int8_t _y)
    {
        if(!outOfRange(_x, _y) && (m_board[_x][_y].isFigureOn() && m_board[_x][_y].figure.player() != player))
        {
            // Король в отличие от других фигур не может быть бит, так что проверяем клетку на нахождение под боем
            if (!isAttackedCell({ static_cast<EnXCoord>(_x), static_cast<EnYCoord>(_y) }, player))
                moves.emplace_back(static_cast<EnXCoord>(_x), static_cast<EnYCoord>(_y));
        }
    };

    const int8_t x = coords.xi();
    const int8_t y = coords.yi();
    checkMove(x, y + 1);        // Верх
    checkMove(x, y - 1);        // Низ
    checkMove(x - 1, y);        // Лево
    checkMove(x + 1, y);        // Право
    checkMove(x - 1, y + 1);    // Верх-Лево
    checkMove(x - 1, y - 1);    // Низ-Лево
    checkMove(x + 1, y + 1);    // Верх-Право
    checkMove(x + 1, y - 1);    // Низ-Право
    return moves;
}

bool ChessBoard::outOfRange(int8_t x, int8_t y) const
{
    return x < toInt8(EnXCoord::en_A) ||
           x > toInt8(EnXCoord::en_H) ||
           y < toInt8(EnYCoord::en_1) ||
           y > toInt8(EnYCoord::en_8);
}

bool ChessBoard::isCheckSituation(const EnPlayer& player, CoordsList& attackingFigures) const
{
    attackingFigures.clear();
    bool isCheck = false;
    const auto kingCoords = playerKingCoords(player);
    const auto enemyPlayer = enemyFor(player);
    for(const auto& enemyCoords : playerFiguresCoords(enemyPlayer))
    {
        CoordsList enemyMoves;
        switch(getCellInfo(enemyCoords).figure.type())
        {
            case EnFigure::en_Pawn: enemyMoves = getMovesForPawn(enemyCoords, enemyPlayer); break;
            case EnFigure::en_Rook: enemyMoves = getMovesForRook(enemyCoords, enemyPlayer); break;
            case EnFigure::en_Bishop: enemyMoves = getMovesForBishop(enemyCoords, enemyPlayer); break;
            case EnFigure::en_Knight: enemyMoves = getMovesForKnight(enemyCoords, enemyPlayer); break;
            case EnFigure::en_Queen: enemyMoves = getMovesForQueen(enemyCoords, enemyPlayer); break;
            case EnFigure::en_King: enemyMoves = getMovesForKing(enemyCoords, enemyPlayer); break;
            default: break;
        }
        if (std::find(enemyMoves.cbegin(), enemyMoves.cend(), kingCoords) != enemyMoves.cend())
        {
            attackingFigures.push_back(enemyCoords);
            isCheck = true;
        }
    }
    return isCheck;
}

bool ChessBoard::isCheckMateSituation(const EnPlayer& player) const
{
    // TODO
    return false;
}

CoordsList ChessBoard::playerFiguresCoords(const EnPlayer& player) const
{
    CoordsList coords;
    for(int8_t x = 0; x < static_cast<int8_t>(m_board.size()); ++x)
    {
        for(int8_t y = 0; y < static_cast<int8_t>(m_board[x].size()); ++y)
        {
            const auto cell = m_board[x][y];
            if (cell.isFigureOn() && cell.figure.player() == player)
                coords.emplace_back(static_cast<EnXCoord>(x), static_cast<EnYCoord>(y));
        }
    }
    return coords;
}

CellCoords ChessBoard::playerKingCoords(const EnPlayer& player) const
{
    for(int8_t x = 0; x < static_cast<int8_t>(m_board.size()); ++x)
    {
        for(int8_t y = 0; y < static_cast<int8_t>(m_board[x].size()); ++y)
        {
            const auto cell = m_board[x][y];
            if (cell.isFigureOn() && cell.figure.player() == player && cell.figure.type() == EnFigure::en_King)
                return CellCoords(static_cast<EnXCoord>(x), static_cast<EnYCoord>(y));
        }
    }
    return CellCoords();
}

bool ChessBoard::isAttackedCell(const CellCoords& coords, const EnPlayer& player) const
{
    const auto enemyPlayer = enemyFor(player);
    for(const auto& enemyCoords : playerFiguresCoords(enemyPlayer))
    {
        CoordsList enemyMoves;
        switch(getCellInfo(enemyCoords).figure.type())
        {
            case EnFigure::en_Pawn: enemyMoves = getMovesForPawn(enemyCoords, enemyPlayer); break;
            case EnFigure::en_Rook: enemyMoves = getMovesForRook(enemyCoords, enemyPlayer); break;
            case EnFigure::en_Bishop: enemyMoves = getMovesForBishop(enemyCoords, enemyPlayer); break;
            case EnFigure::en_Knight: enemyMoves = getMovesForKnight(enemyCoords, enemyPlayer); break;
            case EnFigure::en_Queen: enemyMoves = getMovesForQueen(enemyCoords, enemyPlayer); break;
            case EnFigure::en_King: enemyMoves = getMovesForKing(enemyCoords, enemyPlayer); break;
            default: break;
        }
        if (std::find(enemyMoves.cbegin(), enemyMoves.cend(), coords) != enemyMoves.cend())
            return true;
    }
    return false;
}

bool ChessBoard::isCanCastling(const EnPlayer& player, const EnCastling& castlingType) const
{
    // TODO
    return false;
}

bool ChessBoard::move(const CellCoords& from, const CellCoords& to)
{
    // TODO
    return false;
}

bool ChessBoard::move(int8_t x_from, int8_t y_from, int8_t x_to, int8_t y_to)
{
    if (outOfRange(x_from, y_from) || outOfRange(x_to, y_to))
        return false;

    return move({ static_cast<EnXCoord>(x_from), static_cast<EnYCoord>(y_from) }, { static_cast<EnXCoord>(x_to), static_cast<EnYCoord>(y_to) });
}

bool ChessBoard::castling(const EnPlayer& player, const EnCastling& castlingType)
{
    if (isCanCastling(player, castlingType))
    {
        //TODO
    }
    return false;
}
