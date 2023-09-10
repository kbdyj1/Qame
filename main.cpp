#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "GameApplication.h"

//#define USE_QAPPLICATION

#if defined(USE_QAPPLICATION)
void test_timer();
#endif

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    GameApplication game;

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

#if defined(USE_QAPPLICATION)
    test_timer();

    return app.exec();
#else
    auto* rootContext = engine.rootContext();
    return game.exec(&app, rootContext);
#endif
}
