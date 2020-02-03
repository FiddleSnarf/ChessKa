#pragma once

#include "CoreCommon.h"

namespace Core
{

class ChessBoard
{
public:
    explicit ChessBoard();
    virtual ~ChessBoard();

    /// Устанавливает состояние доски в начальное
    void resetBoard();

    /// Возвращает информацию о состоянии клетки
    Cell getCellInfo(const CellCoords& coords) const;

    /// Возвращает информацию о состоянии доски
    const BoardModel& getBoardInfo() const;

    /// Возвращает список возможных ходов для фигуры в указанных координатах (если там нет фигуры, то вернет пустой список)
    CoordsList getMovesForFigure(const CellCoords& coords) const;

    /// Проверка на шах для игрока (если шах имеет место быть, то в attackingFigures будут помещены координаты атакующих фигур)
    bool isCheckSituation(const EnPlayer& player, CoordsList& attackingFigures) const;

    /// Проверка на мат для игрока
    bool isCheckMateSituation(const EnPlayer& player) const;

    /// Проверка на возможность рокировки для игрока
    bool isCanCastling(const EnPlayer& player, const EnCastling& castlingType) const;

    bool move(const CellCoords& from, const CellCoords& to);
    bool move(int8_t x_from, int8_t y_from, int8_t x_to, int8_t y_to);
    bool castling(const EnPlayer& player, const EnCastling& castlingType);

private:
    CoordsList getMovesForPawn(const CellCoords& coords, const EnPlayer& player) const;     ///< Получить список возможных ходов для пешки
    CoordsList getMovesForKnight(const CellCoords& coords, const EnPlayer& player) const;   ///< Получить список возможных ходов для коня
    CoordsList getMovesForBishop(const CellCoords& coords, const EnPlayer& player) const;   ///< Получить список возможных ходов для слона
    CoordsList getMovesForRook(const CellCoords& coords, const EnPlayer& player) const;     ///< Получить список возможных ходов для ладьи
    CoordsList getMovesForQueen(const CellCoords& coords, const EnPlayer& player) const;    ///< Получить список возможных ходов для королевы
    CoordsList getMovesForKing(const CellCoords& coords, const EnPlayer& player) const;     ///< Получить список возможных ходов для короля

    /// Проверка выхода за границы доски
    bool outOfRange(int8_t x, int8_t y) const;

    /// Получение списка координат на которых находятся фигуры игрока
    CoordsList playerFiguresCoords(const EnPlayer& player) const;

    /// Получение координат короля игрока
    CellCoords playerKingCoords(const EnPlayer& player) const;

    /// Проверка на то находится ли данная координата под атакой фигуры противника
    bool isAttackedCell(const CellCoords& coords, const EnPlayer& player) const;

private:
    BoardModel m_board;         ///< Хранит информацию о состоянии всех ячеек доски
    HistoryInfoList m_history;  ///< История ходов
};

}
