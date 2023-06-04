import QtQuick 6.5
import QtQuick.Controls 6.5
import QtPositioning 6.5
import QtLocation 6.5

Window {
    color: "red"
    height: 500
    title: qsTr("Hello World!")
    visible: true
    width: 700

    Rectangle {
        anchors.fill: parent
        anchors.margins: 10
        color: "#ffffff"

        Plugin {
            id: mapPlugin
            name: "googlemaps"
            PluginParameter {
                name: "apikey"
                value: "API_KEY_HERE"
            }
        }

        Map {
            id: map
            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
                bottom: infoText.top
            }
            plugin: mapPlugin
            zoomLevel: 14

            PositionSource {
                id: positionSource
                active: true
                updateInterval: 10000
                onPositionChanged: {
                    map.center = position.coordinate;
                }
            }

            MapCircle {
                center {
                    latitude: currentLatitude
                    longitude: currentLongitude
                }
                radius: 50.0
                color: '#446cfc'
                border.width: 3
                border.color: "#9db1fc"
            }

            property geoCoordinate startCentroid

            WheelHandler {
                id: wheel
                rotationScale: 1 / 120
                property: "zoomLevel"
            }
            DragHandler {
                id: drag
                target: null
                onTranslationChanged: delta => map.pan(-delta.x, -delta.y)
            }
            Shortcut {
                enabled: map.zoomLevel < map.maximumZoomLevel
                sequence: StandardKey.ZoomIn
                onActivated: map.zoomLevel = Math.round(map.zoomLevel + 1)
            }
            Shortcut {
                enabled: map.zoomLevel > map.minimumZoomLevel
                sequence: StandardKey.ZoomOut
                onActivated: map.zoomLevel = Math.round(map.zoomLevel - 1)
            }
        }

        Text {
            id: infoText
            text: qsTr("Latitude: %1 | Longitude: %2").arg(currentLatitude).arg(currentLongitude)
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
