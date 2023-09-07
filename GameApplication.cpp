#include "GameApplication.h"
#include <QCoreApplication>

//=============================================================================
//  Private
//=============================================================================

class GameApplicationPrivate
{
public:
    bool gameExit = false;
};

//=============================================================================
//  Public
//=============================================================================

GameApplication::GameApplication(QObject* parent)
    : QObject(parent)
    , d(new GameApplicationPrivate)
{

}

GameApplication::~GameApplication()
{
    delete d;
}

int GameApplication::exec(QCoreApplication *eventHandler)
{
    emit gameStarted();

    while (!d->gameExit) {
        eventHandler->processEvents();
    }

    emit gameFinished();

    return 0;
}
