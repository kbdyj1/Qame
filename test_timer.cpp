#include <QElapsedTimer>
#include <QDeadlineTimer>
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

namespace _2 {

void test()
{
    QDeadlineTimer deadline{500};

    qDebug() << "deadline: " << deadline.deadline();

    while (!deadline.hasExpired()) {
        qDebug() << "remaining: " << deadline.remainingTime() << "ms";
        usleep(1000*100);
    }
}

} //_2 --------------------------------------------------------------

} //===========================================================================

void test_timer()
{
#if (0) //done
    _1::test();
#endif

    _2::test();
}
