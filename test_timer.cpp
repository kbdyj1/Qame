#include <QElapsedTimer>
#include <QDebug>
#include <unistd.h>

namespace { //=================================================================

namespace _1 {

void test()
{
    QElapsedTimer elapsedTimer;

    elapsedTimer.start();
    sleep(1);

    qDebug() << "monotonic? " << QElapsedTimer::isMonotonic();
    qDebug() << "sleep(1) : " << elapsedTimer.elapsed() << "ms";
    qDebug() << "nsecsElapsed(1) : " << elapsedTimer.nsecsElapsed() << "ns";
    qDebug() << "msecsSinceReference: " << elapsedTimer.msecsSinceReference();
    qDebug() << "clockType? " << elapsedTimer.clockType();
    qDebug() << "expired(1000)? " << elapsedTimer.hasExpired(1000);
    qDebug() << "expired(1010)? " << elapsedTimer.hasExpired(1010);
}

} //_1 --------------------------------------------------------------

} //===========================================================================

void test_timer()
{
    _1::test();
}
