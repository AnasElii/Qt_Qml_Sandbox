import QtQuick
import QtQuick.Controls.Basic
import mainLib 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML and Cpp integration")

    LumberSawController {
        id: sawController
    }

    Column {
        anchors.centerIn: parent
        spacing: 10

        Text {
            text: "Lumber mill control center"
            anchors.horizontalCenter: parent.horizontalCenter

            font.pointSize: 18
        }

        LumberMillBlock {
            anchors.horizontalCenter: parent.horizontalCenter

            name: "Saw 1"
            controller: sawController
        }
    }

    Image {
        width: 100
        height: 24

        anchors {
            right: parent.right
            bottom: parent.bottom
            margins: 10
        }

        source: "qrc:/mainLib/resources/icons/built-with-qt-badge.png"
    }
}
