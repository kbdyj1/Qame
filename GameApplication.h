#ifndef GAMEAPPLICATION_H
#define GAMEAPPLICATION_H

#include <QObject>
#include <QQmlContext>

class QCoreApplication;
class GameApplicationPrivate;

class GameApplication : public QObject
{
    Q_OBJECT

public:
    GameApplication(QObject* parent = nullptr);
    virtual ~GameApplication();

    int exec(QCoreApplication* eventHandler, QQmlContext* context);

Q_SIGNALS:
    void gameStarted();
    void gameFinished();

private:
    GameApplicationPrivate* d;
};

#endif // GAMEAPPLICATION_H
