#include "GameApplication.h"
#include <QCoreApplication>
#include <QElapsedTimer>

//=============================================================================
//  Private
//=============================================================================

class GameApplicationPrivate
{
public:
    QQmlContext* context = nullptr;
    bool gameExit = false;
    QElapsedTimer elapsedTimer;
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

int GameApplication::exec(QCoreApplication *eventHandler, QQmlContext* context)
{
    d->context = context;

    int frameCount = 0;
    float fps = 0.0;

    emit gameStarted();

    d->elapsedTimer.start();

    while (!d->gameExit) {
        eventHandler->processEvents();
        frameCount++;
        fps = frameCount / (d->elapsedTimer.elapsed() / 1000.0f);
        d->context->setContextProperty("fps", fps);
    }

    emit gameFinished();

    return 0;
}
