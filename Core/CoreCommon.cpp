#include "CoreCommon.h"

QString Core::figureToStr(const EnFigure& figure)
{
    switch(figure)
    {
        case EnFigure::en_Pawn: return QObject::tr("pawn");
        case EnFigure::en_Knight: return QObject::tr("knight");
        case EnFigure::en_Bishop: return QObject::tr("bishop");
        case EnFigure::en_Rook: return QObject::tr("rook");
        case EnFigure::en_Queen: return QObject::tr("queen");
        case EnFigure::en_King: return QObject::tr("king");
        default: return QString();
    }
}

Core::EnPlayer Core::enemyFor(const Core::EnPlayer& player)
{
    return player == Core::EnPlayer::en_White ? Core::EnPlayer::en_Black : Core::EnPlayer::en_White;
}
