import QtQuick 6.0
import QtQuick.Controls 6.0

Window {
    width: 400
    height: 560

    visible: true
    title: "Button Controller"

    Rectangle {
        id: rectangle

        anchors.fill: parent

        Text {
            id: titleText

            width: 108
            height: 35
            anchors.top: parent.top
            anchors.topMargin: 20

            text: qsTr("Button Controller")
            font.pixelSize: 24
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.styleName: "Bold"
        }

        Rectangle {
            id: recInput

            color: "blue"
            anchors {
                top: titleText.bottom
                topMargin: 20
            }

            Row {
                id: inputLayout
                spacing: 20
                Text {
                    text: qsTr("Name")
                }

                TextField {
                    id: nameInput

                    placeholderText: qsTr("Enter name...")
                    font.pixelSize: 12
                }
            }
        }

        Button {
            id: addBtn

            anchors.top: recInput.bottom
            anchors.topMargin: 20

            text: "Add"
            onClicked: {
                backend.name = nameInput.text;
            }
        }

        Label {
            anchors.top: addBtn.bottom
            anchors.topMargin: 20

            text: backend.name
            font.pixelSize: 22
            font.italic: true
        }
    }
}
