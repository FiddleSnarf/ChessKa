#include <QGuiApplication>
#include <QtQuick/QQuickView>

#include "UCIProvider/UCIProvider.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    UCI::UCIProvider uciProvider;
    uciProvider.startUCI("UCISources\\Stockfish\\Windows\\stockfish_10_x64.exe");

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:/App/App.qml"));
    view.show();

    return app.exec();
}
