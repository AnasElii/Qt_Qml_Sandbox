import QtQuick
import QtQuick.Controls.Basic
import mainLib 1.0

Column {
    id: root

    property string name: ""
    required property LumberSawController controller

    spacing: 10

    Text {
        text: root.name
        anchors.horizontalCenter: parent.horizontalCenter

        font.pointSize: 14
    }

    AnimatedImage {
        id: sawImage
        width: 200
        height: 200

        playing: root.controller.isWorking
        source: "qrc:/mainLib/resources/icons/circular-saw.gif"
        speed: root.controller.sawSpeed
    }

    Row {
        spacing: 10

        Button {
            text: "Start"

            onClicked: {
                root.controller.start();
            }
        }

        Button {
            text: "Stop"

            onClicked: {
                root.controller.stop();
            }
        }
    }

    Slider {
        id: slider

        width: 200

        from: 0
        to: 5

        value: root.controller.sawSpeed

        onValueChanged: {
            root.controller.sawSpeed = value;
        }
    }
}
