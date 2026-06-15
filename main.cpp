#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QUrl>

int main(int argc, char *argv[])
{
    // 1. Initialize the Core GUI Application instance
    QGuiApplication app(argc, argv);

    // 2. Instantiate the QML Runtime Engine
    QQmlApplicationEngine engine;

    // 3. Define the virtual Qt Resource (QRC) path to your Main interface
    // CRITICAL: This path follows the strict Qt 6 convention:
    // qrc:/qt/qml/ + [Your CMake Module URI Name] + / + [Your File Name].qml
    const QUrl url(QStringLiteral("qrc:/qt/qml/TelemetryHub/Main.qml"));

    // 4. Advanced Safety Hook: Catch component creation failures cleanly.
    // If the QML file contains syntax errors, broken layout bindings, or path mismatches,
    // this lambda executes instantly and closes the binary gracefully.
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    // 5. Instruct the engine engine to parse and load the UI layout file
    engine.load(url);

    // 6. Enter the main application event loop processing cycle
    return app.exec();
}