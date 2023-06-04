#include <QObject>
#include <QtPositioning/QGeoPositionInfoSource>
#include <QtPositioning/QGeoAreaMonitorSource>
#include <QtPositioning/QGeoSatelliteInfoSource>

class MyClass : public QObject
{
    Q_OBJECT
public:
    MyClass(QObject *parent = 0)
        : QObject(parent)
    {
        QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
        if (source)
        {
            qDebug() << "Geo Position Info Source";
        }

        QGeoAreaMonitorSource *source2 = QGeoAreaMonitorSource::createDefaultSource(this);

        if (source2)
        {
            qDebug() << "Geo Area Monitor Source";
        }

        QGeoSatelliteInfoSource *source3 = QGeoSatelliteInfoSource::createDefaultSource(this);

        if (source3)
        {
            qDebug() << "Geo Satellite Info Source";
        }
    }

private slots:
};