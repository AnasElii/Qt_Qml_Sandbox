import QtQuick 6.0
import QtQuick.Controls 6.0


Window {
    height: 500; width: 700
    title: qsTr("Hello World!")
    visible: true
    
    Text{
            text: "Latitude: " + currentLatitude + " | Longitude: " + currentLongitude
            font.family: "Helvetica"
            font.pointSize: 24
    }
}
