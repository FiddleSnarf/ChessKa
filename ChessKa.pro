QT += core
QT += quick

TARGET = Chess-Ka

CONFIG += c++11
CONFIG += c++14
CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    Core/ChessBoard.cpp \
    Core/ChessCore.cpp \
    Core/CoreCommon.cpp \
    UCIProvider/UCIProcess.cpp \
    UCIProvider/UCIProvider.cpp \
    main.cpp

HEADERS += \
    Core/ChessBoard.h \
    Core/ChessCore.h \
    Core/CoreCommon.h \
    UCIProvider/UCICommon.h \
    UCIProvider/UCIProcess.h \
    UCIProvider/UCIProvider.h

TRANSLATIONS += \
    ChessKa_en_GB.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    App.qml

RESOURCES += \
    resources.qrc

# copy UCI sources
CONFIG(release, debug|release): DESTDIR = $$OUT_PWD/release
CONFIG(debug, debug|release): DESTDIR = $$OUT_PWD/debug
uci.path = $$DESTDIR
uci.files = addOn/*
INSTALLS += uci

# lib copy
isEmpty(TARGET_EXT) {
    win32 {
        TARGET_CUSTOM_EXT = .exe
    }
    macx {
        TARGET_CUSTOM_EXT = .app
    }
} else {
    TARGET_CUSTOM_EXT = $${TARGET_EXT}
}

CONFIG(release, debug|release){
    DEPLOY_TARGET = $$shell_quote($$shell_path($${OUT_PWD}/release/$${TARGET}$${TARGET_CUSTOM_EXT}))
    win32{
        DEPLOY_COMMAND = windeployqt
    }
    unix{
        # TODO
    }
    macx {
        DEPLOY_COMMAND = macdeployqt
    }
    QMAKE_POST_LINK = $${DEPLOY_COMMAND} $${DEPLOY_TARGET}
}
