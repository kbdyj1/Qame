#ifndef GAMEAPPLICATION_H
#define GAMEAPPLICATION_H

#include <QObject>

class QCoreApplication;
class GameApplicationPrivate;

class GameApplication : public QObject
{
    Q_OBJECT

public:
    GameApplication(QObject* parent = nullptr);
    virtual ~GameApplication();

    int exec(QCoreApplication* eventHandler);

Q_SIGNALS:
    void gameStarted();
    void gameFinished();

private:
    GameApplicationPrivate* d;
};

#endif // GAMEAPPLICATION_H
