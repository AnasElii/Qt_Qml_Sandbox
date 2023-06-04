

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Controls
import QtMySql_pj01

Rectangle {
    id: rectangle
    width: 600
    height: 400

    color: Constants.backgroundColor

    Text {
        id: text1

        width: 108
        height: 35
        anchors.top: parent.top
        anchors.topMargin: 20

        text: qsTr("Produit")
        font.pixelSize: 24
        horizontalAlignment: Text.AlignHCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.styleName: "Bold"
    }

    Grid {
        id: grid
        y: 61
        width: 542
        height: 156
        anchors.horizontalCenter: parent.horizontalCenter

        spacing: 20
        columns: 2
        Column {
            id: tColumn
            x: 92
            y: 61
            width: 200
            height: 86
            spacing: 20

            Text {
                text: qsTr("Name")
            }

            Text {
                text: qsTr("Description")
            }

            Text {
                text: qsTr("Quantity")
            }
        }

        Column {
            id: iColumn
            x: 92
            y: 61
            width: 200
            height: 86
            spacing: 20

            TextInput {
                id: nomInput
                width: 80
                height: 20

                PlaceholderText: qsTr("Enter name")
                background: Rectangle {
                    implicitWidth: 200
                    implicitHeight: 40
                    border.color: control.enabled ? "#21be2b" : "transparent"
                }
                font.pixelSize: 12
            }

            Text {
                text: qsTr("Description")
            }

            Text {
                text: qsTr("Quantity")
            }
        }
    }
}
