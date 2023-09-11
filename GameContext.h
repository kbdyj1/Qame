#ifndef GAMECONTEXT_H
#define GAMECONTEXT_H

#include <QObject>

class GameContext : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int HumanCount READ getHumanCount WRITE setHumanCount NOTIFY humanCountChanged)
    Q_PROPERTY(int ZombiCount READ getZombiCount WRITE setZombiCount NOTIFY zombiCountChanged)

public:
    GameContext(QObject* parent) : QObject(parent)
    {}
    virtual ~GameContext()
    {}

    void setHumanCount(int cnt)
    {
        if (humanCount != cnt) {
            humanCount = cnt;
            emit humanCountChanged(humanCount);
        }
    }
    int getHumanCount() const
    {
        return humanCount;
    }

    void setZombiCount(int cnt)
    {
        if (zombiCount != cnt) {
            zombiCount = cnt;
            emit zombiCountChanged(zombiCount);
        }
    }
    int getZombiCount() const
    {
        return zombiCount;
    }

signals:
    void humanCountChanged(int humanCount);
    void zombiCountChanged(int zombiCount);

private:
    int humanCount = 0;
    int zombiCount = 0;
};

#endif // GAMECONTEXT_H
