#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#if QT_CONFIG(permissions)
#include <QPermission>
#endif

#include <QtPositioning/QGeoPositionInfoSource>
#include <QtPositioning/QGeoCoordinate>

int main(int argc, char *argv[])
{
    QGuiApplication application(argc, argv);
    QQmlApplicationEngine engine;

#if QT_CONFIG(permissions)
    QLocationPermission locationPermission;
    locationPermission.setAccuracy(QLocationPermission::Precise);
    application.requestPermission(locationPermission, [&](const QPermission &info)
                                  {
        if(info.status() ==Qt::PermissionStatus::Granted){
            // Create a QGeoPositionInfoSource object and request location updates
            QGeoPositionInfoSource *posSource = QGeoPositionInfoSource::createDefaultSource(nullptr);
            if (posSource)
            {
                qDebug() << "Cpp: Getting User Location";
                posSource->setUpdateInterval(10); // Update the location every 10000 ms
                posSource->startUpdates();           // Start receiving location updates
                // Retrieve the latitude and longitude from the position information
                QObject::connect(posSource, &QGeoPositionInfoSource::positionUpdated, &application, [&](const QGeoPositionInfo &info)
                                 {
                                     const qreal latitude = info.coordinate().latitude();
                                     const qreal longitude = info.coordinate().longitude();
                                     qDebug() << "Cpp: Latitude: " << latitude << " | Longitude: " << longitude;

                                     // Update the QML UI with the new location information
                                     engine.rootContext()->setContextProperty("currentLatitude", latitude);
                                     engine.rootContext()->setContextProperty("currentLongitude", longitude);
                                 });
            }
            else
            {
                qDebug() << "Cpp: Failed to create Position Info source";
            }
        }else{
            qDebug() << "Cpp: Permission Denied";
        } });

#endif

    const QUrl url(u"qrc:/mainLib/interfaces/main.qml"_qs);
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &application, [url](QObject *obj, const QUrl &objUrl)
        {
        if(!obj && objUrl == url)
            QGuiApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    qDebug() << "Applicaiton name: " << QGuiApplication::applicationName();
    application.setApplicationVersion("1.0.0");
    qDebug() << "Applicaiton version: " << QGuiApplication::applicationVersion();
    qDebug() << "Platform name: " << QGuiApplication::platformName();
    qDebug() << "Platform name: " << application.platformName();
    qDebug() << "Device pixel ratio: " << application.devicePixelRatio();

    return application.exec();
}
