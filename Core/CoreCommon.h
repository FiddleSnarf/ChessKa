#pragma once

#include <stdint.h>
#include <list>
#include <array>
#include <QString>
#include <QDateTime>
#include <QObject>

namespace Core
{

/// Перечисление игроков.
enum class EnPlayer : int8_t
{
    en_White,    ///< Белый игрок
    en_Black     ///< Черный игрок
};

/// Перечисление типов рокировки.
enum class EnCastling : int8_t
{
    en_Short,   ///< Короткая рокировка
    en_Long     ///< Длинная рокировка
};

/// Перечисление цвета клеток доски.
enum class EnCellColor : int8_t
{
    en_White,    ///< Белая клетка
    en_Black     ///< Черная клетка
};

/// Перечисление координат по оси X.
enum class EnXCoord : int8_t
{
    en_A = 0,   ///< A
    en_B,       ///< B
    en_C,       ///< C
    en_D,       ///< D
    en_E,       ///< E
    en_F,       ///< F
    en_G,       ///< G
    en_H,       ///< H

    en_count
};
constexpr inline int8_t toInt8(const EnXCoord& x) { return static_cast<int8_t>(x); }

/// Перечисление координат по оси Y.
enum class EnYCoord : int8_t
{
    en_1 = 0,   ///< 1
    en_2,       ///< 2
    en_3,       ///< 3
    en_4,       ///< 4
    en_5,       ///< 5
    en_6,       ///< 6
    en_7,       ///< 7
    en_8,       ///< 8

    en_count
};
constexpr inline int8_t toInt8(const EnYCoord& y){ return static_cast<int8_t>(y); }

/// Класс описывает координаты ячейки шахматной доски.
class CellCoords
{
public:
    CellCoords(EnXCoord x = EnXCoord::en_count, EnYCoord y = EnYCoord::en_count) :
        m_x(x),
        m_y(y)
    {}

    bool operator==(const CellCoords& other) const
    {
        return m_x == other.x() && m_y == other.y();
    }

    EnXCoord x() const { return m_x; }
    EnYCoord y() const { return m_y; }
    int8_t xi() const { return static_cast<int8_t>(m_x); }
    int8_t yi() const { return static_cast<int8_t>(m_y); }
    bool isValid() const { return (m_x != EnXCoord::en_count && m_y != EnYCoord::en_count); }

private:
    EnXCoord m_x; ///< Координата по оси X
    EnYCoord m_y; ///< Координата по оси Y
};
using CoordsList = std::list<CellCoords>;

/// Перечисление типов шахматных фигур.
enum class EnFigure : int8_t
{
    en_Pawn,    ///< Пешка
    en_Knight,  ///< Конь
    en_Bishop,  ///< Слон
    en_Rook,    ///< Ладья
    en_Queen,   ///< Королева
    en_King,    ///< Король
    en_None     ///< Ничего
};

/// Класс описывает шахматную фигуру.
class Figure
{
public:
    explicit Figure(){}
    explicit Figure(const EnFigure& type, const EnPlayer& player) :
        m_type(type),
        m_player(player)
    {}

    bool isEmpty() const
    {
        return m_type == EnFigure::en_None;
    }

    const EnFigure& type() const
    {
        return m_type;
    }

    const EnPlayer& player() const
    {
        return m_player;
    }

private:
    EnFigure m_type = EnFigure::en_None;
    EnPlayer m_player;
};

/// Структура описывает информацию ячейки шахматной доски.
struct Cell
{
    EnCellColor cellColor;  ///< Цвет клетки
    Figure figure;          ///< Фигура на клетке (имеет смысл только если sellState != en_Empty)

    /*!
     Метод проверяет наличие фигуры на клетке.
     */
    bool isFigureOn() const
    {
        return !figure.isEmpty();
    }
};

/// Структура представляет полную информацию об одной клетке доски
struct CellInfo
{
    CellInfo(const CellCoords& _coords, const Cell& _cell) :
        coords(_coords),
        cell(_cell)
    {}

    CellCoords coords;
    Cell cell;
};

using BoardModel = std::array<std::array<Cell, toInt8(EnYCoord::en_count)>, toInt8(EnXCoord::en_count)>;

/// Структура описывает результат выполнения.
struct Result
{
    bool state = false;         ///< Результат
    QString descr;              ///< Описание
};

/// Перечисление типов ходов шахматных фигур.
enum class EnMoveType : int8_t
{
    en_Move,    ///< Перемещение
    en_Attack   ///< Атака
};

/// Перечисление типов дополнительных событий хода.
enum class EnAddEventType : int8_t
{
    en_Castling,        ///< Рокировка
    en_PawnPromotion,   ///< Превращение пешки в любую фигуру (при достижении 8й линии)
    en_PawnTake,        ///< Взятие вражеской пешки на проходе
    en_Check,           ///< Шах
    en_Mate,            ///< Мат
    en_CheckMate        ///< Шах и мат
};

/// Структура описывает результат выполнения хода.
struct MoveResult
{
    Result res;                             ///< Результат
    EnMoveType moveType;                    ///< Тип хода
    std::list<EnAddEventType> addEvents;    ///< Дополнительные события хода
    QString comment;                        ///< Дополнительный комментарий
};

/// Структура описывает полуход партии.
struct MoveInfo
{
    MoveInfo(const Figure& _figure, const CellCoords& _from, const CellCoords& _to, const MoveResult& _res) :
        figure(_figure),
        from(_from),
        to(_to),
        result(_res)
    {}

    Figure figure;      ///< Фигура
    CellCoords from;    ///< Откуда
    CellCoords to;      ///< Куда
    MoveResult result;  ///< Результат хода
};

/// Структура содержит информацию о полуходе + временные метки
struct HistoryInfo
{
    MoveInfo moveInfo;          ///< Информация о ходе
    QDateTime globalTimestamp;  ///< Глобальная метка времени
    QTime gameTimestamp;        ///< Время прошедшее с начала партии
};
using HistoryInfoList = std::list<HistoryInfo>;

/// Функция перевода перечисления фигур в строку
QString figureToStr(const EnFigure& figure);

/// Функция возвращает противника игрока
EnPlayer enemyFor(const EnPlayer& player);

}
