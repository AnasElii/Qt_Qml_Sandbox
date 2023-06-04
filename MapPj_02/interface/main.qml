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
                value: "GoogleMap_Api_Key"
            }
        }

        Map {
            id: map

            plugin: mapPlugin

            center: QtPositioning.coordinate(33.899689722811225, -6.340254435866118) // Tilet
            zoomLevel: 14

            anchors.fill: parent

            MapItemView {
                model: []
            }

            // property geoCoordinate startCentroid
            // PinchHandler {
            //     id: pinch
            //     target: null
            //     onActiveChanged: if (active) {
            //         map.startCentroid = map.toCoordinate(pinch.centroid.position, false);
            //     }
            //     onScaleChanged: delta => {
            //         map.zoomLevel += Math.log2(delta);
            //         map.alignCoordinateToPoint(map.startCentroid, pinch.centroid.position);
            //     }
            //     onRotationChanged: delta => {
            //         map.bearing -= delta;
            //         map.alignCoordinateToPoint(map.startCentroid, pinch.centroid.position);
            //     }
            //     grabPermissions: PointerHandler.TakeOverForbidden
            // }
            // WheelHandler {
            //     id: wheel
            //     rotationScale: 1 / 120
            //     property: "zoomLevel"
            // }
            // DragHandler {
            //     id: drag
            //     target: null
            //     onTranslationChanged: delta => map.pan(-delta.x, -delta.y)
            // }
            // Shortcut {
            //     enabled: map.zoomLevel < map.maximumZoomLevel
            //     sequence: StandardKey.ZoomIn
            //     onActivated: map.zoomLevel = Math.round(map.zoomLevel + 1)
            // }
            // Shortcut {
            //     enabled: map.zoomLevel > map.minimumZoomLevel
            //     sequence: StandardKey.ZoomOut
            //     onActivated: map.zoomLevel = Math.round(map.zoomLevel - 1)
            // }
        }
    }
}
