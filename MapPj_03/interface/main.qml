import QtQuick 6.0
import QtQuick.Controls 6.0
import QtPositioning
import QtLocation

Window {
    width: 800
    height: 560

    visible: true
    title: "Google map"

    Rectangle {
        id: mainRec

        anchors {
            fill: parent
            margins: 20
        }
        color: "red"

        Plugin {
            id: mapPlugin
            name: "googlemaps"
            PluginParameter {
                name: "apikey"
                value: "API_KEY_HERE"
            }
        }

        PositionSource {
            id: positionSource
            active: true
            updateInterval: 1000

            onPositionChanged: {
                var coordin = positionSource.position.coordinate;
                console.log("Coordinate:", coordin.longitude, coordin.latitude);
            }

            Component.onCompleted: {
                var coordin = positionSource.position.coordinate;
                console.log("Coordinate:", coordin.longitude, coordin.latitude);
            }
        }
    }
}
