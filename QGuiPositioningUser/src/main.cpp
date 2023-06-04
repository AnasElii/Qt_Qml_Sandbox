#include "pch.h"
#include <winrt/Windows.Devices.Geolocation.Geofencing.h>
#include <iostream>
#include <objbase.h>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QtPositioning/QGeoPositionInfoSource>
#include <QtPositioning/QGeoCoordinate>

using namespace std;
using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Devices::Geolocation;

int main(int argc, char *argv[])
{
    try
    {
        init_apartment();
    }
    catch (const std::exception& ex)
    {
        std::cout << "Initialise Apartment Error :) " << ex.what() << std::endl;
    }

    Geolocator geolocator;
    geolocator.DesiredAccuracy(PositionAccuracy::High);

    auto accessStatus = Geolocator::RequestAccessAsync().get();

    if (accessStatus != GeolocationAccessStatus::Allowed)
    {
        std::cout << "Location access not granted" << std::endl;
        return 0;
    }

    auto location = geolocator.GetGeopositionAsync().get().Coordinate().Point().Position();

    double latitude = location.Latitude;
    double longitude = location.Longitude;

    std::cout << "Latitude: " << latitude << std::endl;
    std::cout << "Longitude: " << longitude << std::endl;

    QGuiApplication application(argc, argv);
    QQmlApplicationEngine engine;

    qDebug() << "Trying Position Info";
    // Create a QGeoPositionInfoSource object and request location updates
    QGeoPositionInfoSource* posSource = QGeoPositionInfoSource::createDefaultSource(nullptr);
    if (posSource)
    {
        qreal gLatitude;
        qreal gLongitude;
        qDebug() << "Position Info created";
        posSource->setUpdateInterval(10000); // Update the location every 1000 ms
        posSource->startUpdates();           // Start receiving location updates
        // Retrieve the latitude and longitude from the position information
        QObject::connect(posSource, &QGeoPositionInfoSource::positionUpdated, &application, [&](const QGeoPositionInfo& info)
            {

                const qreal latitude = info.coordinate().latitude();
                const qreal longitude = info.coordinate().longitude();
                qDebug() << "Latitude: " << latitude << " | Longitude: " << longitude;
                // Update the QML UI with the new location information
                engine.rootContext()->setContextProperty("currentLatitude", latitude);
                engine.rootContext()->setContextProperty("currentLongitude", longitude); });
    }
    else
    {
        qDebug() << "Failed to create Position Info source";
    }

    const QUrl url(u"qrc:/res/interfaces/main.qml"_qs);
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &application, [url](QObject *obj, const QUrl &objUrl)
        {
        if(!obj && objUrl == url)
            QGuiApplication::exit(-1); },
        Qt::QueuedConnection);
    
    engine.load(url);
    return application.exec();
}