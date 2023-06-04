import QtQuick 6.5
import QtQuick.Controls 6.5
import TableModel 1.0

Window {
    width: 800
    height: 560

    visible: true
    title: "QtMySql_pj01"

    Rectangle {
        id: rectangle

        anchors.fill: parent

        // color: Constants.backgroundColor
        Text {
            id: titleText

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

        // Search Input
        TextField {
            id: searchInput

            anchors {

                bottom: tableDisplay.top
                bottomMargin: 10
                right: tableDisplay.right
            }

            placeholderText: qsTr("Search...")
            font.pixelSize: 12
        }

        // Table View
        Rectangle {
            id: tableDisplay
            width: parent.width / 1.4

            color: "red"
            anchors {
                top: titleText.bottom
                topMargin: 20
                left: parent.left
                leftMargin: 20
                bottom: infoLable.top
            }

            TableView {
                id: tableView
                anchors.fill: parent
                columnSpacing: 1
                rowSpacing: 1
                clip: true

                model: TableModel {
                }

                delegate: Rectangle {
                    id: delegRec
                    implicitWidth: 100
                    implicitHeight: 50

                    Text {
                        text: display
                        anchors.centerIn: parent
                    }
                }
            }
        }

        // Add Update and Delete Buttons
        Rectangle {

            color: "blue"
            anchors {
                left: tableDisplay.right
                leftMargin: 20
                top: tableDisplay.top
                right: parent.rights
                rightMargin: 20
            }
            Column {
                spacing: 20

                Button {
                    id: addBtn

                    text: "Add"
                    onClicked: {
                        console.log("addProduct Clicked!");
                    }
                }
                Button {
                    id: updateBtn

                    text: "Update"

                    onClicked: {
                        console.log("updateProduct Clicked!");
                    }
                }
                Button {
                    id: deleteBtn
                    text: "Delete"
                    onClicked: {
                        console.log("deleteProduct Clicked!");
                    }
                }
            }
        }

        // Lable Info
        Label {
            id: infoLable

            visible: false
            anchors {
                left: parent.left
                leftMargin: 20
                bottom: parent.bottom
                bottomMargin: 20
            }

            text: ""
            font.pixelSize: 22
            font.italic: true
        }
    }
}
